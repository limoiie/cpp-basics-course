#include "demo.h"
#include "print_field_range.h"

DEMO_ANCHOR(memory_layout_base_with_vtable)
struct base {
    int *i{};
    double *d{};

    virtual void foo() {}
};

DEMO_ANCHOR(memory_layout_derived_with_vtable)
struct derived : public base {
    long *l{};
    const char *s{};

    void foo() override {}
    virtual void tuu() {}
};

DEMO_ANCHOR(memory_layout_derived_bro_with_vtable)
struct derived_bro : public base {
    float *f{nullptr};
    unsigned *u{nullptr};

    virtual void gee() {}
};

DEMO(RevisitSingleInheritanceMemoryLayout, DerivedMemoryLayout) { // NOLINT(cert-err58-cpp)

    std::cout.setf(std::ios_base::showbase);

    auto *p_obj = new derived();
    auto const start = to_long(p_obj);

    std::cout << "memory layout of class derive: " << std::endl;

    print_range_of_field("    base::i", p_obj->i, start);
    print_range_of_field("    base::d", p_obj->d, start);

    print_range_of_field("^^^^^^^^^^^^^^^^^^^^^^^^ base part", *(base *) p_obj, start);

    print_range_of_field(" derived::l", p_obj->l, start);
    print_range_of_field(" derived::s", p_obj->s, start);

    print_range_of_field("^^^^^^^^^^^^^^^^^^^^^ derived part", *p_obj, start);

    delete p_obj;

}

DEMO(RevisitSingleInheritanceMemoryLayout, DerivedBroMemoryLayout) { // NOLINT(cert-err58-cpp)

    std::cout.setf(std::ios_base::showbase);

    auto *p_obj = new derived_bro();
    auto const start = to_long(p_obj);

    std::cout << "memory layout of class derive_bro: " << std::endl;

    print_range_of_field("        base::i", p_obj->i, start);
    print_range_of_field("        base::d", p_obj->d, start);

    print_range_of_field("^^^^^^^^^^^^^^^^^^^^^^^^ base part", *(base *) p_obj, start);

    print_range_of_field(" derived_bro::l", p_obj->f, start);
    print_range_of_field(" derived_bro::s", p_obj->u, start);

    print_range_of_field("^^^^^^^^^^^^^^^^^ derived_bro part", *p_obj, start);

    delete p_obj;

}
