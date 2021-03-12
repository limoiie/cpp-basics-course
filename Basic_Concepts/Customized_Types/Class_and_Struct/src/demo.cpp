#include "demo.h"

#include <utility>

struct Person {
    std::string name;
    int age;

    Person(std::string name, int age)
            : name(std::move(name)), age(age) {
    }

    void print_info() const {
        std::cout << "name: " << name
                  << "age:  " << age << std::endl;
    }

};

DEMO(CustomizedTypesClass, Simple) { // NOLINT(cert-err58-cpp)

    // method 1 to create an object of Person
    auto ming = Person("ming", 10);
    ming.print_info();

    // method 2 to create an object of Person
    auto *p_hong = new Person("hong", 20);
    p_hong->age += 3;
    p_hong->print_info();

    delete p_hong;

}