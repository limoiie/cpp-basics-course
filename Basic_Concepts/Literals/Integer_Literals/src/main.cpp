#include <iostream>

int main() {
    std::cout.setf(std::ios_base::showbase);
    std::cout << std::hex
              << 0x123 << std::endl
              << -0xafd << std::endl
              << std::oct
              << 0123 << std::endl
              << std::dec
              << 123 << std::endl;

    return 0;
}