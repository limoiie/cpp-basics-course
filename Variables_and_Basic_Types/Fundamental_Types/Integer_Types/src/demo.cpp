#include "demo.h"

DEMO(IntegerType, DefaultSigned) { // NOLINT(cert-err58-cpp)

    // signed is the default signedness of integer type
    std::cout << "signed int == int? "
              << std::is_same<signed int, int>::value << std::endl;

}

DEMO(IntegerType, DefaultInt) { // NOLINT(cert-err58-cpp)

    // int can be omitted if there is a modifier in the type

    std::cout << "signed int == signed? "
              << std::is_same<signed int, signed>::value << std::endl;

    std::cout << "long int == long? "
              << std::is_same<long int, long>::value << std::endl;

    std::cout << "long long int == long long? "
              << std::is_same<long long int, long long>::value << std::endl;

}

DEMO(IntegerType, IntegerTypeSize) { // NOLINT(cert-err58-cpp)

    std::cout << "sizeof short int:      " << sizeof(short int) << " bytes" << std::endl;
    std::cout << "sizeof int:            " << sizeof(int) << " bytes" << std::endl;
    std::cout << "sizeof long int:       " << sizeof(long int) << " bytes" << std::endl;
    std::cout << "sizeof long long int:  " << sizeof(long long int) << " bytes" << std::endl;

    std::cout << "sizeof void *:         " << sizeof(void *) << " bytes" << std::endl;

}