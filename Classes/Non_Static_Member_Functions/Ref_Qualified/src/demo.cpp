#include "demo.h"

struct cls {
    void foo() & {
        // (*this) has type T&
        //hoo(); // error: `this` is an lvalue, but function has
                 // rvalue ref-qualifier
    }
    void foo() && {
        // (*this) has type T&
        goo();
        //hoo(); // error: `this` is an lvalue, but function has
                 // rvalue ref-qualifier
    }
    void goo() & {
        // (*this) has type T&

    }
    void hoo() && {
        // (*this) has type T&

    }

};

DEMO(MemberFunctionsRefQualified, Access) { // NOLINT(cert-err58-cpp)
    cls a;
    a.foo();
    //a.hoo();

    cls().foo();
}