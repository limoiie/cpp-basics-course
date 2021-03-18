#include <__bit_reference>
#ifndef C___BASICS_COURSE__DEMO_UTILS_H_
#define C___BASICS_COURSE__DEMO_UTILS_H_

#include <gtest/gtest.h>

#ifndef DEMO
#  define DEMO(demo_case_name, demo_name) TEST(demo_case_name, demo_name)
#endif

#ifndef DEMO_BOUNDARY
#  define DEMO_BOUNDARY(N) namespace ns_##N
//#  define DEMO_BOUNDARY_END(N)
#endif

#ifndef DEMO_MEMBER_ANCHOR
# define DEMO_MEMBER_ANCHOR(id) friend void __only_for_anchor_used__##id();
#endif

#ifndef DEMO_ANCHOR
# define DEMO_ANCHOR(id) void __only_for_anchor_used__##id();
#endif

__unused static auto __x = [] { // NOLINT(cppcoreguidelines-interfaces-global-init,bugprone-reserved-identifier,cert-err58-cpp)
    // for outputting bool as 'true' or 'false'
    std::cout.setf(std::ios_base::boolalpha);

    // for showing 0x for hex, 0 for oct and 0b for binary integers
    std::cout.setf(std::ios_base::showbase);
    return nullptr;
}();

#endif //C___BASICS_COURSE__DEMO_UTILS_H_
