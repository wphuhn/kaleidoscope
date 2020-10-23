# Kaleidoscope

Working through LLVM tutorial

# Dependencies

* LLVM 10.0.1
* Clang 10.0.1
* CMake 3.16

# Note

* You'll need to grab the KaleidoscopeJIT header file from the LLVM's source
  repo (located in
  llvm-project/llvm/examples/Kaleidoscope/include/KaleidoscopeJIT.h) and put it
  in an `include` folder.  It's Apache 2.0 licensed, and it's too early to
  worry about the lawyers.

# Installation

* `mkdir build && cd build`
* `cmake .. && make`

# To-Do

* Break into different files
* Add visitor pattern
