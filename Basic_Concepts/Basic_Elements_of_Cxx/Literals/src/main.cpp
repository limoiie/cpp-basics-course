#include <iostream>

int main() {
    auto i1 = 10;
    std::cout << "type(i1): " << typeid(i1).name() << std::endl;
    auto l1 = 10l;
    std::cout << "type(l1): " << typeid(l1).name() << std::endl;
    auto ll1 = 10ll;
    std::cout << "type(ll1): " << typeid(ll1).name() << std::endl;

    auto ui1 = 10u;
    std::cout << "type(ui1): " << typeid(ui1).name() << "==" << typeid(unsigned int).name() << std::endl;
    auto ul1 = 10ul;
    std::cout << "type(ul1): " << typeid(ul1).name() << "==" << typeid(unsigned long).name() << std::endl;
    auto ull1 = 10ull;
    std::cout << "type(ull1): " << typeid(ull1).name() << "==" << typeid(unsigned long long).name() << std::endl;

    auto f1 = 10.0f;
    std::cout << "type(f1): " << typeid(f1).name() << std::endl;
    auto f2 = 10.f;
    std::cout << "type(f2): " << typeid(f2).name() << std::endl;
    auto f3 = 10e-4f;
    std::cout << "type(f3): " << typeid(f3).name() << std::endl << std::endl;

    auto d1 = 10.0;
    std::cout << "type(d1): " << typeid(d1).name() << std::endl;
    auto d2 = 10.;
    std::cout << "type(d2): " << typeid(d2).name() << std::endl;
    auto d3 = 10e-4;
    std::cout << "type(d3): " << typeid(d3).name() << std::endl;

    return 0;
}