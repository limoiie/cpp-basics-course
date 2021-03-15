#include "demo.h"

class cls {
public:
    DEMO_MEMBER_ANCHOR(constructor)
    cls(const int a, const int& b)
            : v_int()
            , v_const_int(a)
            , v_const_ref_int(b) {
    }

    DEMO_MEMBER_ANCHOR(delegating_constructor)
    explicit
    cls(const int& b)
            : cls(0, b) { // 调用 cls(const int, const int&)
    }

private:
    int v_int;
    const int v_const_int;
    const int& v_const_ref_int;

};
