#include "demo.h"

DEMO(LambdaExpression, SyntaxOne) { // NOLINT(cert-err58-cpp)

    int pat = 3;

    auto is_divided_by = [&](int num) -> bool {
        return (num % pat) == 0;
    };

    std::cout << is_divided_by(10) << std::endl;

}

DEMO(LambdaExpression, SyntaxTwo) { // NOLINT(cert-err58-cpp)

    int pat = 3;

    auto is_divided_by = [&](int num) { // return type is deduced as bool
        return (num % pat) == 0;
    };

    std::cout << is_divided_by(10) << std::endl;

}

DEMO(LambdaExpression, SyntaxThree) { // NOLINT(cert-err58-cpp)

    int count = 3;
    int step = 2;

    auto increment_by_step = [&] { // the whole parameters part can be
                                   // ignored if the parameter-list is empty
        return count += step;
    };

    std::cout << increment_by_step() << std::endl;

}
