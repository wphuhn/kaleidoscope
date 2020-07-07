all:
	clang++-10 -g -O3 -c toy.cpp -o toy.o `llvm-config-10 --cxxflags`
	clang++-10 -g -O3  toy.o -o toy `llvm-config-10 --ldflags --libs`

clean:
	rm -f toy.o toy
