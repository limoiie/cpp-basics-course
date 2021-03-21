# User Defined Conversion

C++ 支持 coder 定义自己的 conversion 实现, 一共有两种形式:

- [user-defined conversion function](course://Functions/Operator_Functions/Overload_Type_Conversion_Operators)
   - member operator, 支持将 operator 所在的 class type 转成其他指定 type
- [conversion constructor](course://Classes/Constructors/Conversion_Constructors)
   - member constructor, 支持将其他 type 转成 constructor 所在的 class type
