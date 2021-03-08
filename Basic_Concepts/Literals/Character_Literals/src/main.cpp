#include <iostream>

int main() {
    std::cout.setf(std::ios_base::showbase);

    auto c0 = 'A';
    std::cout << std::hex << "c0 == " << c0 << ", type == char? " << std::boolalpha
              << std::is_same<typeof(c0), char>::value << std::endl;

    auto c1 = u'貓';
    std::cout << std::hex << "c1 == " << c1 << ", type == char16_t? " << std::boolalpha
              << std::is_same<typeof(c1), char16_t>::value << std::endl;

    auto c2 = U'貓';
    std::cout << std::hex << "c2 == " << c2 << ", type == char32_t? " << std::boolalpha
              << std::is_same<typeof(c2), char32_t>::value << std::endl;

    auto c5 = L'A';
    std::cout << std::hex << "c5 == " << c5 << ", type == wchar_t? " << std::boolalpha
              << std::is_same<typeof(c5), wchar_t>::value << std::endl;

    auto c6 = 'AB';
    std::cout << std::hex << "c6 == " << c6 << ", type == int? " << std::boolalpha
              << std::is_same<typeof(c6), int>::value << std::endl;

    auto c7 = L'AB';
    std::cout << std::hex << "c7 == " << c7 << ", type == wchar_t? " << std::boolalpha
              << std::is_same<typeof(c7), wchar_t>::value << std::endl;

    return 0;
}