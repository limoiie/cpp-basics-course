#include "demo.h"
#include "print_field_range.h"

DEMO_ANCHOR(memory_layout_multi_base_with_vtable)
struct base {
    int *i {};
    double *d {};

    virtual void foo() {}
};

struct derived : public base {
    long *l {};
    const char* s {};

    void foo() override {}
    virtual void tuu() {}
};

struct derived_bro : public base {
    float *f {nullptr};
    unsigned *u {nullptr};

    virtual void gee() {}
};

DEMO_ANCHOR(memory_layout_multi_derived_with_vtable)
struct multi_derived : public derived, public derived_bro {
    short *h {nullptr};

    void tuu() override {}
    void gee() override {}
    virtual void haa() {}

    void non() {}
};


DEMO(RevisitMultipleInheritanceMemoryLayout, MultiDerivedMemoryLayout) { // NOLINT(cert-err58-cpp)

    std::cout.setf(std::ios_base::showbase);

    auto * p_obj = new multi_derived();
    auto const start = to_long(p_obj);

    std::cout << "memory layout of class multi_derive: " << std::endl;

    std::cout << "========================== p_vtable" << std::endl;

    print_range_of_field("         base::i", ((derived *) p_obj)->i, start);
    print_range_of_field("         base::d", ((derived *) p_obj)->d, start);

    print_range_of_field("^^^^^^^^^^^^^^^^^^^^^^derived#base part", *(base *) (derived *) p_obj, start);

    print_range_of_field("      derived::l", p_obj->l, start);
    print_range_of_field("      derived::s", p_obj->s, start);

    print_range_of_field("^^^^^^^^^^^^^^^^^^^^^^^^^^^derived part", *(derived *) p_obj, start);

    std::cout << "========================== p_vtable" << std::endl;

    print_range_of_field("         base::i", ((derived_bro *) p_obj)->i, start);
    print_range_of_field("         base::d", ((derived_bro *) p_obj)->d, start);

    print_range_of_field("^^^^^^^^^^^^^^^^^^derived_bro#base part", *(base *) (derived_bro *) p_obj, start);

    print_range_of_field("  derived_bro::f", p_obj->f, start);
    print_range_of_field("  derived_bro::u", p_obj->u, start);

    print_range_of_field("^^^^^^^^^^^^^^^^^^^^^^^derived_bro part", *(derived_bro *) p_obj, start);

    print_range_of_field("multi_derived::h", p_obj->h, start);

    print_range_of_field("^^^^^^^^^^^^^^^^^^^^^multi_derived part", *p_obj, start);

    p_obj->gee();
    p_obj->haa();
    p_obj->non();

    delete p_obj;

}
