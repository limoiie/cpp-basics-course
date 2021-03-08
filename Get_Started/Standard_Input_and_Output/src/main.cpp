#include <iostream>

int main() {
    int i;
    char s[20];

    std::cout << "Please input:" << std::endl;

    // standard input
    std::cin >> i >> s;

    // standard output
    std::cout << "std::cout: " << i << ", " << s << std::endl;
    std::cerr << "std::cerr: " << i << ", " << s << std::endl;
    std::clog << "std::clog: " << i << ", " << s << std::endl;

    return 0;
}