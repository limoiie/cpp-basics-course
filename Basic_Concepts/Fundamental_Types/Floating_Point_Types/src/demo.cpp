#include "demo.h"

DEMO(FundamentalTypesFloatingPoint, Size) { // NOLINT(cert-err58-cpp)

    std::cout << "sizeof(float): " << sizeof(float) << std::endl;
    std::cout << "sizeof(double): " << sizeof(double) << std::endl;
    std::cout << "sizeof(long double): " << sizeof(long double) << std::endl;

}

DEMO(FundamentalTypesFloatingPoint, Value) { // NOLINT(cert-err58-cpp)

    std::cout << "INFINITY is " << INFINITY << std::endl;
    std::cout << "NAN is " << NAN << std::endl;

}

DEMO(FundamentalTypesFloatingPoint, DivideZero) { // NOLINT(cert-err58-cpp)

    std::cout.setf(std::ios_base::boolalpha); // let cout output "true" or "false" for boolean value

    std::cout << "0.0 / 0.0 is " << (0.0 / 0.0) << std::endl;
    std::cout << "0.0 / -0.0 is " << (0.0 / -0.0) << std::endl;
    std::cout << "1.0 / 0.0 is " << (1.0 / 0.0) << std::endl;
    std::cout << "1.0 / -0.0 is " << (1.0 / -0.0) << std::endl;

    std::cout << "INFINITY == INFINITY? " << (INFINITY == INFINITY) << std::endl;
    std::cout << "NAN == NAN? " << (NAN == NAN) << std::endl;

}