# Union

Union 是一种特殊的 Class, 它在同一时刻只能持有一个 Member Variable 的值.
具体来说, 它的每个 Member Variable 都起始于同一 Address, 共享 Address 处的 Memory; 
调用 Union 的某个 Member Variable, 实际上是以那个 Variable 的 Type 来解读这块 Memory.

## Syntax

- `union` *attr*<b>?</b> *class-head-name* { *member-specification* }

其中 

- *attr* 是 a list of attributes
- *class-head-name* 是 Union 的 Type 名称
- *member-specification* 是 Union 的各种 Member:
  - Member variable with non-reference type
  - Member function
  - Static member variable
  - Static member function
  
值得注意的是, Union 不可以有 Base Class 而且不能作为 Base Class.