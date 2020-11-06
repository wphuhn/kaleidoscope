#include <iostream>

#include "../ks_stdlib.h"

extern "C" {
    double printstar(double);
}

int main() {
    std::cout << printstar(100) << std::endl;
}
