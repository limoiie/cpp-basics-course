#include "demo.h"

DEMO(FundamentalTypesCharacter, Similarity) { // NOLINT(cert-err58-cpp)
    std::cout.setf(std::ios_base::boolalpha); // let cout output "true" or "false" for boolean value

    std::cout << "   char == unsigned char? " << std::is_same<char, unsigned char>::value << std::endl;
    std::cout << "   char == signed char? " << std::is_same<char, signed char>::value << std::endl;
    std::cout << "wchar_t == char16_t? " << std::is_same<wchar_t, char16_t>::value << std::endl;
    std::cout << "wchar_t == char32_t? " << std::is_same<wchar_t, char32_t>::value << std::endl;
}

DEMO(FundamentalTypesCharacter, Size) { // NOLINT(cert-err58-cpp)
    std::cout << "sizeof(char): " << sizeof(char) << std::endl;
    std::cout << "sizeof(signed char): " << sizeof(signed char) << std::endl;
    std::cout << "sizeof(unsigned char): " << sizeof(unsigned char) << std::endl;
    std::cout << "sizeof(wchar_t): " << sizeof(wchar_t) << std::endl;
    std::cout << "sizeof(char16_t): " << sizeof(char16_t) << std::endl;
    std::cout << "sizeof(char32_t): " << sizeof(char32_t) << std::endl;
}