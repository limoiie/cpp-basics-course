# `nullptr`

`nullptr` 是一个十分特殊的 Literal, 表示 Null Pointer.

传统 C 语言里用 Macro `NULL` (`#define *NULL* 0`) 表示 Null Pointer, 
但是为了将 Pointer 和普通的 Object 区分开, C++11 引入了这一个特殊的 keyword 来代替 `NULL`.