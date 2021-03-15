#include "demo.h"
#include "print_field_range.h"

struct base {
    int *i {};
    double *d {};

    virtual void foo() {}
};

struct derived : virtual public base {
    long *l {};
    const char* s {};
};

struct derived_bro : virtual public base {
    float *f {nullptr};
    unsigned *u {nullptr};
};

struct multi_derived : public derived, public derived_bro {
    short *h {nullptr};

    virtual void goo() {}
};

DEMO(VirtualInheritance, DerivedMemoryLayout) { // NOLINT(cert-err58-cpp)

    std::cout.setf(std::ios_base::showbase);

    auto *p_obj = new derived();
    auto const start = to_long(p_obj);

    std::cout << "memory layout of class derive: " << std::endl;

    std::cout << "========================= p_vtable of class derived" << std::endl;

    print_range_of_field(" derived::l", p_obj->l, start);
    print_range_of_field(" derived::s", p_obj->s, start);

    std::cout << "========================= p_vtable" << std::endl;

    print_range_of_field("    base::i", p_obj->i, start);
    print_range_of_field("    base::d", p_obj->d, start);

    print_range_of_field("^^^^^^^^^^^^^^^^^^^^^^^^ base part", *(base *) p_obj, start);

    print_range_of_field("^^^^^^^^^^^^^^^^^^^^^ derived part", *p_obj, start);

    auto p_base = new base();

    delete p_obj;

}

DEMO(VirtualInheritance, DerivedBroMemoryLayout) { // NOLINT(cert-err58-cpp)

    std::cout.setf(std::ios_base::showbase);

    auto *p_obj = new derived_bro();
    auto const start = to_long(p_obj);

    std::cout << "memory layout of class derive_bro: " << std::endl;

    print_range_of_field(" derived_bro::l", p_obj->f, start);
    print_range_of_field(" derived_bro::s", p_obj->u, start);

    print_range_of_field("        base::i", p_obj->i, start);
    print_range_of_field("        base::d", p_obj->d, start);

    print_range_of_field("^^^^^^^^^^^^^^^^^^^^^^^^ base part", *(base *) p_obj, start);

    print_range_of_field("^^^^^^^^^^^^^^^^^ derived_bro part", *p_obj, start);
    delete p_obj;

}

DEMO(VirtualInheritance, MultiDerivedMemoryLayout) { // NOLINT(cert-err58-cpp)

    std::cout.setf(std::ios_base::showbase);

    auto * p_obj = new multi_derived();
    auto const start = to_long(p_obj);

    std::cout << "memory layout of class multi_derive: " << std::endl;

    print_range_of_field("     derived::l", p_obj->l, start);
    print_range_of_field("     derived::s", p_obj->s, start);

    print_range_of_field("^^^^^^^^^^^^^^^^^^^^^^^^^^derived part", *(derived *) p_obj, start);

    print_range_of_field(" derived_bro::f", p_obj->f, start);
    print_range_of_field(" derived_bro::u", p_obj->u, start);

    print_range_of_field("^^^^^^^^^^^^^^^^^^^^^^derived_bro part", *(derived_bro *) p_obj, start);

    print_range_of_field("        base::i", p_obj->i, start);
    print_range_of_field("        base::d", p_obj->d, start);

    print_range_of_field("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^base part", *(base *) p_obj, start);

    print_range_of_field("^^^^^^^^^^^^^^^^^^^^multi_derived part", *p_obj, start);

    auto * p_derived = (derived *) p_obj;
    std::cout << &(p_derived->i) << std::endl;

    auto * p_derived_bro = (derived_bro *) p_obj;
    std::cout << &(p_derived_bro->i) << std::endl;

    delete p_obj;

}
