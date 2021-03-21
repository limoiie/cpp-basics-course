#include "demo.h"

#include <utility>

DEMO(CustomizedTypesClass, Struct) { // NOLINT(cert-err58-cpp)

    struct person_t {
    //public: // public is default
        std::string name;
        int age;

        person_t(std::string name, int age)
                : name(std::move(name)), age(age) {
        }

        void print_info() const {
            std::cout << "name: " << name
                      << "age:  " << age << std::endl;
        }

    };

    // method 1 to create an object of person_t
    auto ming = person_t("ming", 10);
    ming.print_info();

    // method 2 to create an object of person_t
    auto *p_hong = new person_t("hong", 20);
    p_hong->print_info();

    delete p_hong;

}

DEMO(CustomizedTypes, Class) { // NOLINT(cert-err58-cpp)

    class person_t {
    //private: // private is default
        std::string name;
        int age;

    public:
        person_t(std::string name, int age)
                : name(std::move(name)), age(age) {
        }

        void print_info() const {
            std::cout << "name: " << name
                      << "age:  " << age << std::endl;
        }

    };

    // method 1 to create an object of person_t
    auto ming = person_t("ming", 10);
    ming.print_info();

    // method 2 to create an object of person_t
    auto *p_hong = new person_t("hong", 20);
    p_hong->print_info();

    delete p_hong;

}