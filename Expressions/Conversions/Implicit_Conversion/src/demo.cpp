#include "demo.h"

DEMO_BLOCK()
{
    void foo(int num) {
        std::cout << num << std::endl;
    }

    DEMO(ImplicitConversion, WhenAsArguemnt) { // NOLINT(cert-err58-cpp)
        // following conversion is ok, but with warning - narrowing conversion
        foo(10.3); // implicit conversion from double to int: 10.3 to 10
    }

}

DEMO_BLOCK()
{
    DEMO(ImplicitConversion, WhenAsOperand) { // NOLINT(cert-err58-cpp)
        auto a = 10 + 2.2; // implicit conversion from int to double: 10 to 10.0
        std::cout << "a: " << a << std::endl;
    }

}

DEMO(ImplicitConversion, WhenInitializeWithOtherType) { // NOLINT(cert-err58-cpp)

    double d = 10; // implicit conversion from int to double: 10 to 10.0
    // following conversion is ok, but with warning - narrowing conversion
    int i = 10.1;  // implicit conversion from double to int: 10.1 to 10

    std::cout << "d: " << d << std::endl;
    std::cout << "i: " << i << std::endl;

}

DEMO(ImplicitConversion, WhenInSwitchCondition) { // NOLINT(cert-err58-cpp)

    double d = 10.2;
    if (d) { // implicit conversion from double to bool: 10.2 to true
        std::cout << "any non-zero value will be converted to true" << std::endl;
    }

}