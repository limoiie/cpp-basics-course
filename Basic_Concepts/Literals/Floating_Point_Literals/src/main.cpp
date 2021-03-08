#include <iostream>

int main() {
    std::cout << 10e2F << ", " << 10e-5 << std::endl;
    std::cout << 10.e10F << ", " << 10. << ", " << 10.F << std::endl;
    std::cout << 10.10e5L << ", " << .10 << ", " << .10L << std::endl;
    return 0;
}