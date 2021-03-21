#include "demo.h"

struct vec {
    int *p_vec = nullptr;
    int size;

    // constructor
    vec(size_t const size, int const value)
            : size(size) {
        p_vec = new int[size];
        for (auto i = 0; i < size; ++i) {
            p_vec[i] = value;
        }
    }

    // destructor
    ~vec() {
        delete p_vec;
    }

    // copy constructor
    vec(vec const& other) {
        std::cout << "vec copy constructor is called" << std::endl;

        delete p_vec;
        p_vec = new int[other.size];
        size = other.size;

        // must copy the big vector
        std::copy_n(other.p_vec, other.size, p_vec);
    }

    DEMO_MEMBER_ANCHOR(lrvalue_move_constructor)
    // move constructor
    vec(vec && other)  noexcept {
        std::cout << "vec move constructor is called" << std::endl;

        // we know that other is rvalue and it will be destroyed after this call
        // hence, here we just take its vector over without copy
        delete p_vec;
        p_vec = other.p_vec;
        size = other.size;

        other.p_vec = nullptr;
    }

};

vec make_very_big_vec() {
    vec big_vec(1000000, 10);
    vec another_big_vec(200000, 20);

    if (random() % 2 == 1) {
        return another_big_vec;
    }
    return big_vec;
}

DEMO(LValueRValue, RValueAvoidCopy) { // NOLINT(cert-err58-cpp)

    vec v = make_very_big_vec();

}
