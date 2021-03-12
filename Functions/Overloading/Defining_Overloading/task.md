# Defining Overloaded Functions

那些在同一个 scope、拥有相同 name<sup>1</sup>、但 parameter lists 却不相同的 functions 被称为 overloaded functions.
在 overloaded function 的 call-site (调用处), compiler 会根据 parameter-list 来寻找相匹配的那个 function [(*demo*)](psi_element://Overloading_Function_Test).

请注意: 两个仅有 return type 不同的 functions 不能 overloaded, 它们会被视为 redefinitions.

<sup>1</sup>:
等等, 不是说在同一 scope 中不可 define 两个相同的 names 吗?
其实两个 overloaded functions 看似 name 相等, 但在 compilation 期间 compiler 会根据每个 function 的 name 和 parameter list 为其生成一个 extended name 来替代原有的 name.
比如 function `foo(int, int)` 在 compilation 时的 extended name **可能**是 `foo__int_int` (而不是 foo).