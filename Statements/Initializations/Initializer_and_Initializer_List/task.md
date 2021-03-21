# Initializer

Initialization 发生在 object construction 期间, 通过指定 initializer 的方式来为 object 提供 initial value. 

## Syntax of Initializer

Initializer 有如下几种形式:

1. ( *braced-init-list* )
2. = *expression'*
3. { *braced-init-list* }
4. = { *braced-init-list* }

其中:

- *expression'* 是除了 *braced-init-list* 以外的 expression
- *braced-init-list* 是以逗号为分割的一列 *braced-init*
- *braced-init* 是 *expression'* 或 *braced-init-list*

## Various Initialization

为了提高 initialization 的可拓展性, 同时使得调用方式更为灵活和简洁, C++ 提供了一套相对复杂的 initialization 机制.
在不同的 context 下, 即使使用相同 syntax 的 initializer, 也会触发不同的 initialization strategy:

- [Default initialization](course://Statements/Initializations/Default_Initialization)
  - 没有 initializer 时 
- [Value initialization](course://Statements/Initializations/Value_Initialization)
  - 当 initializer 为空时, 即 initializer 为 `()` 或 `{}` 时
- [Direct initialization strategy](course://Statements/Initializations/Direct_Initialization)
  - 当 initializer 匹配 syntax 1 或 syntax 3 时
- [Copy initialization](course://Statements/Initializations/Copy_Initialization)
  - 当 initializer 匹配 syntax 2 或 syntax 4 时
- [List initialization](course://Statements/Initializations/List_Initialization)
  - 当 initializer 匹配 syntax 3 或 syntax 4 且 arg type 是 `std::initializer_list` 时
- [Aggregate initialization](course://Statements/Initializations/Aggragate_Initialization)
  - 当 initializer 匹配 syntax 3 或 syntax 4 且 arg type 是 aggregate type 时
