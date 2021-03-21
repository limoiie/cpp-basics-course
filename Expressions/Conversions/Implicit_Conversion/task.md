# Implicit Conversion

Implicit Conversion (隐式转换) 发生于这样一种情况下:
type `T1` 的 expression 用在了接收 type `T2` (而不接收 type `T1`) 的 context 中.

## Use Case of the Conversions

特别地, implicit conversion 会在下列情况下自动发生:

1. 当 type `T1` expression 用作 argument/operand 而对应 function/operator 接收 type `T2` 时
   [(*demo*/](psi_element://ImplicitConversion_WhenAsArguemnt_Test)[*demo*)](psi_element://ImplicitConversion_WhenAsOperand_Test);
2. 当 type `T1` expression 用于 initialize object of type `T2` 时
   [(*demo*)](psi_element://ImplicitConversion_WhenInitializeWithOtherType_Test);
3. 当 type `T1` expression 用作 if 和 loop statement 的条件时 (type `T2` 将为 `bool`)
   [(*demo*)](psi_element://ImplicitConversion_WhenInSwitchCondition_Test)

若想上述 implicit conversion 能够被正确编译, 那么从 type `T1` 到 `T2` 必须存在一个 unambiguous implicit conversion sequence, 有关代码才会被正确编译.

## Order of the Conversions *

由于 C++ 支持众多 type 间的 conversion, 同时也允许 coder 以多种方式实现 user-defined conversion, 所以需要一个确定的 conversion sequence 以确保整个
conversion 有迹可循.

C++ 内置有 standard conversion sequence, 同时也支持 user-defined conversion sequence. 为了尽可能的支持更多的 conversion, 完整的 implicit
conversion sequence 如下按顺序组成:

1. zero or one standard conversion sequence;
2. zero or one user-defined conversion;
3. zero or one standard conversion sequence.
