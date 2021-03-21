#include "demo.h"
#include "randoms.h"

DEMO(CustomizedTypesEnum, UnscopedEnum) { // NOLINT(cert-err58-cpp)

    // un-scoped enumeration
    enum color_e {
        red,
        green,
        blue
    };

    auto const c = []() {
        switch (rand_int(3)) {
            case 0:
                return red; // can access the enumerator directly
            case 1:
                return green;
            default:
                return blue;
        }
    }();

    int const i = c;
    std::cout << "(int) c == " << i << std::endl;

}

DEMO(CustomizedTypesEnum, ScopedEnum) { // NOLINT(cert-err58-cpp)

    // scoped enumeration
    enum class emotion_e {
        blue,
        happy,
        angry
    };

    auto const e = emotion_e::blue; // access the enumerator with scope qualifier 'emotion_e::'

    //int const i = e;
    int const i = (int) e;
    std::cout << "(int) emotion_e::happy == " << i << std::endl;

}

enum Number {
    ONE = 1,
    FOUR = ONE + 3,
};

DEMO(CustomizedTypesEnum, Constexpr) { // NOLINT(cert-err58-cpp)

    std::cout << ONE << std::endl;
    std::cout << FOUR << std::endl;

}