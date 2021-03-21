# Array Type

Array type (数组类型) 用于创建一连串指定 type 和 length 的 objects
[(*demo*)](psi_element://CompoundTypesArray_Array_Test).
Objects in an array 拥有相同的 type.

Array 本质上就是指定了 length 的 pointer
[(*demo*)](psi_element://CompoundTypesArray_ArrayAndPointer_Test).

## Syntax of Declaration

- *element-type* *noptr-declarator* [ *expr*<b>?</b> ] *attr*<b>?</b>

其中

- *element-type* 是 array 元素的 type
- *noptr-declarator* 是 array 的 name
- *expr*<b>?</b> 是 array 的 length, 可以是 expression 但必须是 constexpr
- *attr*<b>?</b> 是 a list of attributions

## Array Related Operators

`operator[](signed)` subscript operator (下标操作符),
- operands (input) 为目标 index
- return value (output) 为 array 的第 index 个 object 的 lvalue-reference
