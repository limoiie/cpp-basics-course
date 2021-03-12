#include "demo.h"

struct A {
    char c;

    explicit A(char c) : c(c) {
        std::cout << "A(" << c << ")" << std::endl;
    }

    ~A() {
        std::cout << "~A(" << c << ")" << std::endl;
    }

};

void foo( // scope of function foo begins
        A a = A('a'), // name-scope of 'a' begins
        A b = A('b') // name-scope of 'b' begins
) {
    // scope of block begins

    std::cout << a.c << std::endl;
    std::cout << b.c << std::endl;

    // name-scope of 'c' begins
    A c = A('c');

    std::cout << c.c << std::endl;

    // name-scope of 'c' ends
    // scope of block  ends
} // scope of function foo ends
//   name-scope of 'b' ends
//   name-scope of 'a' ends

DEMO(Scopes, FunctionScope) { // NOLINT(cert-err58-cpp)

    // 运行, 并观察输出结果. 留意 a, b, c 的 construction 顺序和 deconstruction 顺序
    foo();

}