#include <gtest/gtest.h>

int at_least_10(int v);

// Tests:
TEST(TestAtLeastTen, Simple) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_EQ(at_least_10(-1), 10);
    ASSERT_EQ(at_least_10( 9), 10);
    ASSERT_EQ(at_least_10(10), 10);
    ASSERT_EQ(at_least_10(20), 20);
}