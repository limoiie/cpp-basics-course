#include "demo.h"

#include <iostream>

DEMO(FundamentalTypesAuto, Auto) { // NOLINT(cert-err58-cpp)

    auto i = 10;
    auto l = 10L;
    auto s = "hello, world";

    std::cout.setf(std::ios_base::boolalpha);

    std::cout << "typeof(i) == int? " << std::is_same<typeof(i), int>::value << std::endl;
    std::cout << "typeof(l) == long? " << std::is_same<typeof(l), long>::value << std::endl;
    std::cout << "typeof(s) == const const*? " << std::is_same<typeof(s), char const*>::value << std::endl;

    std::vector<int> v;

    auto itr = v.begin(); // instead of std::vector<int>::iterator itr = v.begin();
    std::cout << "typeof(v) == std::vector<int>::iterator? "
              << std::is_same<typeof(itr), std::vector<int>::iterator>::value << std::endl;

}