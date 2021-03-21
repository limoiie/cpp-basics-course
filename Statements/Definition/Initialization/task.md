# Initializer

Initialization 发生在 object construction 期间, 它通过为 declaration 添加 initializer 来实现.

## Syntax

initializer

1. ( *expression-list* )
2. = *expression*
3. { *initializer-list* }

## Various Initialization

为了提高 initialization 的可拓展性, 同时使得调用方式更为灵活和简洁, C++ 提供了一套相对复杂的 initialization 机制.
在不同的 context 下, 即使使用相同 syntax 的 initializer, 也会触发不同的 initialization strategy:

- Value initialization strategy
  - 当 initializer 为空时, 即 initializer 为 `()` 或 `{}` 时
- Direct initialization strategy
  - 调用参数匹配的 constructor
- Copy initialization strategy
  - 调用 copy constructor
- List initialization strategy
  - 当 type 有 initializer_list constructor 时
- Aggregate initialization strategy
  - 当 type 是 aggregate type 时<br>
    而 aggregate type 是 
    - array Type, 或是
