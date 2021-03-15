#include "demo.h"

struct base {
    int *i {nullptr};
    double *d {nullptr};

    virtual void foo() {
        std::cout << "base" << std::endl;
    }
};

struct derived : public base {
    long *l {nullptr};
    const char* s {nullptr};
};

DEMO(MultipleInheritance, DerivedMemoryLayout) { // NOLINT(cert-err58-cpp)

    std::cout << sizeof(derived) << std::endl;
    std::cout << sizeof(base) << std::endl;

    auto * p_obj = new derived();

    std::cout << (void *) ((long long int) (void *) p_obj + sizeof(base)) << std::endl;
    std::cout << (void *) (&(p_obj->l)) << std::endl;

    delete p_obj;

}

struct derived_bro : public base {
    float *f {nullptr};
    unsigned *u {nullptr};
};

DEMO_ANCHOR(memory_layout_derived_derived)
struct derived_derived : public derived, public derived_bro {
    long double ld {0};
};


DEMO(MultipleInheritance, DerivedDerivedMemoryLayout) { // NOLINT(cert-err58-cpp)

    std::cout << sizeof(derived_derived) << std::endl;
    std::cout << sizeof(derived_bro) << std::endl;
    std::cout << sizeof(derived) << std::endl;
    std::cout << sizeof(base) << std::endl;

    auto * p_obj = new derived_derived();

    std::cout << (void *) ((long long int) (void *) p_obj + sizeof(base)) << std::endl;
    std::cout << (void *) (&(p_obj->l)) << std::endl;

    derived * p_derived = p_obj;
    derived_bro * p_derived_bro = p_obj;

    std::cout << p_obj << std::endl;
    std::cout << ((long) (void *) p_derived - (long) (void *) p_obj) << std::endl;
    std::cout << ((long) (void *) p_derived_bro - (long) (void *) p_obj) << std::endl;

    delete p_obj;

}

DEMO(MultipleInheritance, MultipleInheritanceMemoryLayout) { // NOLINT(cert-err58-cpp)



}