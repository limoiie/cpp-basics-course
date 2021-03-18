#include "demo.h"
#include "randoms.h"

enum Color {
    red,
    green,
    blue
};

Color random_color() {
    switch (rand_int(3)) {
        case 0:
            return red;
        case 1:
            return green;
        default:
            return blue;
    }
}

DEMO(CustomizedTypesEnum, Simple) { // NOLINT(cert-err58-cpp)

    // un-scoped enumeration
    Color c = random_color();

    switch (c) {
        case red: // access the enumerator directly
            std::cout << "red" << std::endl;
            break;
        case green:
            std::cout << "green" << std::endl;
            break;
        case blue:
            std::cout << "blue" << std::endl;
            break;
    }

}

enum class Emotion {
    blue,
    happy,
    angry
};

DEMO(CustomizedTypesEnum, UnScopedVsScoped) { // NOLINT(cert-err58-cpp)

    // un-scoped enumeration
    Color c = blue; // access the enumerator directly

    // scoped enumeration
    Emotion s = Emotion::blue; // access the enumerator with the prefix Size::

}

enum Number {
    ONE = 1,
    TWO = ONE + 1,
};

DEMO(CustomizedTypesEnum, WithInit) { // NOLINT(cert-err58-cpp)

    std::cout << ONE << std::endl;
    std::cout << TWO << std::endl;

}