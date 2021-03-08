#include "demo.h" // for using Macro DEMO
#include "randoms.h" // for using Function rand_int

DEMO(FlowOfControlsFor, For) { // NOLINT(cert-err58-cpp)

    for (auto i = 0; i < 10; ++i) {
        std::cout << i << ", ";
    } // Variable i 在此销毁
    std::cout << std::endl;

}

DEMO(FlowOfControlsFor, While) { // NOLINT(cert-err58-cpp)

    auto i = 0;
    while (i < 10) {
        std::cout << i << ", ";
        ++i;
    } // Variable i 在此之后依然可用!
    std::cout << std::endl;

    std::cout << "Finally i's value: " << i << std::endl;

}