#include "demo.h"


class base {
public:
    DEMO_MEMBER_ANCHOR(virtual_in_base_class)
    virtual void virtual_func() { // add the specifier virtual
        std::cout << "virtual_func() of base" << std::endl;
    }

    virtual void pure_virtual_func() = 0;

    DEMO_MEMBER_ANCHOR(virtual_destructor)
    virtual ~base() {
        std::cout << "base is released" << std::endl;
    }

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

    ~derived() override {
        std::cout << "derived is released" << std::endl;
    }

};

DEMO(VirtualDestructors, Virtual) { // NOLINT(cert-err58-cpp)

    base *p_obj = new derived();
    p_obj->virtual_func(); // should output "virtual_func() of derived"

    delete p_obj; // actually call ~derived(), should output "derived is released"

}

DEMO(VirtualDestructors, PureVirtual) { // NOLINT(cert-err58-cpp)

    base *p_obj = new derived();
    p_obj->pure_virtual_func(); // should output "pure_virtual_func() of derived"

    delete p_obj; // actually call ~derived(),
    // should output "derived is released" and "base is released"

}