#include "demo.h"

DEMO(Constructors, ImplicitlyDeclaredCopy) { // NOLINT(cert-err58-cpp)

    class cls {
    public:
        int i;
    };

    cls c = cls();
    cls a = c; // call the default copy constructor created by the compiler
    std::cout << c.i << std::endl;
    std::cout << a.i << std::endl;

}

DEMO(Constructors, ImplicitlyDefinedCopy) { // NOLINT(cert-err58-cpp)

    class cls {
    public:
        int i;

        cls() = default;

        cls(cls &c)
                : i(c.i + 3) {
            std::cout << "call copy constructor" << std::endl;
        }

        cls(cls const& c) = default; // implicitly-defined default copy constructor

    };

    cls c {};
    cls a = c; // call copy constructor cls(cls &)

    std::cout << "==" << std::endl;

    const cls b {};
    cls d = b; // call the implicitly-defined default copy constructor

}

class cls {
public:
    cls() = default;

    DEMO_MEMBER_ANCHOR(copy_constructor)
    cls(cls const&c)
            : i(c.i + 1) {
        std::cout << "copy constructor is called" << std::endl;
    }

    cls& operator=(cls const& c) {
        std::cout << "copy assign operator is called" << std::endl;
        i = c.i + 1;
        return *this;
    }

    int i;
};

DEMO(Constructors, CopyConstructorAssignOperator) { // NOLINT(cert-err58-cpp)

    cls a {};

    cls c = a; // call the copy constructor
    c.i = 0;

    c = a; // call the copy assign operator

}