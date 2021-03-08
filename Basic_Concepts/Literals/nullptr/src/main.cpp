#include <iostream>

class A {};

int main() {
    // nullptr 可以 Assign 给任意 Type 的 Pointer_Type
    int *a = nullptr;
    void *b = nullptr;
    A* c = nullptr;

    std::cout << "a: " << a << std::endl
              << "b: " << b << std::endl
              << "c: " << c << std::endl;

    std::cout << "NULL: " << NULL << std::endl;

    std::cout.setf(std::ios_base::boolalpha);

    // 相等. 但不建议将 nullptr 同普通数值 Object 进行 Assignment 或 Compare 操作.
    std::cout << (nullptr == NULL) << std::endl;

    return 0;
}