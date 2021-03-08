# A Simple Class

当 Primitive Type 满足不了日常需求时, C/C++ 支持用 Keyword `class` 和 `struct` 自定义 Type.
这样的 Type 被称为 Compounded Data Type (组合数据类型), 或 Class (类).

**Create:** Class 由一组 Member Variable 和一组可以访问它自己的 Member Function 组成, 如右所示.
使用 Class 的方式与正常 Type 一样, 可以直接构造 Object;
也可以使用 Operator `new` 创建 Object 并返回指向该 Object 的 Pointer.

**Access:** 对于 Object, 可以用 Member Access Operator `operator.` 以 `a.member` 的形式访问其内部的 Members;
而对于 Pointer, 可以用 Member Access Operator `operator->` 以 `p_a->member` 的形式访问其内部的 Members.
<br><br>

## `class` VS `struct`

`class` 和 `struct` 的唯一区别是, 它们默认的 Member Access Level 不同:
`class` 默认所有的 Member 都是 `private` 的, 而 `struct` 默认所有的 Member 都是 `public` 的.

```c++
// 1. struct <==> class + public:
struct A {
    // ...
};
// equivalent to
class A {
public:
    // ...
};

// 2. class <==> struct + private:
class B {
    // ...
};
// equivalent to 
struct {
private:
    // ...
};
```