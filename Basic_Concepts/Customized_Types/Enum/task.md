# Enumeration

Enumeration (枚举) 可以将一组常量值组合起来形成一个更有意义的 Type.
C++ 提供两种 Enumeration: 
- UnScoped Enumeration 
  - e.g. `enum Enum {...}`
- Scoped Enumeration
  - e.g. `enum class Enum {...}`

顾名思义, UnScoped Enumeration 中的 Enumerator 可以直接访问;
而 Scoped Enumeration 的 Enumerator 需要加 Scope Qualifier 才可访问.
Scoped Enumeration 显而易见的好处是可以避免 *enumerator* 冲突.

## Declaration Syntax

两种 Enumeration 具体的 Syntax 如下所示: 

### Un-Scoped Enumeration

- `enum` *name*<b>?</b> { *enumerator* = *constexpr*<b>?</b>, ... }
- `enum` *name*<b>?</b> : *base-type* { *enumerator* = *constexpr*<b>?</b>, ... }
- `enum` *name*<b>?</b> : *base-type* ;

### Scoped Enumeration

- `enum` class *name*<b>?</b> { *enumerator* = *constexpr*<b>?</b>, ... }
- `enum` class *name*<b>?</b> : *base-type* { *enumerator* = *constexpr*<b>?</b>, ... }
- `enum` class *name*<b>?</b> : *base-type* ;
- `enum` class *name*<b>?</b>;

其中,

- *name* 即 Enumeration 的 Type 名称
- *base-type* 是 *enumerator* 的 Type, 被称为 Enumeration 的 Underlying Type;
  若 Underlying Type 未指定时, 默认是 Type `int`
- *enumerator* 即 Enumeration 的元素, 它的 Type 是 Enumeration 的 Underlying Type
- *constexpr* 是对应 *enumerator* 的值, 其 Type 是 Enumeration 的 Underlying Type;
  若该项未指定时, *enumerator* 的值默认从 `0` 开始, 后续每个 *enumerator* 的值都比前项大 `1`