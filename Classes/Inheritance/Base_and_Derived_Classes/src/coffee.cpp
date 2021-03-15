#include "demo.h"

#include <utility>

/**
 * Base class
 */
DEMO_ANCHOR(base_and_derived_classes)
class coffee_t {
public:
    enum cup_e {
        SUPER_CUP,
        BIG_CUP,
        MIDDLE_CUP,
    };

    explicit
    coffee_t(std::string brand, cup_e cup)
            : brand(std::move(brand))
            , cup(cup) {
    }

    std::string content() const {
        return brand + " in " + cup_to_string(cup);
    }

    bool change_cup(cup_e const to_cup) {
        cup = to_cup;
        return true;
    }

    static std::string cup_to_string(cup_e cup) {
        switch (cup) {
            case SUPER_CUP: return "super cup";
            case BIG_CUP: return "big cup";
            case MIDDLE_CUP: return "middle cup";
        }
    }

protected:
    std::string brand;
    cup_e cup;

};

/**
 * Derived class
 */
class with_milk_t : coffee_t {
public:
    with_milk_t(std::string const& brand, cup_e cup, double milk)
            : coffee_t(brand, cup), milk(milk) {
    }

protected:
    double milk;

};

/**
 * Derived class
 */
class with_sugar_t : coffee_t {
public:
    with_sugar_t(std::string const& brand, cup_e cup, double sugar)
            : coffee_t(brand, cup), sugar(sugar) {
    }

protected:
    double sugar;

};

DEMO(BaseDerivedClasses, CannotAccessPublicMemberOfBaseClass) { // NOLINT(cert-err58-cpp)

    coffee_t coffee("Maxwell House", coffee_t::MIDDLE_CUP);
    std::cout << coffee.content() << std::endl; // content() is accessible

    with_milk_t milk_coffee("Nescafe", coffee_t::SUPER_CUP, .10);
    // milk_coffee.content(); // error: content() is a private member of `coffee_t`?!

}