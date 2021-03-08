#include <exception>
#include <string>
#include <iostream>
#include <sstream>
#include <random>
#include <thread>

#include "randoms.h"

template<typename T>
struct Operator {
    const unsigned bits = sizeof(T) * 8;

    virtual T compute() const = 0;
    virtual std::string to_string() const = 0;

    std::string to_binary(T v) const {
        std::string r(bits, '0');
        for (int i = bits - 1; i >= 0; --i, v >>= 1) {
            r[i] = (v & 1) ? '1' : '0';
        }
        return r;
    }
};

template<typename T>
struct UnOperator : Operator<T> {
    using super = Operator<T>;
    using Operator<T>::bits;

    const char *c;
    const T val;

    __unused UnOperator(const char *c, int val)
            : c(c), val(val) {
    }

    std::string to_string() const override {
        std::stringstream ss;

        ss << c << "  " << super::to_binary(val) << std::endl
           << std::string(3 + bits, '-')        << std::endl
           <<     "=  ";

        return ss.str();
    }

};

template<typename T>
struct BinOperator : Operator<T> {
    using super = Operator<T>;
    using Operator<T>::bits;

    const char *c;
    const T lhs;
    const T rhs;

    __unused BinOperator(const char *c, int lhs, int rhs)
            : c(c), lhs(lhs), rhs(rhs) {
    }

    std::string to_string() const override {
        std::stringstream ss;

        auto const i = 3 - std::string(c).size();

        ss <<     "   " << super::to_binary(lhs) << std::endl
           << c << std::string(i, ' ') << super::to_binary(rhs) << std::endl
           << std::string(3 + bits, '-')        << std::endl
           <<     "=  ";

        return ss.str();
    }
};

template<typename T>
struct BitwiseNot : UnOperator<T> {
    using super = UnOperator<T>;
    explicit BitwiseNot(T val) : super("~", val) {}

    T compute() const override {
        return ~super::val;
    }
};

template<typename T>
struct BitwiseAnd : BinOperator<T> {
    using super = BinOperator<T>;
    BitwiseAnd(T lhs, T rhs) : super("&", lhs, rhs) {}

    T compute() const override {
        return super::lhs & super::rhs;
    }
};

template<typename T>
struct BitwiseOr : BinOperator<T> {
    using super = BinOperator<T>;
    BitwiseOr(T lhs, T rhs) : super("|", lhs, rhs) {}

    T compute() const override {
        return super::lhs | super::rhs;
    }
};

template<typename T>
struct BitwiseXor : BinOperator<T> {
    using super = BinOperator<T>;
    BitwiseXor(T lhs, T rhs) : super("^", lhs, rhs) {}

    T compute() const override {
        return super::lhs ^ super::rhs;
    }
};

template<typename T>
struct BitwiseLeftShift : BinOperator<T> {
    using super = BinOperator<T>;
    BitwiseLeftShift(T lhs, T rhs) : super("<<", lhs, rhs) {}

    T compute() const override {
        return super::lhs << super::rhs;
    }
};

template<typename T>
struct BitwiseRightShift : BinOperator<T> {
    using super = BinOperator<T>;
    BitwiseRightShift(T lhs, T rhs) : super(">>", lhs, rhs) {}

    T compute() const override {
        return super::lhs >> super::rhs;
    }
};

template<typename T>
std::shared_ptr<Operator<T>> random_exp(T lhs, T rhs) {
    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_int_distribution<T> dist(0, 5);

    switch (dist(e)) {
        case 0: return std::make_shared<BitwiseAnd<T>>(lhs, rhs);
        case 1: return std::make_shared<BitwiseOr<T>>(lhs, rhs);
        case 2: return std::make_shared<BitwiseXor<T>>(lhs, rhs);
        case 3: return std::make_shared<BitwiseNot<T>>(lhs);
        case 4: return std::make_shared<BitwiseLeftShift<T>>(lhs, rhs);
        case 5: return std::make_shared<BitwiseRightShift<T>>(lhs, rhs);
    }
    return nullptr;
}

void do_exercise() {
    constexpr int COUNT = 10;

    auto dist = rand_dist<std::uint8_t>(0xFF);
    for (auto i = 0; i < COUNT; ++i) {
        auto lhs = dist();
        auto rhs = dist();
        auto exp = random_exp(lhs, rhs);

        std::cout << std::endl << std::endl << exp->to_string();

        std::string result;
        std::cin >> result;

        auto expect = exp->to_binary(exp->compute());
        if (result != expect) {
            std::cerr << "Output: " << std::endl << "\t"
                      << result << std::endl
                      << "Expect: " << std::endl << "\t"
                      << expect << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}
