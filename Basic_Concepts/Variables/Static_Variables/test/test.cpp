#include <gtest/gtest.h>

extern double pi;
double area_of_circle(double radius);


// Tests:
TEST(AreaOfCircleTest, Simple) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_EQ(area_of_circle(1.3), 1.3 * 1.3 * pi);
}