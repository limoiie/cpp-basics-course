# Pointer Type

Pointer type (指针类型) 由任意 type 加上一个 `*` 组成
[(*demo*)](psi_element://CompoundTypesPointer_Pointer_Test).
`type *` 中的 `type` 也被称为 target type, 而 pointer 主要用来指向一个 target type 的 object.

Pointer 本身是一个 pointer type 的 variable, 值为 memory address of the pointed object.
Pointer 不仅可以指向外部的 object, function, 还可以指向 object 内部的 member variables 和 member functions
[(*demo*)](psi_element://CompoundTypesPointer_Targets_Test).

## Syntax

Pointer 具体的 syntax 如下所示:

- *target-type* <b>*</b> *attr*<b>?</b> *cv*<b>?</b> *declarator*
- nested-name-specifier *target-type* <b>*</b> *attr*<b>?</b> *cv*<b>?</b> *declarator*

其中, 
- *target-type* 是 pointer 所指向的 type
- *attr*<b>?</b> 是 a list of attributes
- *cv*<b>?</b> 是 qualifier `const/volatile`
- *declarator* 是 pointer name

## Pointer Related Operators

与 Pointer 相关的 Operator 有四种:

`operator&(T&)`
[(*demo*)](psi_element://CompoundTypesPointer_OperatorAddressOf_Test)
- 被称为 address-of operator (取地址操作符)
- operand (input) 为一般 *lvalue*
- return value (output) 是指向 *lvalue* 的 pointer

`operator*()`
[(*demo*)](psi_element://CompoundTypesPointer_OperatorDereference_Test)
- 被称为 dereference operator (解引用操作符)
- return value (output) 是 pointer 所指的对象的一个 reference

`operator->()`
[(*demo*)](psi_element://CompoundTypesPointer_OperatorMemberAccess_Test) 
- 被称为 member-of-pointer operator (指针成员操作符);
  当 operator 指向的 object 有 members 时, 可用该 operator 直接访问其 members

`operator[](unsigned)`
[(*demo*)](psi_element://CompoundTypesPointer_OperatorSubscript_Test)
- 被称为 subscript operator (下标操作符)
- operand (input) 为索引 index
- return value 是从 pointer 所指 address 开始, 以 pointer 所指 object 的 size 为单位, 第 index 个 object 的 reference
