#ifndef KALEIDOSCOPE_TOPLEVEL_H__
#define KALEIDOSCOPE_TOPLEVEL_H__

#include "llvm/IR/Module.h"

using namespace llvm;

//===----------------------------------------------------------------------===//
// Top-Level parsing and JIT Driver
//===----------------------------------------------------------------------===//

extern std::unique_ptr<Module> TheModule;

void InitializeModuleAndPassManager();

void HandleDefinition();

void HandleExtern();

void HandleTopLevelExpression();

/// top ::= definition | external | expression | ';'
void MainLoop();

#endif