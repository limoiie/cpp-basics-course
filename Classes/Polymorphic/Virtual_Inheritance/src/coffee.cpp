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

    virtual std::string content() const {
        return brand + " in " + cup_to_string(cup);
    }

    virtual bool change_cup(cup_e to_cup) {
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
class with_milk_t : virtual public coffee_t {
public:
    with_milk_t(std::string const& brand, cup_e cup, double milk)
            : coffee_t(brand, cup), milk(milk) {
    }

    std::string content() const override {
        return coffee_t::content() + " with milk " + std::to_string(milk);
    }

    bool change_cup(cup_e to_cup) override {
        if (to_cup == MIDDLE_CUP) return false;
        return coffee_t::change_cup(to_cup);;
    }

protected:
    double milk;

};

/**
 * Derived class
 */
class with_sugar_t : virtual public coffee_t {
public:
    with_sugar_t(std::string const& brand, cup_e cup, double sugar)
            : coffee_t(brand, cup), sugar(sugar) {
    }

    std::string content() const override {
        return coffee_t::content() + " with sugar " + std::to_string(sugar);
    }

protected:
    double sugar;

};

class with_milk_and_sugar_t : public with_milk_t, public with_sugar_t {
public:
    with_milk_and_sugar_t(std::string const& brand, cup_e cup, double milk, double sugar)
            : coffee_t(brand, cup)
            , with_milk_t(brand, cup, milk)
            , with_sugar_t(brand, cup, sugar) {
        this->milk = milk;
        this->sugar = sugar;
    }

    std::string content() const override {
        return with_milk_t::content() + " && " + with_sugar_t::content();
    }

    bool change_cup(cup_e to_cup) override {
        return with_milk_t::change_cup(to_cup);
    }

};

DEMO(VirtualInheritance, SomethingWrong) { // NOLINT(cert-err58-cpp)

    with_milk_and_sugar_t coffee("Nescafe", coffee_t::BIG_CUP, .1, .2);
    coffee.change_cup(coffee_t::SUPER_CUP);
    std::cout << coffee.content() << std::endl; // ok: both are super cup

}
