#include <iostream>


class A // scope of class 'A' begins
{
public:
    void foo() const;
    // 在 class scope declared 的 name, 在 member function scopes 中全部可见
    void goo( // scope of function 'goo' start
            int b = x
    ) const; // scope of function 'goo' interrupted

    int a;
    // 在 class scope declared 的 name, 在 member function scopes 以外的 scope 按照 declaration 顺序可见
    // int b = x; // error: x is not declared
    static int const x = 10;
}; // scope of class 'A' ends

void A::foo() const { // scope of function 'foo' resumes
    std::cout << "foo: " << a << std::endl;
} // scope of function 'foo' ends

void A::goo( // scope of function 'goo' resumes
        int b
) const {
    std::cout << "goo: " << a + b << std::endl;
} // scope of function 'goo' ends

int main() {
    A a = A();
    a.goo();
    a.foo();
    return 0;
}