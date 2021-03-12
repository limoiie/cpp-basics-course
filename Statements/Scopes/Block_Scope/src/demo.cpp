#include "demo.h"

DEMO(BlockScope, BlockScope) { // NOLINT(cert-err58-cpp)
    // scope of the outer block begins

    int i = 0;  // name-scope of the first 'i' begins
    ++i;

    std::cout << i << " at line " << __LINE__ << std::endl;

    {  // scope of a anonymous block begins

        int i = 20; // name-scope of the second 'i' begins
        //             while the name-scope of the first 'i' is interrupted

        std::cout << i << " at line " << __LINE__ << std::endl;

        i = 100;    // this 'i' is in the name-scope and refers to the second 'i'

        std::cout << i << " at line " << __LINE__ << std::endl;

        // scope of a anonymous block ends
        // name-scope of the second 'i' ends
        // name-scope of the first 'i' resumes
    }

    std::cout << i << " at line " << __LINE__ << std::endl;

    // scope of the outer block ends
    // name-scope of the fist 'i' ends
}

DEMO(BlockScope, ControlBlockScope) { // NOLINT(cert-err58-cpp)

    volatile int i = 0;
    if (i == 0) {  // scope of block begins

        int a = 10;

        // scope of block ends
    }

    while (i++ < 5) { // scope of block begins for each loop

        // the block scope of 'while' will end for each loop
        // std::cout << a << std::endl; // error: undeclared

        int a = 10; // name-scope of 'a' begins for each loop

        // scope of block ends for each loop
        // name-scope of 'a' ends for each loop
    }


    for (; i < 10; ++i) { // scope of block begins for each loop

        // the block scope of 'for' will end for each loop
        // std::cout << a << std::endl; // error: undeclared

        int a = 10; // name-scope of 'a' begins for each loop

        // scope of block ends for each loop
    }

}

DEMO(BlockScope, OutOfControlBlockScope) { // NOLINT(cert-err58-cpp)

    // 'for' 后 `()` 内的区域即为 non-block scope 区域
    for (int a = 0;  // name-scope of 'a ' begins -+
         a < 10;     //                            +-> non-block scope area
         ++a)        //                          --+
    {
        std::cout << a << std::endl; // 'a' is in name-scope for all loops
    }
    // name-scope of 'a' ends after the whole statement

}