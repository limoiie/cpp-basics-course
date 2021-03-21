# Union

Union 是一种特殊的 class, 它在同一时刻只能持有一个 member variable 的值.
具体来说, 它的每个 member variable 都起始于同一 address, 共享 address 处的 memory;
调用 union 的某个 member variable, 实际上是以那个 variable 的 type 来解读这块 memory
[(*demo*)](psi_element://CustomizedTypesUnion_MembersWithSameAddress_Test).

## Syntax

- `union` *class-head-name*<b>?</b> {<br>
  &#20;&#20;&#20;&#20;*member-specification*<br>
  }

其中,

- *attr* 是 a list of attributes
- *class-head-name* 是 union 的 type name
- *member-specification* declare 了 union 的各种 members:
  - member variable with non-reference type
  - member function
  - static member variable
  - static member function
  
Union 有如下性质:

1. union 的每个 member variable 都起始于同一 memory address, 共享 memory address 处的 memory
   [(*demo*)](psi_element://CustomizedTypesUnion_MembersWithSameAddress_Test)
   - 调用 union 的某个 member variable, 实际上是以那个 variable 的 type 来解读这块 memory
2. union's size 等于其所有 member variables' sizes 中的最大值
   [(*demo*)](psi_element://CustomizedTypesUnion_Size_Test)
   - 既然 union 的所有 member variables 共享同一块 memory, 那么 union's size 同其中最大者一样即可
3. 当 union name 为空时, union 的 members 会直接被引入到 union's enclosing scope 中
   [(*demo*)](psi_element://CustomizedTypesUnion_Anonymous_Test)
   - 可用于创建一次性的 union variables
4. union 不可以有 base class 而且不能作为 base class