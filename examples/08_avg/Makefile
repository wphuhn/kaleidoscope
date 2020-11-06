.PHONY: default clean all

default: all

all:
	toy < ./avg.ks
	clang++ main.cpp output.o -o main

clean:
	rm -f *.o main
