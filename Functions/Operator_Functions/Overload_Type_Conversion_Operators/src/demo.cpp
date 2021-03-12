#include "demo.h"

using std::string;

struct complex_int {
    int i;
    int j;

    /**
     * Support both implicit and explicit conversion to the target type `string`
     */
    operator string() const; // NOLINT(google-explicit-constructor)

    /**
     * Support explict conversion to the target type `double`
     */
    explicit operator double() const;
};

complex_int::operator string() const {
    return string("complex_int(")
           + std::to_string(i) + ", "
           + std::to_string(j) + ")";
}

DEMO(OverloadTypeConversioinOperators, Explicit) { // NOLINT(cert-err58-cpp)

    complex_int v = {3, 4};

    string s1 = v;                       // 支持 implicitly conversion
    string s3 = (string) v;              // 老式 explicitly conversion (C++11 之前)
    string s2 = static_cast<string>(v);  // 新式 explicitly conversion (C++11 之后)

    std::cout << "implicit: " << s1 << std::endl;
    std::cout << "(std::string) v: " << s2 << std::endl;
    std::cout << "static_cast<std::string>(v): " << s3 << std::endl;

}

complex_int::operator double() const {
    return sqrt(pow(i, 2) + pow(j, 2));
}

DEMO(OverloadTypeConversioinOperators, Implicit) { // NOLINT(cert-err58-cpp)

    complex_int v = {3, 4};

    // 不支持 implicitly conversion
    // double a = v; // error: no viable implicit conversion

    auto a = (double) v;             // 老式 explicitly conversion (C++11 之前)
    auto b = static_cast<double>(v); // 新式 explicitly conversion (C++11 之后)

    std::cout << "(double) v: " << a << std::endl;
    std::cout << "static_cast<double>(v): " << b << std::endl;

}
