# Declaration

Member variables 被 declare 在 class body 里.
Member variables 的 declaration 很简单, 大部分情况下与正常的 variable declaration 无异 [(*demo*)](psi_element://coffee_t),
除了:
- 不可使用 specifier `extern`, `register` 和 `thread_local` (要求 member variables 都必须只属于当前 class 的 object)
- 不可使用 auto type (auto type 推导发生在 class definition 之后?)
- 不可使用 incomplete type 和它的 array (在 class definition 时需要确定 class 的 size, 而 incomplete type 没有 size)
- 当存在 user-defined constructor 时, 不可有与当前 class 同名 的 member variable (防止 name conflict) 

注意: member variables 默认是 declare 而非 define 在 class body 里, 它们的 definitions 发生在 constructors 里.
当然, 你也可以在 member variable declaration 时附上 initialization, 从而将其转变成一个 definition.
