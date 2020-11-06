#include <iostream>

#define MAX 30

extern "C" {
    double fib(double);
    double fibi(double);
}

int main() {
    std::cout << "Recursive Fibonacci:" << std::endl;
    for (int i = 0; i < MAX; i++) {
        std::cout << "fib(" << i << "): " << fib((double)i) << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Iterative Fibonacci:" << std::endl;
    for (int i = 0; i < MAX; i++) {
        std::cout << "fibi(" << i << "): " << fibi((double)i) << std::endl;
    }
}
