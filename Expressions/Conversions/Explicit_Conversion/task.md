# Explicit Conversion

Explicit conversion (显式转换).
显式地调用 cast expression (C-style or C++-style or functional) 进行的 conversion 就是 explicit conversion.
而若想 cast expression 能够成功地被 compiled, 
那么从 old type 到 new type 之间一定要存在对应的 
[standard conversion sequence](course://Expressions/Conversions/Standard_Conversion) 或
[user-defined conversion sequence](course://Expressions/Conversions/User_Defined_Conversion).

## Syntax of Cast Expression

有如下三种 cast expressions:

1. **(** *new_type* **)** *old_type_expression*
2. *new_type* **(** *old_type_expression* **)**
3. *cxx_cast_operator<* *new_type* `>` **(** *old_type_expression* **)**

其中:

- *new_type* 是目标 type
- *old_type_expression* 是被转换的 expression
- *cxx_cast_operator* 是 C++ 支持的 
  [cast operator](course://Expressions/Operators/Cast):
  - `static_cast`
  - `const_cast`
  - `reinterpret_cast`
  - `dynamic_cast`
    
## Explanation

1. **(** *new_type* **)** *old_type_expression*
   - C-style cast expression
    [(*demo*)](psi_element://ExplicitConversion_CStyleCast_Test)
    
2. *new_type* **(** *old_type_expression* **)**
   - functional cast expression
    [(*demo*)](psi_element://ExplicitConversion_FunctionalCast_Test)
    
3. *cxx_cast_operator<* *new_type* `>` **(** *old_type_expression* **)**
   - C++-style cast expression
    [(*demo*)](psi_element://ExplicitConversion_CppStyleCast_Test)
