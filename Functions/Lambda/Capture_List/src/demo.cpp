#include "demo.h"

DEMO(CaptureList, CaptureDefaultByReference) { // NOLINT(cert-err58-cpp)

    int a = 0;
    int b = 0;

    auto fn = [&] { // capture-default: capture all by-reference
        ++a; // captured by reference
        ++b; // captured by reference
    };

    fn();

    // 因为是 capture by-reference, 这里 a 和 b 应该都被修改了
    std::cout << "a: " << a << std::endl; // should be 1
    std::cout << "b: " << b << std::endl; // should be 1

}

DEMO(CaptureList, CaptureDefaultByCopy) { // NOLINT(cert-err58-cpp)

    int a = 0;
    int b = 0;

    auto fn = [=] { // capture-default: capture all by-copy
        // ++a; // error: 不可修改 captured by-copy
        // ++b; // error: 不可修改 captured by-copy
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
    };

    fn();

}

DEMO(CaptureList, CaptureByCopy) { // NOLINT(cert-err58-cpp)

    int a = 0;
    int b = 0;

    auto fn = [a] { // capture only 'a' by-copy
        // ++a; // error: 不可修改 captured by-copy
        std::cout << "a: " << a << std::endl;
        // std::cout << "b: " << b << std::endl; // 'b' is not captured
    };

    fn();

    // 因为是 capture by-reference, 这里 a 和 b 应该都被 lambda 修改了
    std::cout << "a: " << a << std::endl; // should be 1
    std::cout << "b: " << b << std::endl; // should be 1

}

DEMO(CaptureList, CaptureByCopyPackExpansion) { // NOLINT(cert-err58-cpp)

}

DEMO(CaptureList, CaptureByReference) { // NOLINT(cert-err58-cpp)

    int a = 0;
    int b = 0;

    auto fn = [&a] { // capture only 'a' by-reference
        ++a;
        std::cout << "a: " << a << std::endl;
        // std::cout << "b: " << b << std::endl; // 'b' is not captured
    };

    fn();

    // 因为是 capture by-reference, 这里 a 应该被修改了
    std::cout << "a: " << a << std::endl; // should be 1
    std::cout << "b: " << b << std::endl; // should be 0

}

DEMO(CaptureList, CaptureByReferencePackExpansion) { // NOLINT(cert-err58-cpp)

}

DEMO(CaptureList, CaptureThis) { // NOLINT(cert-err58-cpp)

    // 只有在 class 内部才有 pointer this, 才会出现 capture this 的情况

    struct A {
        int a;
        int b;

        void reset() {
            a = b = 0;
        }

        void foo() {
            auto fn = [this]() { // capture all the members of the current object this
                reset(); // the function member

                a = 10; // the data member
                b = 20; // the data member
            };
            fn();
        }

    };

    A obj = {};
    obj.foo();

    // 因为是 capture by-reference, 这里的 obj.a 和 obj.b 应该被 lambda 修改了
    std::cout << "obj.a: " << obj.a << std::endl;
    std::cout << "obj.b: " << obj.b << std::endl;

}
