# Enumeration

Enumeration (枚举) 可以将一组常量值组合起来形成一个更有意义的 type.
C++ 提供两种 enumerations: 
- unscoped enumeration [(*demo*)](psi_element://CustomizedTypesEnum_UnscopedEnum_Test)
  - e.g. `enum Enum {...}`
- scoped enumeration [(*demo*)](psi_element://CustomizedTypesEnum_ScopedEnum_Test)
  - e.g. `enum class Enum {...}`

顾名思义, unscoped enumeration 中的 enumerator 可以直接访问;
而 scoped enumeration 的 enumerator 需要加 scope qualifier 才可访问.
scoped enumeration 显而易见的好处是可以避免 *enumerator* 冲突.

## Declaration Syntax

两种 enumerations 具体的 syntax 如下所示: 

### Un-Scoped Enumeration

1. `enum` *name*<b>?</b> {<br>
  &#20;&#20;&#20;&#20;*enumerator* = *constexpr*<b>?</b>, ...<br>
  }
2. `enum` *name*<b>?</b> : *base-type* {<br>
  &#20;&#20;&#20;&#20;*enumerator* = *constexpr*<b>?</b>, ...<br>
  }

### Scoped Enumeration

1. `enum class` *name* {<br>
  &#20;&#20;&#20;&#20;*enumerator* = *constexpr*<b>?</b>, ...<br>
  }
2. `enum class` *name* : *base-type* {<br>
  &#20;&#20;&#20;&#20;*enumerator* = *constexpr*<b>?</b>, ...<br>
  }

其中,

- *name* 即 enumeration 的 type name
- *base-type* 是 *enumerator* 的 type, 被称为 enumeration 的 underlying type;
  若 underlying type 未指定时, 默认是 type `int`
- *enumerator* 即 enumeration 的元素, 它的 type 是 enumeration 的 underlying type
- *constexpr* 是对应 *enumerator* 的值
  [(*demo*)](psi_element://CustomizedTypesEnum_Constexpr_Test),
  其 type 是 enumeration 的 underlying type;
  若该项未指定时, *enumerator* 的值默认从 `0` 开始, 后续每个 *enumerator* 的值都比前项大 `1`