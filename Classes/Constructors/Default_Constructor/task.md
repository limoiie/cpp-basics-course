# Default Constructor

Default constructor 可以无需任何 arguments 直接被调用, 也被称为无参构造器.

## Syntax

1. *class-name* **()**  *noexcept-expr*<b>?</b> <br>
   &#20;&#20;&#20;&#20;&#20;&#20;&#20;&#20;*member-initializer-list*<b>?</b> **{** <br>
   &#20;&#20;&#20;&#20; *function-body*<br>
   **}**
2. *class-name* **()** = `default` ;
3. *class-name* **()** = `delete` ;

## Implicitly-Declared Default Constructor

当一个 class 没有 user-defined constructors 时, compiler 往往会为该 class 创建一个 inline public 的 default constructor [(*demo*)](psi_element://Constructors_ImplicitlyDeclared_Test).
该 default constructor 会为每个 member variable 采取 default initialization.

## Implicitly-Defined Default Constructor

当一个 class 有 user-defined constructors 时, 若仍想让 compiler 为该 class 创建 default constructor, 
可以采用 syntax 2 的方式声明一个 implicitly-defined default constructor [(*demo*)](psi_element://Constructors_ImplicitlyDefined_Test).

## Deleted Implicitly-Declared Default Constructor

对于一个 `class T` 来说, 当下列情况发生时, 它的 default constructor 将会被标记为 `deleted`:
- `T` 有一个 member 是 reference, 且并没有为该 member 指定 [*default-member-initializer*](course://Classes/Non_Static_Member_Variables/Initialization)
- `T` 有一个 member 没有可用的 default constructor, 且并没有为该 member 指定 [*default-member-initializer*](course://Classes/Non_Static_Member_Variables/Initialization)
- `T` 的某一个 direct or virtual base class 没有可用(或可访问)的 default constructor
- `T` 的某一个 direct or virtual base class 没有可用(或可访问)的 destructor