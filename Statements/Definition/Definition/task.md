# Variable Definition

通常情况下, definition 可以看作是由 declaration 和 initialization 构成的: 
declaration 向 C++ program 中引入新的 names, initialization 为这些新的 names 提供初始值.

## Syntax

1. *specified-type* *init-declarator* ;
2. *specified-type* *init-declarator-list* ;

其中,
- *specified-type* 是一个 specified 后的 type; specifiers 即 `constexpr`, `const`, `volatile`, 等
- *init-declarator* 由 declarator 和 initializer (可选项) 构成:
  - *declarator* *initializer*<b>?</b>
- *init-declarator-list* 是一个由逗号隔开的 *init-declarator* 序列
  
## Explanation

1. *specified-type* *init-declarator* ; define 了一个 type 为 *specified-type* 的 variable
    - e.g. `std::string s = "a short sentence";`
2. *specified-type* *init-declarator-list* ; 同时 define 了多个 type 为 *specified-type* 的 variables
    - e.g. `int a, b = 10, c(10), d{10};` 