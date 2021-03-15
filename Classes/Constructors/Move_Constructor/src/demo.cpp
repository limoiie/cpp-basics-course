#include "demo.h"

DEMO(Constructors, ImplicitlyDeclaredMove) { // NOLINT(cert-err58-cpp)

    class cls {
    public:
        std::vector<int> i;
    };

    cls c = cls();
    cls a = std::move(c); // call the default move constructor created by the compiler
    std::cout << a.i.size() << std::endl;

}

DEMO(Constructors, ImplicitlyDefinedMove) { // NOLINT(cert-err58-cpp)

    class cls {
    public:
        std::vector<int> i;

        cls() = default;

        cls(cls const &&c) noexcept
                : i(c.i) {
            std::cout << "call move constructor" << std::endl;
        }

        cls(cls && c) = default; // implicitly-defined default copy constructor

    };

    cls c {};
    cls a = std::move(c); // call copy constructor cls(cls &&)

    std::cout << "==" << std::endl;

    const cls b {};
    cls d = std::move(b); // call the implicitly-defined default move constructor

}

class cls {
public:
    cls() = default;

    DEMO_MEMBER_ANCHOR(move_constructor)
    cls(cls &&c) noexcept
            : i(c.i + 1) {
        std::cout << "copy constructor is called" << std::endl;
    }

    cls& operator=(cls && c) noexcept {
        std::cout << "copy assign operator is called" << std::endl;
        i = c.i + 1;
        return *this;
    }

    int i;
};

DEMO(Constructors, MoveConstructorAssignOperator) { // NOLINT(cert-err58-cpp)

    cls a {};

    cls c = std::move(a); // call the move constructor
    c.i = 0;

    c = std::move(c); // call the move assign operator

}