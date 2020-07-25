CLANG=clang++
LLVM_CONFIG=llvm-config
CXXFLAGS=-g -O0

all:
	$(CLANG) $(CXXFLAGS) -c toy.cpp -o toy.o `$(LLVM_CONFIG) --cxxflags`
	$(CLANG) $(CXXFLAGS)  toy.o -o toy `$(LLVM_CONFIG) --ldflags --libs`

clean:
	rm -f toy.o toy
