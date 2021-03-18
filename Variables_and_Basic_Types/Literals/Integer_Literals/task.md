# Integer Literal

C++ 支持十进制, 八进制, 十六进制以及二进制的 integer literal
[(*demo*)](psi_element://IntegerLiterals_Literals_Test).

同时, C++ 也允许通过添加 type suffix 的形式为 integer literal 指定 integer type
[(*demo*)](psi_element://IntegerLiterals_TypeSuffix_Test).

## Syntax of Literal *

详细的 syntax 如下所示:

1. *decimal-literal integer-suffix*
2. *octal-literal integer-suffix*
3. *hex-literal integer-suffix*
4. *binary-literal integer-suffix*

其中:

- *decimal-literal* 是一个非零 decimal digit (`1, 2, 3, 4, 5, 6, 7, 8, 9`) 
  再加上零个或多个 decimal digit (`0, 1, 2, 3, 4, 5, 6, 7, 8, 9`)
  - i.e. `10, 20, 921, ...`
- *octal-literal* 是一个零 (`0`) 再加零个或多个 octal digit (`0, 1, 2, 3, 4, 5, 6, 7`)
  - i.e. `010, 020, 00, 011, ...`
- *hex-literal* 是一个 `0x` 或 `0X` 前缀再加上一个或多个 
  hexadecimal digit (`0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, f, A, B, C, D, E, F`)
  - i.e. `0xff, 0x10, 0xdeadbeef, ...`
- *binary-literal* 是一个 `0b` 或 `0X` 前缀再加上一个或多个 binary digit (`0, 1`)
  - i.e. `0x00101, 0x1111, ...`
- *integer-suffix* 可选项; 若提供了的话, 会包含一个或两个如下后缀:
  - *unsigned-suffix* (the character `u` or the character `U`)
  - *size-suffix*
    - *long-suffix* (the character `l` or the character `L`)
    - *long-long-suffix* (the character sequence `ll` or the character sequence `LL`)
  - i.e. `10u, 10ul, 10ull, 10l, ...`
  
## Type of Literal *

如果一个 integer literal 指定了 *integer-suffix*, 那么它的 type 对应于 *integer-suffix*.
否则, 一个 integer literal 可以拥有许多候选 types, 而它真正的 type 是这些候选 types 中满足如下条件的那一个:
1. size 足够大, 大到可以容纳该 literal;
2. modified 程度最小, 也就是对 `int` 的 signedness 或 size 的修改程度最小

如 literal `10`, 它的候选 types 有 `short int`, `int`, `long int` 等等.
其中所有的 types 都可以容纳 `10`; 而对 `int` 而言 modified 程度最小的自然是 `int`.
因此, literal `10` 的 type 就是 `int`.

See more on [The Type of Integer Literal](https://en.cppreference.com/w/cpp/language/integer_literal#The_type_of_the_literal).