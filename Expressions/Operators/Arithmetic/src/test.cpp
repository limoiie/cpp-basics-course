#include <exception>
#include <string>
#include <iostream>
#include <random>

template<typename T>
struct Operator {
    virtual T compute() const = 0;
    virtual std::string to_string() const = 0;
};

template<typename T>
struct UnOperator : Operator<T> {
    const char *c;
    const T val;

    __unused UnOperator(const char *c, int val)
            : c(c), val(val) {
    }

    std::string to_string() const override {
        return c + std::to_string(val);
    }

};

template<typename T>
struct BinOperator : Operator<T> {
    const char *c;
    const T lhs;
    const T rhs;

    __unused BinOperator(const char *c, int lhs, int rhs)
            : c(c), lhs(lhs), rhs(rhs) {
    }

    std::string to_string() const override {
        return std::to_string(lhs) + " " + c + " " + std::to_string(rhs);
    }
};

template<typename T>
struct Positive : UnOperator<T> {
    using super = UnOperator<T>;
    explicit Positive(int val) : super("+", val) {}
    T compute() const override {
        return super::val;
    }
};

template<typename T>
struct Negative : UnOperator<T> {
    using super = UnOperator<T>;
    explicit Negative(int val) : super("-", val) {}
    T compute() const override {
        return -super::val;
    }
};

template<typename T>
struct Add : public BinOperator<T> {
    using super = BinOperator<T>;
    Add(int lhs, int rhs) : super("+", lhs, rhs) {}
    T compute() const override {
        return super::lhs + super::rhs;
    }
};

template<typename T>
struct Minus : public BinOperator<T> {
    using super = BinOperator<T>;
    Minus(int lhs, int rhs) : super("-", lhs, rhs) {}
    T compute() const override {
        return super::lhs - super::rhs;
    }
};

template<typename T>
struct Times : public BinOperator<T> {
    using super = BinOperator<T>;
    Times(int lhs, int rhs) : super("*", lhs, rhs) {}
    T compute() const override {
        return super::lhs * super::rhs;
    }
};

template<typename T>
struct Divide : public BinOperator<T> {
    using super = BinOperator<T>;
    Divide(int lhs, int rhs) : super("/", lhs, rhs) {}
    T compute() const override {
        return super::lhs / super::rhs;
    }
};

template<typename T>
std::shared_ptr<Operator<T>> random_exp(T lhs, T rhs) {
    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_int_distribution<> dist(0, 5);

    switch (dist(e)) {
        case 0: return std::make_shared<Add<T>>(lhs, rhs);
        case 1: return std::make_shared<Minus<T>>(lhs, rhs);
        case 2: return std::make_shared<Times<T>>(lhs, rhs);
        case 3: return std::make_shared<Divide<T>>(lhs, rhs);
        case 4: return std::make_shared<Positive<T>>(lhs);
        case 5: return std::make_shared<Negative<T>>(lhs);
    }
    return nullptr;
}

#define ASSERT_EQ(expect, output)               \
if (expect != output) {                         \
  std::cerr << "Expect: " << std::endl << "\t"  \
            << expect << std::endl              \
            << "Output: " << std::endl << "\t"  \
            << output << std::endl;             \
}

void do_exercise() { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    constexpr int COUNT = 10;
    constexpr int LIMIT = 20;

    std::random_device r;
    std::default_random_engine e(r());

    std::uniform_int_distribution<> dist(-LIMIT, LIMIT);

    for (auto i = 0; i < COUNT; ++i) {
        auto lhs = dist(e);
        auto rhs = dist(e);
        auto exp = random_exp(lhs, rhs);

        std::cout << "compute " << exp->to_string() << ":" << std::endl;

        int result;
        std::cin >> result;

        ASSERT_EQ(exp->compute(), result)
    }
}
