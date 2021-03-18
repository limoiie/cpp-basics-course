#include <iostream>

#include "demo.h"


DEMO(CompoundTypesReferenceLValueReference, Simple) { // NOLINT(cert-err58-cpp)

    auto a = 0;
    auto & ref = a;

    std::cout << "ref: " << ref << std::endl;

    ref = 10; // equivalent to assigning to Variable a

    std::cout << (ref == a) << std::endl; // a also becomes 10
    std::cout << (&ref == &a) << std::endl; // reference has the same address as the variable!

}


void increment_ref(int & a) {
    a += 1;
}

void increment_var(int a) {
    a += 1;
}

DEMO(CompoundTypesReferenceLValueReference, PassByReference) { // NOLINT(cert-err58-cpp)

    auto a = 0;

    std::cout << "a: " << a << std::endl;
    increment_var(a); // 没有 reference, 一般不可以在另一个 Function 里改变 a 的值
    std::cout << "a after increment_var(): " << a << std::endl;

    std::cout << "a: " << a << std::endl;
    increment_ref(a); // 将 parameter 改为 reference, 现在就可以改变 a 的值了
    std::cout << "a after increment_ref(): " << a << std::endl;

}


int & first_of(int arr[2]) {
    return arr[0];
}

DEMO(CompoundTypesReferenceLValueReference, ReturnAsReference) { // NOLINT(cert-err58-cpp)

    int a[2] = {1, 2};

    std::cout << "a[0]: " << a[0] << std::endl;

    // 将 Return Type 声明成 reference, 你就可以赋值给它了
    first_of(a) = 10;

    std::cout << "a[0]: " << a[0] << std::endl;

}


DEMO(CompoundTypesReferenceRValueReference, Simple) { // NOLINT(cert-err58-cpp)

    // rvalue-reference 通常用来延长 Temporary Object (rvalue) 的 Lifetime
    int && ref = 10 + 20; // 10 + 20 的结果是 Temporary Object, ref 延长了其 Lifetime

    std::cout << "ref: " << ref << std::endl;

    // 注: rvalue-reference 在 Use 时被视为 lvalue
    ref = 10;  // 作为 lvalue, 可以 assignment

    std::cout << "ref: " << ref << std::endl;

    // lvalue-reference to const 也可延长 Temporary Object (rvalue) 的 Lifetime
    int const & c_lvalue_ref = 10 + 20;
    // 但其为 const, 不可修改
    // c_lvalue_ref = 10; // error: cannot assign to const value

}


void foo(int & v) {
    std::cout << "foo(int &) is called" << std::endl;
}

void foo(int && v) {
    std::cout << "foo(int &&) is called" << std::endl;
}

DEMO(CompoundTypesReferenceRValueReference, PassByReference) { // NOLINT(cert-err58-cpp)

    int && ref = 10 + 20; // 10 + 20 的结果是 Temporary Object, ref 延长了其 Lifetime

    foo(ref);            // 作为 lvalue, 调用的是 foo(int &);
    foo(std::move(ref)); // 强制转换成 rvalue, 调用的是 foo(int &&);

}