#include "demo.h"

using std::string;

struct complex_int {
    int i;
    int j;

    /**
     * Support both implicit and explicit conversion to the target type `string`
     */
    operator string() const { // NOLINT(google-explicit-constructor)
        return string("complex_int(")
               + std::to_string(i) + ", "
               + std::to_string(j) + ")";
    }

    /**
     * Support explict conversion to the target type `double`
     */
    explicit operator double() const {
        return sqrt(pow(i, 2) + pow(j, 2));
    }
};

DEMO(OverloadTypeConversioinOperators, Implicit) { // NOLINT(cert-err58-cpp)

    complex_int v = {3, 4};

    string s1 = v;                       // support implicitly conversion
    string s3 = (string) v;              // support C-style explicitly conversion
    string s2 = static_cast<string>(v);  // support C++-style explicitly conversion

    std::cout << "implicit: " << s1 << std::endl;
    std::cout << "(std::string) v: " << s2 << std::endl;
    std::cout << "static_cast<std::string>(v): " << s3 << std::endl;

}

DEMO(OverloadTypeConversioinOperators, Explicit) { // NOLINT(cert-err58-cpp)

    complex_int v = {3, 4};

    // do not support implicitly conversion
    // double a = v; // error: no viable implicit conversion

    auto a = (double) v;             // support C-style explicitly conversion
    auto b = static_cast<double>(v); // support C++-style explicitly conversion

    std::cout << "(double) v: " << a << std::endl;
    std::cout << "static_cast<double>(v): " << b << std::endl;

}
