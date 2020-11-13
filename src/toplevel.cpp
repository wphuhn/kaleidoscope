#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "llvm/Transforms/Utils.h"
#include <cstdio>
#include <memory>
#include <vector>
#include "KaleidoscopeJIT.h"

using namespace llvm;
using namespace llvm::orc;

#include "ast.hpp"
#include "debug.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "toplevel.hpp"

std::unique_ptr<Module> TheModule;

//===----------------------------------------------------------------------===//
// Top-Level parsing and JIT Driver
//===----------------------------------------------------------------------===//

void InitializeModuleAndPassManager() {
  // Open a new module.
  TheModule = std::make_unique<Module>("my cool jit", TheContext);

  // Create a new pass manager attached to it.
  TheFPM = std::make_unique<legacy::FunctionPassManager>(TheModule.get());

#ifndef NO_OPTS
  // Promote allocas to registers.
  TheFPM->add(createPromoteMemoryToRegisterPass());
  // Do simple "peephole" optimizations and bit-twiddling optzns.
  TheFPM->add(createInstructionCombiningPass());
  // Reassociate expressions.
  TheFPM->add(createReassociatePass());
  // Eliminate Common SubExpressions.
  TheFPM->add(createGVNPass());
  // Simplify the control flow graph (deleting unreachable blocks, etc).
  TheFPM->add(createCFGSimplificationPass());
#endif

  TheFPM->doInitialization();
}

void HandleDefinition() {
  if (auto FnAST = ParseDefinition()) {
    if (!FnAST->codegen())
      fprintf(stderr, "Error reading function definition:");
  } else {
    // Skip token for error recovery.
    getNextToken();
  }
}

void HandleExtern() {
  if (auto ProtoAST = ParseExtern()) {
    if (!ProtoAST->codegen())
      fprintf(stderr, "Error reading extern");
    else
      FunctionProtos[ProtoAST->getName()] = std::move(ProtoAST);
  } else {
    // Skip token for error recovery.
    getNextToken();
  }
}

void HandleTopLevelExpression() {
  // Evaluate a top-level expression into an anonymous function.
  if (auto FnAST = ParseTopLevelExpr()) {
    if (!FnAST->codegen()) {
      fprintf(stderr, "Error generating code for top level expr");
    }
  } else {
    // Skip token for error recovery.
    getNextToken();
  }
}

/// top ::= definition | external | expression | ';'
void MainLoop() {
  while (true) {
    switch (CurTok) {
    case tok_eof:
      return;
    case ';': // ignore top-level semicolons.
      getNextToken();
      break;
    case tok_def:
      HandleDefinition();
      break;
    case tok_extern:
      HandleExtern();
      break;
    default:
      HandleTopLevelExpression();
      break;
    }
  }
}
