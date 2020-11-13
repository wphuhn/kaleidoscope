#ifndef KALEIDOSCOPE_TOPLEVEL_H__
#define KALEIDOSCOPE_TOPLEVEL_H__

#include "KaleidoscopeJIT.h"

using namespace llvm;
using namespace llvm::orc;

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