#include <iostream>

extern "C" {
    double trig(double);
}

int main() {
    std::cout << "sin(3.14)^2 + cos(3.14)^2 = " << trig(3.14) << std::endl;
}
