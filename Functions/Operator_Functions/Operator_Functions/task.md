# Operator Functions

还记得 [lesson Operators](course://Basic_Concepts/Operators) 里介绍的各种 operators 吗?
它们就是一些有着特殊 names 的 functions, 如同 functions 一样处理输入、返回输出.

## Syntax

在 C++ 里, operator names 一共有如下几种 syntax:

1. `operator` *op*
2. `operator` *type*
3. `operator new` <br>
   `operator new` *[]*
4. `operator delete` <br>
   `operator delete` *[]*
5. `operator ""` *suffix-identifier*

## Explanation

对应不同的 syntax, 它们的用途也有所不同:

1. 是 computing operators
2. 是 type-conversion operators
3. 是 allocation operators
4. 是 de-allocation operators
5. 是 literal operators

## Overloading and Restrictions

既然是 functions, 那么 operators 也可以像 functions 一样被 overloaded.
在 overload 这些 operators 时, 要保证至少有一个 operand 是 class type 或 enumeration type 的.
