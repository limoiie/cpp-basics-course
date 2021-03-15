# Overload Type Conversion Operators

Type conversion operators 支持 implicitly (隐式地) 或 explicit (显式地) 将一个 class type 转换成另一种 type.
这些 operators **必须**被 declare 成 source class type 的 non-static member functions, 

注意: type conversion operators 是将当前 class type 转成 target type.
若要实现将其他 source type 转成当前 class type, 请见 [Conversion Constructor](course://Classes/Constructors/Conversion_Constructors). 

## Syntax

C++ 支持如下两种 overload 的 syntax:

1. `operator` *target-type-id*
2. `explicit operator` *target-type-id*

## Explanation

1. `operator` *target-type-id* [(*demo*)](psi_element://OverloadTypeConversioinOperators_Implicit_Test)<br>
   该 overload 同时支持 implicit conversion 和 explicit conversion
2. `explicit operator` *target-type-id* [(*demo*)](psi_element://OverloadTypeConversioinOperators_Explicit_Test)<br>
   该 overload 仅支持 explicit conversion 
