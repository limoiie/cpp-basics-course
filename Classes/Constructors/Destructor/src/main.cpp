#include "demo.h"

class cls {
public:
    explicit cls(std::string const& name) noexcept
            : name(name)  {
        std::cout << name << " is constructed" << std::endl;
    }

    ~cls() noexcept {
        std::cout << name << " is destructed" << std::endl;
    }

private:
    std::string name;
};

cls a("1. objects with static storage duration"); // NOLINT(cert-err58-cpp)

void foo() {
    auto *d = new cls("4. objects with dynamic storage duration");

    std::cout << "  4. delete-expression" << std::endl;
    delete d; // 4. delete-expression

    cls e("6. objects with automatic storage duration when an exception escapes their block, uncaught");

    std::cout << "  6. stack unwinding" << std::endl;
    throw std::runtime_error("some exception"); // 6. stack unwinding
}

DEMO(Constructors, Destructor) { // NOLINT(cert-err58-cpp)

    {
        cls b("3. objects with automatic storage duration");
        cls&& c = cls("3. temporaries whose life was extended by binding to a reference");

        std::cout << "  3. end of scope" << std::endl;
    } // 3. end of scope

    try {
        foo();
    } catch(std::runtime_error &) {
        // ...
    }

    std::cout << "  1. program terminated" << std::endl;
    // 1. program termination (not by std::terminated)

}

DEMO(Constructors, DeletedDestructor) { // NOLINT(cert-err58-cpp)

    class cls {
    public:
        ~cls() = delete;
    };

    // cls a; // error: attempt to use a deleted function ~cls

    auto *c = new cls(); // ok
    std::cout << std::hex << c << std::endl;

    // delete c; // error: attempt to use a deleted function ~cls

}
