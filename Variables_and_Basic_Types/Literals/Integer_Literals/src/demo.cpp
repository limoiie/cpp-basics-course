#include "demo.h"

DEMO(IntegerLiterals, Literals) { // NOLINT(cert-err58-cpp)

    std::cout << std::hex
              << 0x123 << std::endl
              << -0xafd << std::endl;

    std::cout << std::oct
              << 0123 << std::endl;

    std::cout << std::dec
              << 123 << std::endl;

}

DEMO(IntegerLiterals, TypeSuffix) { // NOLINT(cert-err58-cpp)

    // int
    std::cout << "typeof(10) == int?              " <<
              std::is_same<typeof(10), int>::value << std::endl;

    // unsigned
    std::cout << "typeof(10u) == unsigned int?    " <<
              std::is_same<typeof(10u), unsigned int>::value << std::endl;

    // long
    std::cout << "typeof(10l) == long int?        " <<
              std::is_same<typeof(10l), long int>::value << std::endl;

    // long long
    std::cout << "typeof(10ll) == long long int?  " <<
              std::is_same<typeof(10ll), long long int>::value << std::endl;

    // specify the signedness and the size at the same time
    std::cout << "typeof(10ul) == unsigned long?  " <<
              std::is_same<typeof(10ul), unsigned long>::value << std::endl;

    // the order of signedness and size doesn't matter
    std::cout << "typeof(10lu) == unsigned long?  " <<
              std::is_same<typeof(10lu), unsigned long>::value << std::endl;

}