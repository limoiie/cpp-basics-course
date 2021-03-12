#include "demo.h"

#include <string>

int count = 0;

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
    std::string brand = "Nescafe";

    double milk_percentage { 0.0 };
    double sugar_percentage {};

    double price;

    Cup cup_size;

    employee const &maker;

    // constructor
    coffee(double price,
           Cup cup_size,
           employee const&maker)
            : price(price)
            , cup_size(cup_size)
            , maker(maker) {
    }

};

DEMO(MemberVarInitialization, Initialization) { // NOLINT(cert-err58-cpp)

}

DEMO(MemberVarInitialization, OverwriteInitialization) { // NOLINT(cert-err58-cpp)

    count = 0;

    struct A {
        int age = ++count; // default-member-initializer

        // constructor 1
        A() {}; // use default-member-initializer   NOLINT(modernize-use-equals-default)

        // constructor 2
        A(int age) : age(age) {} // use member-initializer-list   NOLINT(google-explicit-constructor)

    };

    std::cout << "count: " << count << std::endl;
    A a = A(); // 调用 constructor 1, 运行 default-member-initializer
    std::cout << "a.age: " << a.age << std::endl;
    std::cout << "count: " << count << std::endl;

    A b = A(10); // 调用 constructor 2, default-member-initializer 被覆盖
    std::cout << "b.age: " << b.age << std::endl;
    std::cout << "count: " << count << std::endl;

}

DEMO(MemberVarInitialization, Order) { // NOLINT(cert-err58-cpp)

    count = 0;

    struct A {

        int one;
        int two = ++count;
        int three;
        int four;

        // member-initializer-list 对 initialization 顺序没有影响!
        A() : three(++count), four(++count), one(++count) {};

    };

    A a;

    std::cout << "a.one: " << a.one << std::endl;
    std::cout << "a.two: " << a.two << std::endl;
    std::cout << "a.three: " << a.three << std::endl;
    std::cout << "a.four: " << a.four << std::endl;

}
