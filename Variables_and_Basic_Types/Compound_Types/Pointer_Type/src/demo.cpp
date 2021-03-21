#include "demo.h"

DEMO(CompoundTypesPointer, Pointer) { // NOLINT(cert-err58-cpp)

    int a = 0;
    int *p_a = &a;

    std::cout << std::hex << p_a << std::endl;

}

void func(int) {}

DEMO(CompoundTypesPointer, Targets) { // NOLINT(cert-err58-cpp)

    std::cout.unsetf(std::ios_base::boolalpha);

    struct A {
        long member_var;
        void member_func(int) {}
    };

    // `p_func` is a function pointer, its value is the address of the function
    void (*p_func)(int) = func;
    std::cout << "pointer to 'void func(int)': " << (void *) p_func << std::endl;

    // `p_member_func` is a member function pointer, its value is a little complex
    void (A::*p_member_func)(int) = &A::member_func;
    std::cout << "pointer to 'void A::member_func(int)': " << p_member_func << std::endl;

    A obj {10};

    // `p_var` is just a normal variable pointer, not a member variable pointer
    auto p_var = &obj.member_var;
    std::cout << "pointer to 'obj.member_var': " << p_var << std::endl;

    // `p_member_var` is a member variable pointer, should be used with `std::bind`
    auto p_member_var = &A::member_var;
    std::cout << "obj.p_member_var: " << std::bind(p_member_var, &obj)() << std::endl;

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
    std::cout << a << std::endl;  // `a` should be changed too

}

DEMO(CompoundTypesPointer, OperatorMemberAccess) { // NOLINT(cert-err58-cpp)

    auto *s = new std::string("hello");

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