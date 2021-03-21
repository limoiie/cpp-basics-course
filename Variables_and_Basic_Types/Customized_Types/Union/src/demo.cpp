#include "demo.h"

DEMO(CustomizedTypesUnion, MembersWithSameAddress) { // NOLINT(cert-err58-cpp)

    union A {
        std::int32_t i;
        char c;
        std::int64_t l;
    };

    A a = A();

    // each member of an union has the same address
    std::cout << "address of a.i: " << &(a.i) << std::endl;
    std::cout << "address of a.c: " << &(a.c) << std::endl;
    std::cout << "address of a.l: " << &(a.l) << std::endl;

    a.i = 0x41; // 0x41 is the Ascii code of character 'A'
    std::cout << a.c << std::endl; // set a.i but a.c is also changed at same time

}

DEMO(CustomizedTypesUnion, UnionSizeIsMaxMemberSize) { // NOLINT(cert-err58-cpp)

    union A {
        std::int32_t i;  // occupies 4 bytes
        char c;          // occupies 1 bytes
        std::int64_t l;  // occupies 8 bytes
    }; // the whole union occupies 8 bytes

    std::cout << "size of union A: " << sizeof(A) << std::endl;

}

DEMO(CustomizedTypesUnion, Anonymous) { // NOLINT(cert-err58-cpp)

    // anonymous union
    union {
        int a = 0;
        char b[2];
    }; // the whole union occupies 8 bytes

    // all the members of a anonymous union will be injected into the enclosing scope
    a = 0x41; // 0x41 is the ASCII code for character 'A'
    b[1] = 'b';

    std::cout << b << std::endl;

}