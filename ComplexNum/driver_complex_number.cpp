#include <iostream>
#include "ComplexNumber.hpp"

int main() {
    ComplexNumber n1(1, 1);
    ComplexNumber n2(n1);
    n2 = n2*n1;
    n1.Im = 0;
    n2.R = 312;
    n2 /= 5;
    n2 = n2;
    std::cout << n2 << std::endl;
    std::cout << powC(n2, 2) << std::endl;
    return 0;
}