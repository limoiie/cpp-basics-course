#include "demo.h"

DEMO(Reference, LValueReference) { // NOLINT(cert-err58-cpp)

    auto a = 0;
    auto & ref = a;

    std::cout << "ref of a: " << ref << std::endl;

    ref = 10; // equivalent to assigning to Variable a

    std::cout << "ref == a?   " << (ref == a) << std::endl; // 'a' becomes 10, too
    std::cout << "&ref == &a? " << (&ref == &a) << std::endl; // reference and the target has the same address

}


void increment_ref(int & a) {
    a += 1;
}

void increment_var(int a) {
    a += 1;
}

DEMO(Reference, PassByLValueReference) { // NOLINT(cert-err58-cpp)

    auto a = 0;

    std::cout << "a: " << a << std::endl;
    increment_var(a); // you cannot change `a` inner the function without pass-by-reference
    std::cout << "a after increment_var(): " << a << std::endl;

    std::cout << "a: " << a << std::endl;
    increment_ref(a); // with pass-by-reference, `a` could be changed
    std::cout << "a after increment_ref(): " << a << std::endl;

}


int & first_of(int arr[2]) {
    return arr[0];
}

DEMO(Reference, ReturnAsLValueReference) { // NOLINT(cert-err58-cpp)

    int a[2] = {1, 2};

    std::cout << "a[0]: " << a[0] << std::endl; // output 1

    // if a function return a lvalue-reference, you can assign to it directly
    first_of(a) = 10;

    std::cout << "a[0]: " << a[0] << std::endl; // output 10

}


DEMO(Reference, RValueReference) { // NOLINT(cert-err58-cpp)

    // rvalue-reference 通常用来延长 temporary object (rvalue) 的 Lifetime
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


void foo(std::vector<int> & v) {
    std::cout << "foo(vector<int> &) is called" << std::endl;
}

void foo(std::vector<int> && v) {
    std::cout << "foo(vector<int> &&) is called" << std::endl;
}

DEMO(Reference, PassByRValueReference) { // NOLINT(cert-err58-cpp)

    auto && ref = std::vector<int> { 1, 2, 3 }; // 10 + 20 的结果是 Temporary Object, ref 延长了其 Lifetime

    foo(ref);            // `foo(int &)` is called
    foo(std::move(ref)); // `foo(int &&)` is called

}