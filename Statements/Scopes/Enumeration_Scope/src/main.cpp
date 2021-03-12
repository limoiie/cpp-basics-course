#include <iostream>

namespace ns
{
    enum un_scoped_enum { // scope of un-scoped enum begins
        green, // name-scope of green begins
        red
        // name-scope of green is not interrupted
    }; // scope of un-scoped enum ends

    enum class scoped_enum // scope of scoped enum begins
    {
        blue
        // name-scope of blue is interrupted
    }; // scope of scoped enum begins

    void foo() {
        // since name-scope of green is not interrupted, we can use it directly
        std::cout << green << std::endl;
        // since name-scope of blue is interrupted, we cannot use it directly
        // std::cout << blue << std::endl; // error: blue is undeclared
        std::cout << (int) scoped_enum::blue << std::endl;
    }
}

int main() {
    ns::foo();
    return 0;
}