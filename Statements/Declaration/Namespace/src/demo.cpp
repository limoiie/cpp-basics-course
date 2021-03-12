#include "demo.h"

#pragma region DEMO_BEGIN

namespace ns_someone
{
    int x;

    struct A {
        int x;
    };
}

DEMO(Namespace, Namespace) { // NOLINT(cert-err58-cpp)

    // access the name in namespace ns_name by ns_name::name
    std::cout << ns_someone::x << std::endl;

    ns_someone::x = 20;

    std::cout << ns_someone::x << std::endl;

    ns_someone::A a = ns_someone::A();
    a.x = 30;

    std::cout << a.x << std::endl;

}

#pragma endregion

#pragma region DEMO_BEGIN

inline namespace ns_global_inline
{
    int global_v;
}

namespace ns_outer
{
    inline namespace ns_inner_inline
    {
        int inner_v;
    }
}

DEMO(Namespace, InlineNamespace) { // NOLINT(cert-err58-cpp)

    // inline namespace 里的 names 对 enclosing namespace 可见

    // namespace ns_global_inline 没有 enclosing namespace, 默认导入 global
    global_v = 10;
    ns_global_inline::global_v = 20; // 正常方式访问也可以

    // namespace ns_outer::ns_inner_inline 的 enclosing namespace 是 namespace ns_outer
    ns_outer::inner_v = 10;
    ns_outer::ns_inner_inline::inner_v = 20; // 正常方式访问也可以

}

#pragma endregion

#pragma region DEMO_BEGIN

namespace // anonymous
{
    int v_in_anonymous_ns;
}

namespace ns_outer
{
    namespace // anonymous
    {
        int v_in_nested_anonymous_ns;
    }
}

DEMO(Namespace, AnonymousNamespace) { // NOLINT(cert-err58-cpp)

    // anonymous namespace 里的 names 对 enclosing namespace 可见

    v_in_anonymous_ns = 10; // 没有 enclosing namespace, 默认导入 global scope
    ns_outer::v_in_nested_anonymous_ns = 20; // enclosing namespace 是 namespace ns_outer

}

#pragma endregion
