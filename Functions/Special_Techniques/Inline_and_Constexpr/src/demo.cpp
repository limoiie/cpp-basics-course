#include "demo.h"

inline double circle_area(double r) {
    return r * r * 3.1415;
}

DEMO(InlineAndConstexpr, Inline) { // NOLINT(cert-err58-cpp)

    circle_area(3); // 因为指定了 `inline`, 将会被直接替换成 statement: 3 * 3 * 3.1415

}

constexpr int constexpr_times(int l, int r) {
    return l * r;
}

constexpr int constexpr_pow2(int r) {
    return constexpr_times(r, r);
}

int normal_pow2(int r) { // 与 constexpr_pow2(int) 完全一致, 除了没有 constexpr
    return constexpr_times(r, r);
}

DEMO(InlineAndConstexpr, Constexpr) { // NOLINT(cert-err58-cpp)

    // non-type argument 需要是 constant expression
    std::array<int, constexpr_pow2(1)> *a; // ok
    // std::array<int, normal_pow2(1)> *b; // error: not a constant expression

}