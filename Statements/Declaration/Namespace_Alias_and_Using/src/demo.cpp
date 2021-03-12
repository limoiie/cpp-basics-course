#include "demo.h"

namespace ns_outer
{
    int v_in_outer;

    namespace ns_inner
    {
        int v_in_inner;
    }

    struct class_in_ns {};

    void foo() {
        std::cout << "call foo()" << std::endl;
    }
}

DEMO(NamespaceAliasUsing, UseNamespace) { // NOLINT(cert-err58-cpp)

    using namespace ns_outer; // 现在, 可以直接使用 ns_outer 里可见的 names

    v_in_outer = 10; // variable in ns_outer
    foo(); // function in ns_outer
    class_in_ns a = class_in_ns(); // class in ns_outer
    ns_inner::v_in_inner = 20;

    std::cout << v_in_outer << ", " << ns_inner::v_in_inner << std::endl;

}

DEMO(NamespaceAliasUsing, UseName) { // NOLINT(cert-err58-cpp)

    using ns_outer::v_in_outer; // 现在, 可以直接使用 ns_outer 里的 v_in_outer

    v_in_outer = 10; // v_in_outer 可直接使用
    // ns_inner::v_in_inner = 20; // error: ns_inner 当前不可见

    std::cout << v_in_outer << ", "
              // << ns_inner::v_in_inner // error: ns_inner 当前不可见
              << std::endl;

}

DEMO(NamespaceAliasUsing, NamespaceAlias) { // NOLINT(cert-err58-cpp)

    namespace ns = ns_outer::ns_inner; // 现在, 可用 ns 代替 ns_outer::ns_inner

    ns::v_in_inner = 10; // ns is equivalent to ns_outer::ns_inner

}

DEMO(NamespaceAliasUsing, TypeInNamespaceAlias) { // NOLINT(cert-err58-cpp)

    using cls = ns_outer::class_in_ns; // 现在, 可用 cls 代替 ns_outer::class_in_ns

    cls c = cls();

    std::cout.setf(std::ios_base::boolalpha);

    std::cout << "cls == ns_outer::class_in_ns? "
              << std::is_same<cls, ns_outer::class_in_ns>::value << std::endl;

}
