#include <string>

struct employee {
    std::string name;
    int age;

};

struct coffee {

    enum Cup {
        BIG_CUP,
        MIDDLE_CUP,
        SMALL_CUP
    };

    /**
     * Brand of coffee:
     * - Starbucks
     * - Costa Coffee
     * - Nescafe
     * - Maxwell House
     * - ...
     */
    std::string brand;

    double milk_percentage;
    double sugar_percentage;

    double price;

    Cup cup_size;

    employee const &maker;

};