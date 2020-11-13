#ifndef KALEIDOSCOPE_DEBUG_H__
#define KALEIDOSCOPE_DEBUG_H__

#include "llvm/IR/DIBuilder.h"
#include "KaleidoscopeJIT.h"

#include "ast.hpp"

using namespace llvm;
using namespace llvm::orc;

//===----------------------------------------------------------------------===//
// Debug Info Support
//===----------------------------------------------------------------------===//

extern std::unique_ptr<DIBuilder> DBuilder;

DISubroutineType *CreateFunctionType(unsigned NumArgs, DIFile *Unit);

struct DebugInfo {
  DICompileUnit *TheCU;
  DIType *DblTy;
  std::vector<DIScope *> LexicalBlocks;

  void emitLocation(ExprAST *AST);
  DIType *getDoubleTy();
};

extern DebugInfo KSDbgInfo;

#endif