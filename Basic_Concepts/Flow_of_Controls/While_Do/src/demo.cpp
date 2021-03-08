#include "demo.h" // for using Macro DEMO

DEMO(FlowOfControlsWhile, While) { // NOLINT(cert-err58-cpp)

    auto i = 0;
    while (i < 10) {
        std::cout << i << ", ";
        ++i;
    }

}

DEMO(FlowOfControlsWhile, DoWhile) { // NOLINT(cert-err58-cpp)

    auto i = 0;
    do {
        std::cout << i << ", ";
        ++i;
    } while (i < 10);

}

DEMO(FlowOfControlsWhileCompare, EqualCase) { // NOLINT(cert-err58-cpp)

    std::cout << "while    : ";
    auto i = 0;
    while (i < 10) {
        std::cout << i << ", ";
        ++i;
    }
    std::cout << std::endl;

    std::cout << "do while : ";
    i = 0;
    do {
        std::cout << i << ", ";
        ++i;
    } while (i < 10);

}

DEMO(FlowOfControlsWhileCompare, DifferentCase) { // NOLINT(cert-err58-cpp)

    std::cout << "while    : ";
    auto i = 3;
    while (i < 2) {
        std::cout << i << ", ";
        ++i;
    }
    std::cout << std::endl;

    std::cout << "do while : ";
    i = 3;
    do {
        std::cout << i << ", ";
        ++i;
    } while (i < 2);

}