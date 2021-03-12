# Pointer Type

Pointer Type (指针类型) 由任意 Type 加上一个 `*` 组成.
这个任意 Type 被称为 Element Type, Pointer 可以用来指向一个 Element Type 的 Object.

## Syntax

Pointer 本身是一个 Pointer Type 的 Variable, 值为其所指 Object 所在的 Memory Address.
Pointer 不仅可以指向外部的 Object, Function, 还可以指向 Object 内部的 Member Variables 和 Member Functions.

- *element-type* <b>*</b> *attr*<b>?</b> *cv*<b>?</b> *declarator*
- nested-name-specifier *element-type* <b>*</b> *attr*<b>?</b> *cv*<b>?</b> *declarator*

其中, 
- *element-type* 是 Pointer 所指向的 Type
- *attr*<b>?</b> 是 a list of attributes
- *cv*<b>?</b> 是 qualifier `const/volatile`

## Pointer 相关的 Operator

与 Pointer 相关的 Operator 有四种: `operator&(T&)`, `operator*()`, `operator->()` 以及 `operator[](unsigned)`.

`operator&(T&)` 被称为 Address-Of Operator (取地址操作符), 
- Operand (Input) 为一般 *lvalue*
- Return Value (Output) 是指向 *lvalue* 的 Pointer

`operator*()` 被称为 Dereference Operator (解引用操作符),
- Return Value (Output) 是 Pointer 所指的对象的一个 Reference

`operator->()` 被称为 Member-of-Pointer Operator (指针成员操作符); 
当 Operator 指向的 Object 有 Members 时, 可用该 Operator 直接访问其 Members

`operator[](unsigned)` 被称为 Subscript Operator (下标操作符),
- Operand (Input) 为索引 Index
- Return Value 是 - 从 Pointer 所指 Address 开始, 以 Pointer 所指 Object 的 Size 为单位, 第 Index 个 Object 的 Reference