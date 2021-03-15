#include "demo.h"

DEMO(Constructors, ImplicitlyDeclared) { // NOLINT(cert-err58-cpp)

    class cls {
    public:
        int i;
    };

    cls c{};  // call the default constructor created by the compiler
    std::cout << c.i << std::endl;

}

DEMO(Constructors, ImplicitlyDefined) { // NOLINT(cert-err58-cpp)

    class cls {
    public:
        int i;

        explicit
        cls(int i) : i(i) {} // user-defined constructor

        cls() = default; // implicitly-defined default constructor

    };

    cls c = cls(); // call the implicitly-defined default constructor
    std::cout << c.i << std::endl;

}
