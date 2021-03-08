#include <iostream>

int main() {
    int a, b, c;

    a = b = c = 5;
    std::cout << "a, b, c == " << a << ", " << b << ", " << c << std::endl << std::endl;

    std::cout << "(a = 10) = 20  == "
              << ((a = 10) = 20)  // 等价于 a = 10; a = 20;
              << std::endl;
    std::cout << "after (a = 10) = 20, a == "
              << a << std::endl;

    return 0;
}