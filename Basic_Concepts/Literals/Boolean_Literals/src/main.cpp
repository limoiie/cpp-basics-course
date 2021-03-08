#include <iostream>

int main() {
    std::cout << std::boolalpha
              << true << std::endl
              << false << std::endl
              << std::noboolalpha
              << true << std::endl
              << false << std::endl;

    return 0;
}