#include "demo.h"


class base {
public:
    DEMO_MEMBER_ANCHOR(virtual_in_base_class)
    virtual void virtual_func() { // add the specifier virtual
        std::cout << "virtual_func() of base" << std::endl;
    }

    virtual void pure_virtual_func() = 0;

};

class derived : public base {
public:
    DEMO_MEMBER_ANCHOR(override_in_derived_class)
    void virtual_func() override {
        std::cout << "virtual_func() of derived" << std::endl;
    }

    void pure_virtual_func() override {
        std::cout << "pure_virtual_func() of derived" << std::endl;
    }
};

DEMO(VirtualPureSpecifier, Virtual) { // NOLINT(cert-err58-cpp)

    base *obj = new derived();
    obj->virtual_func(); // should output "virtual_func() of derived"

    delete (derived *) obj;

}

DEMO(VirtualPureSpecifier, PureVirtual) { // NOLINT(cert-err58-cpp)

    base *obj = new derived();
    obj->pure_virtual_func(); // should output "pure_virtual_func() of derived"

    delete (derived *) obj;

}