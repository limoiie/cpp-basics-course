#include "demo.h"

class cls {
public:
    int i, j;

    cls(int i) // NOLINT(cppcoreguidelines-pro-type-member-init,google-explicit-constructor)
            : i(i), j(i) {
    }

    cls(cls const& c) = default;

    explicit cls(int i, int j)
            : i(static_cast<int>(i)), j(static_cast<int>(j)) {
    }

};

DEMO(ConversionConstructors, Conversion) { // NOLINT(cert-err58-cpp)

    cls c = 10; // ok: implicit conversion by calling conversion constructor `cls(int)`
    // cls d = {0, 1}; // error: chosen constructor is explicit in copy-initialization

}

DEMO(ConversionConstructors, IllConversion) { // NOLINT(cert-err58-cpp)

    int i = 10;
    cls j = cls(i, i + 1);

    // ill form: j is needed in fact, but given i by typo
    cls c = i; // no error by calling `cls(int)`, but not what we want -- `cls(cls const&)`
    // if the constructor is explicit, then compiler would have pained about this typo

    std::cout << c.i << ", " << c.j << std::endl;
    std::cout << j.i << ", " << j.j << std::endl;

}