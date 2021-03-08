#include "demo.h" // for using Macro DEMO
#include "randoms.h" // for using Function rand_int

DEMO(FlowOfControlsIf, If) { // NOLINT(cert-err58-cpp)

    int a = rand_int(10);
    std::cout << "Get a: " << a << std::endl;
    if (a > 4) {
        std::cout << a << " is greater than 4!" << std::endl;
    }

}

DEMO(FlowOfControlsIf, IfElse) { // NOLINT(cert-err58-cpp)

    int a = rand_int(10);
    std::cout << "Get a: " << a << std::endl;
    if (a > 4) {
        std::cout << a << " is greater than 4!" << std::endl;
    } else {
        std::cout << a << " is less than or equals to 4!" << std::endl;
    }

}

DEMO(FlowOfControlsIf, ElseIf) { // NOLINT(cert-err58-cpp)

    int a = rand_int(10);
    std::cout << "Get a: " << a << std::endl;
    if (a > 4) {
        std::cout << a << " is greater than 4!" << std::endl;
    } else if (a < 4) {
        std::cout << a << " is less than 4!" << std::endl;
    } else {
        std::cout << a << " equals to 4!" << std::endl;
    }

}

DEMO(FlowOfControlsIf, IfDef) { // NOLINT(cert-err58-cpp)

    if (int a = rand_int(2)) {
        std::cout << "enter if-branch because a == " << a << std::endl;
    } else {
        std::cout << "enter else-branch" << std::endl;
    }

}