#include "demo.h" // for using Macro DEMO
#include "randoms.h" // for using Function rand_int

DEMO(FlowOfControlsSwitch, Switch) { // NOLINT(cert-err58-cpp)

    auto a = rand_int(3);
    switch (1 + a) {
        case 1:
            std::cout << "enter case 1 == 1 + " << a << std::endl;
            break;
        case 1 + 1:
            std::cout << "enter case 2 == 1 + " << a << std::endl;
            break;
        case 1 + 2:
            std::cout << "enter case 3 == 1 + " << a << std::endl;
            break;
        default:
            std::cout << "Impossible value: " << a << std::endl;
            break;
    }

}


DEMO(FlowOfControlsSwitch, SwitchBreak) { // NOLINT(cert-err58-cpp)

    auto a = rand_int(4);
    switch (a) {
        case 0:
        case 1:
            std::cout << "enter case 1 with " << a << std::endl;
        case 2:
            std::cout << "enter case 2 with " << a << std::endl;
            break;
        case 3:
            std::cout << "enter case 3 with " << a << std::endl;
            break;
        default:
            std::cout << "Impossible value: " << a << std::endl;
            break;
    }

}


DEMO(FlowOfControlsSwitch, SwitchEnum) { // NOLINT(cert-err58-cpp)

    enum color {
        BLACK,
        GREEN,
        RED,
        BLUE
    };

    switch (rand_int(4)) {
        case BLACK:
            std::cout << "enter case BLACK" << std::endl;
            break;
        case GREEN:
            std::cout << "enter case GREEN" << std::endl;
            break;
        case RED:
            std::cout << "enter case RED" << std::endl;
            break;
        case BLUE:
            std::cout << "enter case BLUE" << std::endl;
            break;
        default:
            std::cout << "Impossible value!" << std::endl;
            break;
    }

}


DEMO(FlowOfControlsSwitch, SwitchDef) { // NOLINT(cert-err58-cpp)

    switch (auto a = rand_int(3)) {
        case 0:
            std::cout << "enter case 0 since you get a " << a << std::endl;
            break;
        case 1:
            std::cout << "enter case 1 since you get a " << a << std::endl;
            break;
        case 2:
            std::cout << "enter case 2 since you get a " << a << std::endl;
            break;
        default:
            std::cout << "Impossible value: " << a << std::endl;
            break;
    }

}
