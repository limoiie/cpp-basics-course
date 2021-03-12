#include "demo.h"

namespace
{
    void foo(int a, int b, int c = 10) {
        std::cout << "a, b, c: " << a << ", " << b << ", " << c << std::endl;
    }

    DEMO(DefaultArguments, Simple) { // NOLINT(cert-err58-cpp)

        foo(1, 2, 3);

        foo(1, 2); // 可以移除 c 以使用 c 的 default value -- 10

    }
}

namespace
{
    void foo(int a, char b = 'b', std::string c = "x") {
        std::cout << "a, b, c: " << a << ", " << b << ", " << c << std::endl;
    }

    DEMO(DefaultArguments, RightMost) { // NOLINT(cert-err58-cpp)

        // foo(1, "c"); // error: no matched function

        foo(1); // 可以移除 c 以使用 c 的 default value -- 10

    }

}

namespace
{

    void goo(int a, int b, int c = 10) {
        std::cout << "goo a, b, c: " << a << ", " << b << ", " << c << std::endl;
    }


    DEMO(DefaultArguments, MultiDeclarations) { // NOLINT(cert-err58-cpp)

        goo(1, 2);  // 1, 2, 10

        void goo(int a, int b, int c = 20); // 可以 redefine 'c', 因为 与 original goo 不在一个 scope:
                                            // original goo 在 global scope; 而当前 goo 在 block scope

        goo(1, 2); // 1, 2, 20
    }


    DEMO(DefaultArguments, MultiDeclarationsSameScope) { // NOLINT(cert-err58-cpp)

        void goo(int a, int b, int c = 20);

        goo(1, 2); // 1, 2, 20

        // 不可以 redefine 'c' (即使 default value 没变), 因为当前 scope 里上一个 declaration 已经 define 了
        // void goo(int a, int b = 10, int c = 20); // error: redefine of default argument 'c'

        void goo(int a, int b = 10, int c); // c = 20

        goo(1); // 1, 10, 20

    }
}
