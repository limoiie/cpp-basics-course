#ifndef C___BASICS_COURSE__DEMO_UTILS_H_
#define C___BASICS_COURSE__DEMO_UTILS_H_

#include <gtest/gtest.h>

#ifndef DEMO
#  define DEMO(demo_case_name, demo_name) TEST(demo_case_name, demo_name)
#endif

#endif //C___BASICS_COURSE__DEMO_UTILS_H_
