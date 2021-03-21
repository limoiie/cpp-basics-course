# Union

Union 是一种特殊的 class, 它在同一时刻只能持有一个 member variable 的值.
具体来说, 它的每个 member variable 都起始于同一 address, 共享 address 处的 memory; 
调用 union 的某个 member variable, 实际上是以那个 variable 的 type 来解读这块 memory.

## Syntax

- `union` *class-head-name* {<br>
  &#20;&#20;&#20;&#20;*member-specification*<br>
  }

其中 

- *attr* 是 a list of attributes
- *class-head-name* 是 union 的 type name
- *member-specification* declare 了 union 的各种 members:
  - member variable with non-reference type
  - member function
  - static member variable
  - static member function
  
值得注意的是, union 不可以有 base class 而且不能作为 base class.