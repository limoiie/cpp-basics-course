#include "demo.h"

class cls {
public:
    DEMO_MEMBER_ANCHOR(explicit_demo)
    explicit cls(int i)
            : i(i) {
    }

private:
    int i;
};

DEMO(ExplicitSpecifier, Explicit) { // NOLINT(cert-err58-cpp)

    // cls c = 10; // error: no viable conversion from 'int' to 'cls'
                   // because `cls(int)` cannot be used as conversion constructor

    cls d = cls(10); // ok: call `cls(int)` explicitly

}
