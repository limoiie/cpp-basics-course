#include "demo.h"

namespace
{
    struct complex_int {
        int i;
        int j;

        complex_int &operator++();       /// prefix

        const complex_int operator++(int);     /// postfix
        std::string *operator->() const; /// postfix ->

        complex_int operator+(complex_int const &other) const; /// infix
        complex_int operator+(int delta_i) const;              /// infix
        complex_int &operator=(complex_int const &other); /// infix =

        int &operator[](int idx);                  /// index
        void operator[](complex_int const &other); /// index

        void operator()();                           /// call
        int operator()(std::string const &s, int n); /// call
    };

}

namespace
{

    /// member operator
    complex_int & // return type 建议是 reference to lvalue
    complex_int::operator++() {
        std::cout << "prefix member operator++()" << std::endl;
        i = i + 1;
        return *this;
    }

    /// non member operator
    complex_int & // return type 建议是 reference to lvalue
    operator--(complex_int &v) {
        std::cout << "prefix non-member operator--()" << std::endl;
        v.i = v.i - 1;
        return v;
    }

    DEMO(OverloadComputingOperators, Prefix) { // NOLINT(cert-err58-cpp)

        complex_int x = complex_int();

        ++x;
        x.operator++();

        --x;
        operator--(x);
    }

}

namespace
{

    /// member operator
    const complex_int // return type 建议是 constant object type
    complex_int::operator++(int) { // 该 int 只是用来区分 prefix++, 实际并没用到
        std::cout << "postfix member operator++(int)" << std::endl;

        complex_int const old = *this;
        i = i + 1;
        return old;
    }

    /// non member operator
    const complex_int // return type 建议是 constant object type
    operator--(complex_int &v, int) { // 该 int 只是用来区分 prefix++, 实际并没用到
        std::cout << "postfix non-member operator--()" << std::endl;
        v.i = v.i - 1;
        return v;
    }

    DEMO(OverloadComputingOperators, Postfix) { // NOLINT(cert-err58-cpp)

        complex_int x = {0, 0};

        x++;
        x.operator++(0);

        x--;
        operator--(x, 0);
    }

}

namespace
{

    /// member operator
    complex_int // return type 可以是任意 type
    complex_int::operator+(int delta_i) const {
        std::cout << "infix member operator+(int)" << std::endl;
        complex_int x = *this;
        x.i += delta_i;
        return *this;
    }

    /// member operator
    complex_int // return type 可以是任意 type
    complex_int::operator+(complex_int const &other) const { // parameter type 可以是任意 type
        std::cout << "infix member operator+(complex_int const&)" << std::endl;
        complex_int x = *this;
        x.i += other.i;
        x.j += other.j;
        return x;
    }

    /// non-member operator
    complex_int
    operator+(complex_int const &v, int delta_i) {
        complex_int x = v;
        x.i += delta_i;
        return x;
    }

    /// non-member operator
    complex_int
    operator+(int delta_i, complex_int const &v) {
        return operator+(v, delta_i);
    }

    DEMO(OverloadComputingOperators, Infix) { // NOLINT(cert-err58-cpp)

        complex_int x = {0, 0};
        complex_int y = {1, 2};

        // member operator+(int) 与 non-member operator+(int) 都匹配如下表达式
        // x + 1; // error: ambiguous
        // 此时只能显示地调用 operator+
        x.operator+(1);

        x + y;
        x.operator+(y);

        1 + x; // 只有 non-member function 才可以实现这一

    }

}

namespace
{
    complex_int & // return type 建议是指向自身的 lvalue-reference
    complex_int::operator=(complex_int const &other) { // parameter 可以是任意 type,
        std::cout << "infix member operator=(complex_int const&)" << std::endl;
        this->i = other.i;
        this->j = other.j;
        return *this;
    }

    DEMO(OverloadComputingOperators, InfixAssign) { // NOLINT(cert-err58-cpp)

        complex_int x {};
        complex_int y = {1, 2};

        x = y;
        x.operator=(y);

    }
}

namespace
{

    int &
    complex_int::operator[](int idx) {
        if (idx == 0) return i;
        return j;
    }

    void
    complex_int::operator[](complex_int const &other) { // parameter 和 return 可以是任意 type
        std::cout << "index member operator[](complex_int const&)" << std::endl;
    }

    DEMO(OverloadComputingOperators, Index) { // NOLINT(cert-err58-cpp)

        complex_int x = {0, 0};

        x[0];
        x.operator[](0);

    }

}

namespace
{

    std::string *
    complex_int::operator->() const {
        std::cout << "postfix member operator->()" << std::endl;
        return new std::string(std::to_string(i) + ", " + std::to_string(j));
    }

    DEMO(OverloadComputingOperators, PostfixMemberAccess) { // NOLINT(cert-err58-cpp)

        complex_int x = {0, 0};

        std::cout << x->c_str() << std::endl;
        std::cout << x.operator->()->c_str() << std::endl;

    }

}

namespace
{

    void
    complex_int::operator()() {
        std::cout << "call member operator()()" << std::endl;
    }

    int // return type 可以是任意 type
    complex_int::operator()(std::string const &s, int const n) { // parameter 可以是任意 type
        std::cout << "call member operator()(std::string const&, int const)" << std::endl;
        return n;
    }

    DEMO(OverloadComputingOperators, Call) { // NOLINT(cert-err58-cpp)

        complex_int x = {1, 2};

        x();
        x.operator()();

        x("", 10);
        x.operator()("", 10);

    }

}