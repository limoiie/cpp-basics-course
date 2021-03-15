#include "demo.h"

#include <utility>

/**
 * Base class
 */
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

    DEMO_MEMBER_ANCHOR(expect_polymorphic_content)
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
class with_milk_t : public coffee_t {
public:
    with_milk_t(std::string const& brand, cup_e cup, double milk)
            : coffee_t(brand, cup), milk(milk) {
    }

    DEMO_MEMBER_ANCHOR(milk_content)
    std::string content() const {
        return coffee_t::content() + " with milk " + std::to_string(milk);
    }

    DEMO_MEMBER_ANCHOR(milk_change_cup)
    bool change_cup(cup_e const to_cup) {
        if (to_cup == MIDDLE_CUP) return false;
        return coffee_t::change_cup(to_cup);
    }

protected:
    double milk;

};

/**
 * Derived class
 */
class with_sugar_t : public coffee_t {
public:
    with_sugar_t(std::string const& brand, cup_e cup, double sugar)
            : coffee_t(brand, cup), sugar(sugar) {
    }

    DEMO_MEMBER_ANCHOR(sugar_content)
    std::string content() const {
        return coffee_t::content() + " with sugar " + std::to_string(sugar);
    }

protected:
    double sugar;

};

DEMO(BaseDerivedClasses, CallWrongMember) { // NOLINT(cert-err58-cpp)

    std::cout.setf(std::ios_base::boolalpha);

    coffee_t *coffee_1 = new with_milk_t("Nescafe", coffee_t::BIG_CUP, .10);

    std::cout << "expect: " << "Nescafe in big cup with milk 0.1" << std::endl;
    std::cout << "output: " << coffee_1->content() << std::endl; // wrong: call function content() of base
                                                                 // class instead of with_milk_t's

    std::cout << "expect: false" << std::endl;
    std::cout << "output: "
              << coffee_1->change_cup(coffee_t::MIDDLE_CUP) // wrong: should return false
              << std::endl;

    delete coffee_1;

}