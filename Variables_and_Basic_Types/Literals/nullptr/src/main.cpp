#include "demo.h"

DEMO(Nullptr, Nullptr) { // NOLINT(cert-err58-cpp)
    class A;

    // you can assign nullptr to a pointer of any type
    int *a = nullptr;
    void *b = nullptr;
    A* c = nullptr;

    // the value of nullptr is 0x0
    std::cout << "a: " << a << std::endl
              << "b: " << b << std::endl
              << "c: " << c << std::endl;

}

DEMO(Nullptr, TypeOfNull) { // NOLINT(cert-err58-cpp)

    std::cout << "typeof(NULL) == int? " <<
              std::is_same<typeof(NULL), unsigned>::value << std::endl;

    // 相等. 但不建议将 nullptr 同普通数值 Object 进行 Assignment 或 Compare 操作.
    //std::cout << (nullptr == NULL) << std::endl;

}

void foo(void *) {
    std::cout << "foo(void *) is called" << std::endl;
}

void foo(int) {
    std::cout << "foo(int) is called" << std::endl;
}

DEMO(Nullptr, ambiguous) { // NOLINT(cert-err58-cpp)

    // foo(NULL); // error: call to foo is ambiguous
    foo(nullptr); // ok: call foo(void *)

}