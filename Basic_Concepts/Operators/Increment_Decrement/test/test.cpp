#include <gtest/gtest.h>

#include <iostream>

int prefix_increment(int &a);
int postfix_increment(int &a);

int prefix_decrement(int &a);
int postfix_decrement(int &a);

// Tests:
TEST(SumTest, Simple) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    int i = 0;
    int j = 0;

    std::cout << "int i = 0;" << std::endl;

    ASSERT_EQ(prefix_increment(i), 1);
    ASSERT_EQ(i, 1);

    std::cout << "++i: " << ++j << std::endl;
    std::cout << "  i: " << j << std::endl;

    ASSERT_EQ(postfix_increment(i), 1);
    ASSERT_EQ(i, 2);

    std::cout << "i++: " << j++ << std::endl;
    std::cout << "  i: " << j << std::endl;

    ASSERT_EQ(prefix_decrement(i), 1);
    ASSERT_EQ(i, 1);

    std::cout << "--i: " << --j << std::endl;
    std::cout << "  i: " << j << std::endl;

    ASSERT_EQ(postfix_decrement(i), 1);
    ASSERT_EQ(i, 0);

    std::cout << "i--: " << j-- << std::endl;
    std::cout << "  i: " << j << std::endl;
}
