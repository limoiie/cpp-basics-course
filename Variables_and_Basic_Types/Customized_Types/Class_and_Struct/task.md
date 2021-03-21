# Class and Struct

Class 或 Struct (这两者在C++ 里的概念一致, 后续统一简称 class) 用于创建自定义 type.
通过 class, 可以将相关的一些 variables, 以及与这些 variables 关联紧密的 functions 组合在一起.
因此, class 也被称为 data structure.

## Declaration Syntax

可如下 define 一个 class:

- `struct` *declarator* {<br>
  &#20;&#20;&#20;&#20;*member-specification*<br>
  }
- `class` *declarator* {<br>
  &#20;&#20;&#20;&#20;*member-specification*<br>
  }

其中

- *declarator* 是 class's name
- *member-specification* 是 class's members

## Explanation

用 `class` 与 用 `struct` define 的 class 并无本质不同.
两者唯一区别是默认 
[member accessibility](course://Classes/Encapsulation/Access_Control)
不同:
- `struct` 默认 members 是 `public` 的
  [(*demo*)](psi_element://CustomizedTypesClass_Struct_Test);
- `class` 默认 members 是 `private` 的
  [(*demo*)](psi_element://CustomizedTypes_Class_Test).
