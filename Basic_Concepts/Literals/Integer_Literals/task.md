# Integer Literal

## Syntax

一个 Integer Literal 有如下几个形式:

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
  - one of 
    - *long-suffix* (the character `l` or the character `L`)
    - *long-long-suffix* (the character sequence `ll` or the character sequence `LL`)
  - i.e. `10u, 10ul, 10ull, 10l, ...`


## The Type of the Literal

一个 Integer Literal 的值可以用来 initialize 多个 Types, 如 `10` 可以 initialize `int, long int, long long int`.
而该 Literal 的 Type 就是这些个 Type 中 Modified 程度最小的那一个, 如 `10` 的 Type 就是 `int`.

详尽的 The Type of the Literal 信息请参照 [The Type of Integer Literal](https://en.cppreference.com/w/cpp/language/integer_literal#The_type_of_the_literal).