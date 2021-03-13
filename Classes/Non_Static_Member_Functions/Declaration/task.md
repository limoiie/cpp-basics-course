# Declaration

在 Class 的 member specification 中可以 declare 三种 functions:
- friend functions - function with a `friend` specifier
- static member functions - function with a `static` specifier
- non-static member functions - function without a `static` or a `friend` specifier 

Non-static member function 也简称为 member function.
一个 member function 的 declaration syntax 与 top-level function 一致.
除此之外, member function 还支持几种特有的 syntax elements [(*demo*)](psi_element://NonStaticMemberFunctions_Declaration_Test):
- cv qualifiers - `const`, `volatile` and `const volatile`
- ref qualifiers - `&` and `&&`
- virtual and pure specifiers - `virtual`
- final and override specifiers - `final` and `override` 

其中后两种是与 object-oriental programming 相关的技术, 将放到 [lesson Object Oriental Programming](course://Classes/Object_Oriental) 中. 
本 lesson 只介绍前两种 syntax elements.

按照功能, 可归类几种特殊的 member functions:
- constructor
  - default constructor
  - copy constructor
  - move constructor
  - other
- member operator function
  - copy assignment operator
  - move assignment operator
  - other
- destructor
