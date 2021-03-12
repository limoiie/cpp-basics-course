# Class and Struct

Class 或 Struct (C++ 里这两者概念一致, 后续统一简称 Class) 用于创建自定义 Data Structure (数据结构).
通常意义上, Data Structure 是将一些相关数据和操作该相关数据的逻辑组合在一起的一种手段.

C++ 提供 Keywords `class` 和 `struct` 专门用于 Declare 和 Define 一个 Class.

## Declaration Syntax

- `class` *declarator*
- `struct` *declarator*

其中

- *declarator* 是 Class 或 Struct 的名称

## Explanation

用 `class` 与 用 `struct` Declare 的 Class 并无本质不同.
两者唯一区别是默认 Member Accessibility 不同: 
`class` 默认是 `private` 而 `struct` 默认是 `public`.

每一个 Class 就是一个独一无二的 Type, 使用 Class 如同使用其他 Type 一样.
