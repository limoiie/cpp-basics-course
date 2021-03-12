# Block Scope

在 function 内部的 `{}` 所包裹起来的区域就是 block scope.

在 block scope 中 declared 的 name 的 potential name-scope 从 declaration 所在的点开始、直到 block scope 末尾结束.

为什么是 **potential** name-scope 呢?
这是因为 name-scope 可能会被 nested block scope 中的 declaration of identical name 所截断[(*demo*)](psi_element://BlockScope_BlockScope_Test).
其他情况下, actual name-scope 一般与 potential name-scope 保持一致.

根据定义, 如 statement `if`, `while`, `for`, `switch` 等后接的 `{}` 都属于 block scope [(*demo*)](psi_element://BlockScope_ControlBlockScope_Test).
值得注意的是, loop statements 如 `while`, `for` 的 block scope 在每次循环前都会开始一次, 并在每次循环后都会结束一次.
这意味着在循环体内 define 的 variables 在每次循环结束后都会被销毁.
因此, 尽量不要在循环体内 define 消耗资源的 variable.

而在 statement `if`, `for`, `switch` 的 non-block scope 区域 declare 的 variables 将在整个 statement 完成时才被销毁 [(*demo*)](psi_element://BlockScope_OutOfControlBlockScope_Test).