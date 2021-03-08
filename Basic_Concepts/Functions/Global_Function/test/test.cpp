#include <gtest/gtest.h>

int sum(int a, int b);


// Tests:
TEST(SumTest, Simple) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_EQ(sum(1, 2), 3);
    ASSERT_EQ(sum(2, 4), 6);
}