# Type Alias

Type alias (类型别名) is a name that refers to a previously defined type.
C++11 前常用 specifier `typedef` 来创建 type alias, 之后则建议用新引入的 keyword `using` 来替代 `typedef`.
本文也只介绍后者 keyword `using`.

## Syntax

1. `using` *new-type-name* *attr*<b>?</b> `=` *old-type-name*
2. `template<`*template-parameter-list*`>`<br>
  `using` *new-type-name* *attr*<b>?</b> `=` *old-type-name*


其中,

- *old-type-name* 
  是原有的 type name, 该 type 需要在当前的 scope 可见;
  必要时需要加上 namespace qualifier
- *new-type-name* 
  是新的 type alias, 用来表示原有的 *old-type-name*;
  *new-type-name* 与 *old-type-name* 完全等价

注 syntax 2 请见 [cppreference#type_alias](https://en.cppreference.com/w/cpp/language/type_alias).