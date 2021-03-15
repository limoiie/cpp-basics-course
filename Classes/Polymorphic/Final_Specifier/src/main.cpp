#include "demo.h"

class base {
public:
    DEMO_MEMBER_ANCHOR(final_virtual)
    virtual void foo() final {
        std::cout << "base foo" << std::endl;
    }

};

class derive {
public:
    //void foo() override {} // error: foo is final
};