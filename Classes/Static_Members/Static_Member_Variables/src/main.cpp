#include "demo.h"

// declaration
struct cls {
    static int i;
};

// definition
int cls::i = 10;

DEMO(StaticMemberVariables, Access) { // NOLINT(cert-err58-cpp)

    std::cout << cls::i << std::endl;

}
