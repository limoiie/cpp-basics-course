#include "demo.h"

DEMO(NonStaticMemberFunctions, Declaration) { // NOLINT(cert-err58-cpp)

    struct A {
        // cv qualifiers
        void foo();
        void foo() const;
        void foo() volatile;
        void foo() const volatile;

        // ref qualifiers
        void goo() &;
        void goo() &&;

        // virtual and pure specifiers
        virtual void hoo();
        virtual void pure() = 0;
    };

    struct B : A {
        // final and override specifiers
        void hoo() override;
        void pure() final;
    };

}