# Fundamental Types

Type (类型) 用来修饰一块 memory space (内存空间).
它赋予 memory 以涵义, 告诉 compiler (编译器) 应该以怎样的方式来对待被修饰的 memory.
如果没有 type, memory 将是一条杂乱无章的 `01` 序列.

C++ 语言原生地支持如下 fundamental types (基础类型):

- Integer Types (整数类型)
- Boolean Type (布尔类型)
- Character Types (字符类型)
- Floating Point Types (浮点数类型)
- Auto Type (自动类型)

利用这些 fundamental types, 程序员可以构建各种复杂的、具有特殊性质的
[customized types](course://Variables_and_Basic_Types/Customized_Types).

更多阅读：
[cppreference#types](https://en.cppreference.com/w/cpp/language/types),

<!--
  > - `std::nullptr_t`: 还记得 C 里 Null Pointer_Type 的值为 `NULL` (实际上是一个值为 0 的宏定义) 吗?
  > C++ 里已用一个全新的关键字 `nullptr` 来替代它。
  > 而 `std::nullptr_t` 就是 `nullptr` 的 Type.
-->
