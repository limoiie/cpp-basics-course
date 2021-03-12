#include "demo.h"

//                                         columns  1  2   3  4
DEMO(Scopes, Scope) { // NOLINT(cert-err58-cpp) //  b
                                                //  b
    volatile int i = 0;                         //  b      i
    if (i > 0) {                                //  b  b   i
        std::cout << "enter if" << std::endl;   //  b  b   i
        // name i 的 name-scope 被截断           //  b  b   i
        int i = 2;                              //  b  b      i
        std::cout << "i: " << i << std::endl;   //  b  b      i
    }                                           //  b  b      i
                                                //  b      i
}                                               //  b
//                                                |--+--| |--+--|
//                  +--------------------------------+       +------+
//                  V                                               V
//             block's scope                               name's name-scope
//      第 1 列是最外层的 block scope;                  第 3 列是外层 variable i 的 scope;
//      第 2 列是 if 的 block scope;                   第 4 列是内层 variable i 的 scope;
//                                           可发现外层 i 的 scope 被内层 i 的 declaration 截断了;