#include "demo.h"

DEMO(StandardInputOutput, Output) { // NOLINT(cert-err58-cpp)

    auto const i = 10;
    std::cout << i << std::endl;

}

DEMO_ANCHOR(stdio_cin_multiple_inputs)
int main() {
    int i;
    char s[20];

    // standard input
    std::cin >> i >> s; // separated by spaces or returns

    std::cout << "Get from user: " << i << ", " << s << std::endl;

    return 0;
}

DEMO(StandardInputOutput, OutputCompare) { // NOLINT(cert-err58-cpp)

    auto const i = 10;
    auto const s = "hello, world";

    // standard output
    std::cout << "std::cout: " << i << ", " << s << std::endl;
    std::cerr << "std::cerr: " << i << ", " << s << std::endl;
    std::clog << "std::clog: " << i << ", " << s << std::endl;

}
