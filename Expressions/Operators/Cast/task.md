# Type Conversion Operators

C++ 提供了 4 种新型的 cast operators: `static_cast`, `const_cast`, `reinterpret_cast`, `dynamic_cast`.
每一个 cast operator 都用于特殊的 conversion.

## `static_cast`

Operator `static_cast` 通过组合 implicit conversion 和 user-defined conversion 进行 type conversion.

## `const_cast`

Operator `const_cast` 用于在同一 type 的不同 
[cv-qualified versions](course://Variables_and_Basic_Types/Compound_Types/Const_Volatile_Qualifier)
间进行 conversion.

## `reinterpret_cast`

Operator `reinterpret_cast` 用于以 new type 对 object of old type 进行 reinterpreting.
与 operator `static_cast` 不同, operator `reinterpret_cast` 不会修改 old object of old type.

## `dynamic_cast`

Operator `dynamic_cast` 用于在 base type reference/pointer 和 derived type reference/pointer 间进行 conversions.