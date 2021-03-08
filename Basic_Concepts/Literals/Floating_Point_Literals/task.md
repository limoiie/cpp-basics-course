# Floating Point Literals

## Syntax

Floating Point Literals 用于表示小数, 还支持使用科学记数法表示.
其有如下几种形式:

1. *digit-sequence exponent suffix*<strong>?</strong>
2. *digit-sequence . exponent*<strong>?</strong> *suffix*<strong>?</strong>
3. *digit-sequence*<strong>?</strong> *. digit-sequence exponent*<strong>?</strong> *suffix*<strong>?</strong>

其中:

- *digit-sequence* 由一个或多个 Decimal Digit (`0, 1, 2, 3, 4, 5, 6, 7, 8, 9`) 组成
- *exponent* 是科学记数法部分, 它有如下形式:
  - **e**|**E** *exponent-sign*<strong>?</strong> *digit-sequence*
- *suffix* 是 Type Suffix, 表示着该 Literal 的 Type
  - (no suffix) 意味着 `double`
  - `f` 或 `F` 意味着 `float`
  - `l` 或 `L` 意味着 `long double`
- **?** 表示该部分为可选部分, 可有可无

## Explanation

上述几种形式对应的例子如下:

1. *digit-sequence exponent suffix*<strong>?</strong>
    ```c++
    10e10L, 10e-5, ...
    ```
2. *digit-sequence . exponent*<strong>?</strong> *suffix*<strong>?</strong>
    ```c++
    10.e10L, 10., 10.F, ...
    ```
3. *digit-sequence*<strong>?</strong> *. digit-sequence exponent*<strong>?</strong> *suffix*<strong>?</strong>
    ```c++
    10.10e5L, .10, .10L, ...
    ```
