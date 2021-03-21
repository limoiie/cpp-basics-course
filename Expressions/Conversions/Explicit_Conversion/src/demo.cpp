#include "demo.h"

DEMO(ExplicitConversion, CStyleCast) { // NOLINT(cert-err58-cpp)

    auto x = (int) 10.2;
    std::cout << "(int) 10.2 == " << x << std::endl;

}

DEMO(ExplicitConversion, FunctionalCast) { // NOLINT(cert-err58-cpp)

    auto x = int (10.2);
    std::cout << "int (10.2) == " << x << std::endl;

}

DEMO(ExplicitConversion, CppStyleCast) { // NOLINT(cert-err58-cpp)

    auto x = static_cast<int>(10.2);
    std::cout << "static_cast<int>(10.2) == " << x << std::endl;

}