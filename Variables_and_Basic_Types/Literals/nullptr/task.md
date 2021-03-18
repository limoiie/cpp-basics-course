# `nullptr`

`nullptr` 是一个十分特殊的 literal, 表示任意 type 的 null pointer
[(*demo*)](psi_element://Nullptr_Nullptr_Test).

传统 C 语言里用 macro `NULL` 表示 null pointer:
```c++
#define NULL (void *) 0
```

而在 C++ 里 `NULL` 却有可能优先被解释为 integer 0.
这极易造成混淆
[(*demo*)](psi_element://Nullptr_ambiguous_Test), 降低代码可读性, 并且容易埋下安全隐患.

为了将 pointer 和 integer 区分开, C++11 引入了特殊的 keyword `nullptr` 来代替 `NULL` .
与 `NULL` 不同, `nullptr` 永远都是一个 pointer ([NULL vs nullptr (Why was it replaced?)](https://stackoverflow.com/a/20509811/11192045)).
