#include "demo.h"

DEMO(FloatingPointLiterals, FloatDouble) { // NOLINT(cert-err58-cpp)

    std::cout << 10.123 << std::endl;
    std::cout << 0.123f << std::endl;
    std::cout << 2. << std::endl;
    std::cout << .1 << std::endl;

}

DEMO(FloatingPointLiterals, Scientist) { // NOLINT(cert-err58-cpp)

    std::cout << 10e2F << ", " << 10e-5 << std::endl;
    std::cout << 10.e10F << ", " << 10. << ", " << 10.F << std::endl;
    std::cout << 10.10e5L << ", " << .10 << ", " << .10L << std::endl;

}