#include "demo.h"

DEMO(Lambda, Simple) { // NOLINT(cert-err58-cpp)

    auto const left = 10;
    auto const right = 20;
    auto const top = 10;
    auto const bottom = 20;

    // define a lambda
    auto const is_in_area = [&](int x, int y) -> bool {
        return left <= x && x <= right &&
               top <= y && y <= bottom;
    };

    std::cout.setf(std::ios_base::boolalpha);

    // call a lambda
    std::cout << is_in_area(15, 15) << std::endl;
    std::cout << is_in_area(19, 19) << std::endl;
    std::cout << is_in_area(21, 16) << std::endl;

}