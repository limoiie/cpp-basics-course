# The `virtual` and `override` Specifier

**Virtual member function**.
若想 user-defined class 的 member functions 支持 polymorphism 特性, 只需要:
- 在 base class 里目标 member function 的 declaration 前加上 specifier `virtual` 即可 
  [(*here*)](psi_element://__only_for_anchor_used__virtual_in_base_class)!
- 在 derived class 里对应 member function 的 declaration 后加上 specifier `override` 
  [(*here*)](psi_element://__only_for_anchor_used__override_in_derived_class).
  其实, 去掉 specifier `override` 也不影响整个 polymorphism 机制.
  它只是一个面向程序员的标签, 让程序员即使在长长的 inheritance chain 里, 也能一眼就看出哪些 member function 是 polymorphic 的.
  
**Pure virtual member function**.
在 base class 里, virtual member function 甚至可以完全不提供实现, syntax 上用 `= 0` 代替 function body
[(*demo*)](psi_element://VirtualPureSpecifier_PureVirtual_Test).
这样的 virtual member function 也被称为 *pure virtual member function*. 

此时再看 Coffee Demo 里的问题, 只需将 base class 里的 `content()` 和 `change_cup(cup_e)` 加上 `virtual`
[(*here*,](psi_element://__only_for_anchor_used__polymorphic_virtual_content)
[*here*)](psi_element://__only_for_anchor_used__polymorphic_virtual_change_cup)
(当然最好在 derived class 里也对应加上 specifier `override`
[(*here*,](psi_element://__only_for_anchor_used__override_milk_content)
[*here*,](psi_element://__only_for_anchor_used__override_milk_change_cup)
[*here*)](psi_element://__only_for_anchor_used__override_sugar_content)
) 就可以让该 function 在 base class 中表现出 polymorphism
[(*demo*)](psi_element://VirtualPureSpecifier_Correct_Test).