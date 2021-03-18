#include "demo.h"

DEMO(FloatingPointTypes, Size) { // NOLINT(cert-err58-cpp)

    std::cout << "sizeof(float): " << sizeof(float) << std::endl;
    std::cout << "sizeof(double): " << sizeof(double) << std::endl;
    std::cout << "sizeof(long double): " << sizeof(long double) << std::endl;

}

DEMO(FloatingPointTypes, DivideZero) { // NOLINT(cert-err58-cpp)


    std::cout << "1.0 / 0.0 is " << (1.0 / 0.0) << std::endl;
    std::cout << "-1.0 / 0.0 is " << (-1.0 / 0.0) << std::endl;
    std::cout << "1.0 / -0.0 is " << (1.0 / -0.0) << std::endl;
    std::cout << "-1.0 / -0.0 is " << (-1.0 / -0.0) << std::endl;

}

DEMO(FloatingPointTypes, NegZeroEqualZero) { // NOLINT(cert-err58-cpp)

    std::cout << "0.0 / 0.0 is " << (0.0 / 0.0) << std::endl;
    std::cout << "-0.0 / 0.0 is " << (-0.0 / 0.0) << std::endl;
    std::cout << "0.0 / -0.0 is " << (0.0 / -0.0) << std::endl;
    std::cout << "-0.0 / -0.0 is " << (-0.0 / -0.0) << std::endl;

    std::cout << "-0.0 == 0.0? " << (-0.0 == 0.0) << std::endl;
    std::cout << "1.0 / -0.0 is " << (1.0 / -0.0) << std::endl;

}

DEMO(FloatingPointTypes, NanNotEqualNan) { // NOLINT(cert-err58-cpp)

    std::cout << "INFINITY == INFINITY? " << (INFINITY == INFINITY) << std::endl;
    std::cout << "     NAN == NAN?      " << (NAN == NAN) << std::endl;

}