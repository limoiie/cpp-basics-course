#include "demo.h"

DEMO(CompoundTypesArray, Array) { // NOLINT(cert-err58-cpp)

    int a[3] = {1, 2, 3};

    std::cout << a[0] << ", " << a[1] << ", " << a[2] << std::endl;

    a[1] = 9;

    std::cout << a[0] << ", " << a[1] << ", " << a[2] << std::endl;

}

DEMO(CompoundTypesArray, ArrayAndPointer) { // NOLINT(cert-err58-cpp)

    int a[3] = {1, 2, 3};

    int *p_a = a;

    std::cout << "array a:     " << a[0] << ", " << a[1] << ", " << a[2] << std::endl;
    std::cout << "pointer p_a: " << p_a[0] << ", " << p_a[1] << ", " << p_a[2] << std::endl;

    p_a[1] = 9;
    std::cout << "after p_a[1] = 9;" << std::endl;

    std::cout << "array a:     " << a[0] << ", " << a[1] << ", " << a[2] << std::endl;
    std::cout << "pointer p_a: " << p_a[0] << ", " << p_a[1] << ", " << p_a[2] << std::endl;

}
