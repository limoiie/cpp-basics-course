#include "demo.h"

DEMO(MacroDefine, Define) { // NOLINT(cert-err58-cpp)

#define ALL_DAYS_PER_YEAR 365
#define PI 3.141592654
#define OPERATING_SYSTEM_NAME "Ubuntu"

    std::cout << "How many days in one year? " << ALL_DAYS_PER_YEAR << std::endl;
    std::cout << "What is the value of pi?" << PI << std::endl;
    std::cout << "Give a name of linux system: " << OPERATING_SYSTEM_NAME << std::endl;

}

DEMO(MacroDefine, Expanding) { // NOLINT(cert-err58-cpp)

#define VAR_NAME age
    int VAR_NAME = 10; // exactly equals to 'int age = 10;'

    std::cout << age << std::endl;

}
