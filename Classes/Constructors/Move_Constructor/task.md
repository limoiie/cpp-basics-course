# Move Constructor

Move constructor 会在进行 move initialization 时被调用.
一个 `class T` 的 move constructor 是满足如下条件的 constructor [(*demo*)](psi_element://__only_for_anchor_used__move_constructor):
- 第一个 parameter 具有 type `T&&`, `const T&&`, `volatile T&&` 或 `const volatile T&&`
- 剩下的 parameters
    - 要么仅此一个 parameter
    - 要么都指定有 default-arguments

## Syntax

1. *class_name* **(** *class_name* `&&` **)** *noexcept-expr*<b>?</b> <br>
   &#20;&#20;&#20;&#20;&#20;&#20;&#20;&#20;*member-initializer-list*<b>?</b> **{** <br>
   &#20;&#20;&#20;&#20; *function-body*<br>
   **}**
2. *class_name* **(** *class_name* `&&` **)** = `default`;
3. *class_name* **(** *class_name* `&&` **)** = `delete`;

## Implicitly-Declared Default Move Constructor

当一个 class 没有 user-defined move constructors 时, compiler 往往会为该 class 创建一个 inline public 的 default move constructor [(*demo*)](psi_element://Constructors_ImplicitlyDeclaredMove_Test).
该 default copy constructor 会为每个 member variable 采取 copy-initialization.

当一个 class 已有 user-defined move constructor 时,
若仍想让 compiler 为该 class 创建一个 default move constructor,
可以采用 syntax 2 的方式声明一个 implicitly-declared default move constructor [(*demo*)](psi_element://Constructors_ImplicitlyDefinedMove_Test).

## Implicitly-Defined Default Move Constructor

当 implicitly-declared default move constructor 没有被标记为 deleted 时, 那么 compiler 就会 implicitly define (generate and compile a function body) 它.
该 default move constructor 会 move 当前 class 的 base class 以及当前 class 中的每一个 non-static member.

## Deleted Implicitly-Declared Default Move Constructor

对于一个 `class T` 来说, 当下列情况发生时, 它的 default move constructor 将会被标记为 `deleted`:
- `T` 有一个 member 不能被 move
- `T` 的某一个 direct or virtual base class 不能被 move
- `T` 的某一个 direct or virtual base class 没有可用(或可访问)的 destructor

## Move Constructor VS Move Assign Operator

调用 move constructor 发生在用一个 object 来 initialize 另一个 object with the same type 时:
1. initialization (其中, `a` 和 `b` 具有相同类型 `T`):
    - `T a = std::move(b);`
    - `T a(std::move(b));`
2. function argument passing: `f(std::move(a));` (其中 function `f` 的 type 类似于 `void f(T a)`:
3. function return: `return a;`

而在 assignment 时则会调用 move assign operator [(*demo*)](psi_element://Constructors_MoveConstructorAssignOperator_Test).
