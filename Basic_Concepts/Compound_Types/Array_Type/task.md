# Array Type

Array Type (数组类型) 用于 Declare 一连串指定 Type 和 Length 的 Objects.

## Declaration Syntax

- *element-type* *noptr-declarator* [ *expr*<b>?</b> ] *attr*<b>?</b>

其中

- *element-type* 是数组元素的 Type
- *noptr-declarator* 是数组的名称
- *expr*<b>?</b> 是数组的 Length, 需要是 constexpr
- *attr*<b>?</b> 是 a list of attributions

Array 本质上是指定了 Length 的 Pointer.

## Array 的相关操作

`operator[](signed)` Subscript Operator (下表操作符),
- Operands (Input) 为目标 Index
- Return Value (Output) 为 Array 的第 Index 个 Object 的 Reference
