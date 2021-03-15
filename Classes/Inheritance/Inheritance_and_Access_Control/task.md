# Inheritance and Access Control

Inheritance 时可指定 derived class 如何控制来自 base class 的 members 的 accessibility.
据此可将 inheritance 分为如下三类:
- public inheritance [(*demo*)](psi_element://__only_for_anchor_used__public_inheritance):
  来自 base class 的 members 的 accessibility 高于 `public` 的在 directly-derived class 中将变成 `public` (即全都不变)
  [(*demo*)](psi_element://InheritanceAccessibility_Public_Test);
- protect inheritance [(*demo*)](psi_element://__only_for_anchor_used__protected_inheritance)
  来自 base class 的 members 的 accessibility 高于 `protected` 的在 directly-derived class 中将变成 `protected`
  [(*demo*)](psi_element://InheritanceAccessibility_Protected_Test);
- private inheritance [(*demo*)](psi_element://__only_for_anchor_used__private_inheritance)
  来自 base class 的 members 的 accessibility 高于 `private` 的在 directly-derived class 中将变成 `private` (即全都变成 `private`)
  [(*demo*)](psi_element://InheritanceAccessibility_Private_Test);

若未指定 inheritance accessibility 时, 默认为 private inheritance.

回到 [Coffee Demo](psi_element://__only_for_anchor_used__base_and_derived_classes), 
现在应该明白为什么 derived class 的 object 无法访问 base class 的 public member function `content()` 了:
derived `class with_milk_t` 与 `class with_sugar_t` 都是 privately inherit (default) 了 base `class coffee_t`.
因此, 修正这个小 bug 的方式很简单, 只需要将默认的 inheritance accessibility 改成 public 即可 
([here](psi_element://__only_for_anchor_used__with_milk_change_to_public_inheritance) and [here](psi_element://__only_for_anchor_used__with_sugar_change_to_public_inheritance)).
