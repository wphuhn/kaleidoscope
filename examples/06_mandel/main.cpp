#include <iostream>

#include "../ks_stdlib.h"

extern "C" {
    double mandel(double, double, double, double);
}

int main() {
    std::cout << std::endl;
    std::cout << "mandel(-2.3, -1.3, 0.05, 0.07):" << std::endl;
    std::cout << std::endl;
    mandel(-2.3, -1.3, 0.05, 0.07);

    std::cout << std::endl;
    std::cout << "mandel(-2, -1, 0.02, 0.04):" << std::endl;
    std::cout << std::endl;
    mandel(-2, -1, 0.02, 0.04);
 
    std::cout << std::endl;
    std::cout << "mandel(-0.9, -1.4, 0.02, 0.03):" << std::endl;
    std::cout << std::endl;
    mandel(-0.9, -1.4, 0.02, 0.03);
}
