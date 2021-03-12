#include "demo.h"

DEMO_BOUNDARY()
{
    void print(const char *a);
    void print(int a);
    // 仅有 return type 不同的两个 functions 将被视为重复 definition
    // int print(int a); // error: Functions that differ only in their return type cannot be overloaded

    DEMO(Overloading, Function) { // NOLINT(cert-err58-cpp)

        print(0);       // 调用的是 print(int)
        print("hello"); // 调用的是 print(const char *)

    }

    void print(int a) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        std::cout << a << std::endl;
    }

    // 仅有 return type 不同的两个 functions 将被视为
    // int print(int a); // error: Functions that differ only in their return type cannot be overloaded

    void print(const char *a) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        std::cout << a << std::endl;
    }

}
