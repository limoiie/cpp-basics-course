# Standard Conversion

C++ 提供了众多 standard conversions 用于 
[fundamental type](course://Variables_and_Basic_Types/Fundamental_Types)
间的 conversions.

为了尽可能支持更多的 conversion, C++ 支持分多步进行 conversions.
这个多步 conversion 组合起来就被称为 *conversion sequence*. 

Standard conversion sequence 如下按顺序组成:
1. zero or one conversion from the following set
    - [lvalue-to-rvalue conversion](https://en.cppreference.com/w/cpp/language/implicit_conversion#Lvalue_to_rvalue_conversion)
    - [array-to-pointer conversion](https://en.cppreference.com/w/cpp/language/implicit_conversion#Array_to_pointer_conversion)
    - [function-to-pointer conversion](https://en.cppreference.com/w/cpp/language/implicit_conversion#Function_to_pointer)
2. zero or one [numeric promotion or numeric conversion](https://en.cppreference.com/w/cpp/language/implicit_conversion#Numeric_promotions);
3. zero or one [qualification conversion](https://en.cppreference.com/w/cpp/language/implicit_conversion#Qualification_conversions)
