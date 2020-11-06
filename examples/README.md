This folder contains examples of the Kaleidoscope language, taken from the LLVM
Kaleidoscope tutorial.  To run each example:
* `make && ./main`
Note that you will need to have the Kaleidoscope compiler `toy` in your system
path.

In all cases, we use a small C++ wrapper main() function which calls
Kaleidoscope subroutines using C linkage.

A "Kaledoscope standard library" `ks_stdlib.h` is also provided here.  This is a
header-only library of C subroutines which are intended to be specified in
Kaleidoscope via external linkage, e.g. the `extern` keyword, and then compiled
and linked as part of the C++ wrapper executable.  Originally in the tutorial,
these subroutines were in the symbol table of part of the JIT interpreter,
but as we are using the compiler here, we need to provide them at link time.
