# Overload Literal Operators

User-defined literals 允许我们以一种很直观的 literal-like 的方式创建 target class type 的 object.
为了实现 user-defined literals, 我们需要为 target class type 来 overload 相应的 literal operators.

## User-Defined Literals

### Syntax

一个 User-defined literal 的 syntax 是 raw literals 后接 user-defined suffix.
具体地:

1. *decimal-literal* *ud-suffix*
2. *octal-literal* *ud-suffix*
3. *hex-literal* *ud-suffix*
4. *binary-literal* *ud-suffix*
5. *floating-point-literal* *ud-suffix*
6. *character-literal* *ud-suffix*
7. *string-literal* *ud-suffix*

其中:

- *\*-literal* 是 [lesson Literals](course://Basic_Concepts/Literals) 里介绍的各种 raw literals
- *ud-suffix* 是一个 identifier, which is defined by literal operator.

## Literal Operators

### Syntax

Literal operator 的 declaration 有两种形式:
1. *type* `operator ""` *identifier1* (*parameter-list*) `{...}` [(*demo*)](psi_element://OverloadLiteralOperators_LiteralOperators_Test)
2. *type* `operator ""`*identifier2* (*parameter-list*) `{...}`

注意 syntax 1 中 `""` 与 *identifier1* 之间有空格, 而 syntax 2 中 `""` 与 *identifier2* 之间紧挨着.
其中:

- *type* 是 target class type
- *identifier1* 必须以 underscore `_` 开始, 将被用作 user-defined literals 里的 *ud-suffix*;
  另外, `_` 后不能仅跟 uppercase character (如 `_A`), 这类 suffix 是 reserved
- *identifier2* 与 *identifier1* 基本一致, 除了 *identifier2* 可以是 reserved (即 `_A`)
- (*parameter-list*) 用于接收 user-defined literal 中的 raw literal 部分, 只能是如下几种形式:
  - `(const char *)`
  - `(unsigned long long int)`
  - `(long double)`
  - `(char)`
  - `(wchar_t)`
  - `(char16_t)`
  - `(char32_t)`
  - `(const char *, std::size_t)`
  - `(const wchar_t *, std::size_t)`
  - `(const char16_t *, std::size_t)`
  - `(const char32_t *, std::size_t)`

那些不以 underscore `_` 开始的 *suffix* 只能在 standard library headers 中使用

### Explanation

Syntax 1 与 Syntax 2 的区别是 `""` 与 *identifier* 之间是否有空格.
有空格, 那么 *identifier* 就得符合 *identifier1* 的定义;
否则, *identifier* 就是 *identifier2*.
