#include <gtest/gtest.h>

double compute(double a, double b);


// Tests:
TEST(SumTest, Simple) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_EQ(compute(2.0, 4.0), log2(2.0) + log2(4.0));
}