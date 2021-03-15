#include "demo.h"

DEMO_ANCHOR(virtual_table_base_exmaple)
class base {
public:
    virtual void foo() = 0;
    virtual void too() {}

};

DEMO_ANCHOR(virtual_table_derived_exmaple)
class derived : base {
public:
    void foo() override {}
    virtual void goo() {}
    void hoo() {}
};
