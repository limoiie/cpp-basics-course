#include "demo.h"

DEMO(StringLiterals, String) { // NOLINT(cert-err58-cpp)

    auto s1 = "Ordinary String Literal";
    std::cout << s1 << std::endl;

    auto s2 = u"UTF-16 String Literal";
    std::cout << s2 << std::endl;

    auto s3 = U"UTF-32 String Literal";
    std::cout << s3 << std::endl;

    auto s4 = R"('\n' is a escaped character)";
    std::cout << s4 << std::endl;

}

DEMO(StringLiterals, MultiLineString) { // NOLINT(cert-err58-cpp)

    auto s1 = "this is a "
              "multi-line String"
              "!";
    std::cout << "s1: " << s1 << std::endl;

}

DEMO(StringLiterals, RawStringLiteral) { // NOLINT(cert-err58-cpp)

    // the escape character won't be escaped in a raw string literal
    auto s1 = R"('\n' is a escaped character)"; // == "'\\n' is a escaped character"
    auto s2 =   "'\n' is a escaped character";

    std::cout << "s1: " << s1 << std::endl
              << "s2: " << s2 << std::endl;

    // you can insert double-quote " in a raw string literal
    auto s3 = R"(Raw string Literal can contains any number of ": """")";
    std::cout << s3 << std::endl;

}