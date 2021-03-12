#include "demo.h"

#include <chrono>

namespace experiment
{
    struct seconds {
        long long count;

        seconds() : count(0) {
        }
        // ...
    };
}

DEMO(TypeAlias, Simple) { // NOLINT(cert-err58-cpp)

    // 为来自不同 namespace 的 同名 type 创建便于访问的 type alias
    using std_sec = std::chrono::seconds;
    using my_sec = experiment::seconds;

    std_sec sec1 = std_sec(0); // 可以使用 constructor
    std::cout << sec1.count() << std::endl;

    my_sec sec2 = my_sec(); // 可以使用 constructor
    std::cout << sec2.count << std::endl;

    std::cout.setf(std::ios_base::boolalpha);

    // 完全等价于 std::chrono::seconds
    std::cout << "std_sec == std::chrono::seconds? "
              << std::is_same<std_sec, std::chrono::seconds>::value
              << std::endl;

    // 完全等价于 experiment::seconds
    std::cout << "my_sec == experiment::seconds? "
              << std::is_same<my_sec, experiment::seconds>::value
              << std::endl;

}