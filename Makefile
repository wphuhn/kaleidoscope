CXXFLAGS=-g -O0

all:
	clang++-10 $(CXXFLAGS) -c toy.cpp -o toy.o `llvm-config-10 --cxxflags`
	clang++-10 $(CXXFLAGS)  toy.o -o toy `llvm-config-10 --ldflags --libs`

clean:
	rm -f toy.o toy
