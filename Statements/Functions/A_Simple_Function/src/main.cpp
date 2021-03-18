#include <iostream>

// optional, for global declaration only
//  |     Symbol
//  |       |
//  V       V
extern int add(int a, int b); // 1. Declaration
//      ^       ^      ^
//      +-------|------+
//          Signature

int main() {
    std::cout << add(1, 2); // 3. Use
    return 0;
}

int add(int a, int b) { // 2. Definition
    return a + b;
}
