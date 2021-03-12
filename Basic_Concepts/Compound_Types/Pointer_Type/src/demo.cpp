#include "demo.h"

DEMO(CompoundTypesPointer, Pointer) { // NOLINT(cert-err58-cpp)

    int a = 0;
    int *p_a = &a;

    std::cout << std::hex << p_a << std::endl;

}

DEMO(CompoundTypesPointer, OperatorAddressOf) { // NOLINT(cert-err58-cpp)

    int a = 10;
    int *p_a = &a;

    std::cout << std::hex << "a is stored at " << p_a << std::endl;

}

DEMO(CompoundTypesPointer, OperatorDereference) { // NOLINT(cert-err58-cpp)

    int a = 10;
    int *p_a = &a;

    std::cout << *p_a << std::endl; // dereference for reading

    *p_a = 20; // dereference for modifying

    std::cout << *p_a << std::endl;
    std::cout << a << std::endl;  // a should be changed too

}

DEMO(CompoundTypesPointer, OperatorMemberAccess) { // NOLINT(cert-err58-cpp)

    std::string *s = new std::string("hello");

    std::cout << s->size() << std::endl; // access the member function through operator->

    delete s;

}

DEMO(CompoundTypesPointer, OperatorSubscript) { // NOLINT(cert-err58-cpp)

    int a[] = {1, 2, 3};
    int *p_a = a;

    for (auto i = 0; i < 3; ++i) {
        std::cout << p_a[i] << " == " << a[i] << std::endl;
    }

}