#include <iostream>

int main() {
    std::cout << "sizeof(bool): " << sizeof(bool) << std::endl << std::endl;

    std::cout << "sizeof(char): " << sizeof(char) << std::endl;
    std::cout << "sizeof(char16_t): " << sizeof(char16_t) << std::endl;
    std::cout << "sizeof(char32_t): " << sizeof(char32_t) << std::endl << std::endl;
    std::cout << "sizeof(wchar_t): " << sizeof(wchar_t) << std::endl;

    std::cout << "sizeof(short): " << sizeof(short) << std::endl;
    std::cout << "sizeof(int): " << sizeof(int) << std::endl;
    std::cout << "sizeof(long): " << sizeof(long) << std::endl;
    std::cout << "sizeof(long long): " << sizeof(long long) << std::endl << std::endl;

    std::cout << "sizeof(float): " << sizeof(float) << std::endl;
    std::cout << "sizeof(double): " << sizeof(double) << std::endl << std::endl;

    unsigned unsigned_value = -1;
    std::cout << "unsigned -1 == " << unsigned_value << std::endl;

    signed signed_value = -1;
    std::cout << "signed -1 == " << signed_value << std::endl;

    return 0;
}