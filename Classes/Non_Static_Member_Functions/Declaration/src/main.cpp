#include "demo.h"

DEMO(NonStaticMemberFunctions, Declaration) { // NOLINT(cert-err58-cpp)

    struct A {
        void foo();
        void foo() const;
        void foo() volatile;
        void foo() const volatile;

        void goo() &;
        void goo() &&;

        virtual void hoo();
        virtual void pure() = 0;
    };

    struct B : A {
        void hoo() override;
        void pure() final;
    };

}