# Constructors

Constructor 是一种特殊的 non-static member functions, 用于 initialize 一块已经分配好的 memory space [(*demo*)](psi_element://__only_for_anchor_used__constructor).

## Syntax

1. *class-name* **(** *parameter-list* **)** *noexcept-expr*<b>?</b> <br>
  &#20;&#20;&#20;&#20;&#20;&#20;&#20;&#20;*member-initializer-list*<b>?</b> **{** <br>
  &#20;&#20;&#20;&#20; *function-body*<br>
  **}** 
2. *class-name* **( )** = `default`
3. *class-name* **(** *parameter-list* **)** = `delete`

其中:
- *class-name* 是 constructor 所在 class 的 name
- *parameter-list* 是逗号分隔的 parameters 序列
- *noexcept-expr*<b>?</b> 可选项, 用于标识该 constructor 不会抛出 exception
- *member-initializer-list*<b>?</b> 可选项, 是一组由 `:` 开头, 以 `,` 分隔的 *member-initializer*s;
  每个 *member-initializer* 的 syntax 如下:
  - *class-or-member* ( *expression-list* )
  - *class-or-member* { *initializer-list* }
- *class-or-member* 要么是 class name, 要么是 member variable
  - 若是 class name [(*demo*)](psi_element://__only_for_anchor_used__delegating_constructor), 
    那就是调用对应的 constructor; 可以是当前 class 或当前 class 的 base class 的 constructors
  - 若是 member variable, 那就是直接初始化该 member
- *expression-list* or *initializer-list* 同 [initialization](course://Statements/Definition/Initialization) 里的一致 

## Explanation

1. syntax 1 对应的 constructor 是最常见的一种形式
2. syntax 2 为当前 class 创建 [default constructor](course://Classes/Constructors/Default_Constructor)
3. syntax 3 将该 constructor 标记为 deleted, 显式禁用该 constructor 