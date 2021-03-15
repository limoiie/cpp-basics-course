# Base and Derived Classes

与 inheritance 相关的 classes 会形成一个树形的 hierarchy 结构.
通常这个 hierarchy 会由一个被称为 base class 的 root 节点,
以及被称为 derived classes 的其他节点组成.
这些 derived classes 直接或间接地 inherit 这个 base class. 

在 base class 里 defined 的是对 derived classes 来说公用的 common members;
而在 derived class 里 defined 的是一些专属于其自己的 members.

[Coffee Demo](psi_element://__only_for_anchor_used__base_and_derived_classes) 展示了这样一个例子.
其中:
- `class coffee_t` 是 base class: 
  - *member variables* `brand`, `cup`: 按照常识, 
    每一杯咖啡 (coffee) 都会有自己的品牌 (brand), 大小 (cup_size), 等.
    因此, 这些 common members 被放到了 base `class coffee_t` 中
  - *member function* `content()`:
    用于生成配料说明, 也被放到了 base `class coffee_t` 中;
    毕竟每一杯 coffee 都有配料
  - *member function* `change_cup(cup_e)`:
    每杯饮料都应该可以换杯, 所以这个也属于 base class
- `class with_milk_t` 和 `class with_sugar_t` 是 derived classes:
  - *member variables* `milk`, `sugar` 这些分别只在特有 coffee 中存在的元素, 则被 declared 在对应的 derived classes (`class with_milk_t`, `class with_sugar_t`) 中
  
注意:
这个 member function `content()` 被标识成 `public`, 预想可在 class 外部通过 object 访问.
但奇怪的是, 在 derived class 的 object 调用这个 `public content()` 时, compiler 却报错: *`content`() is a private member of `coffee_t`*
[(*demo*)](psi_element://BaseDerivedClasses_CannotAccessPublicMemberOfBaseClass_Test)?!

其实, 这是因为在 C++ 中默认为 private inheritance.
这与 inheritance accessibility 有关, 见下章 [Inheritance and Access Control](course://Classes/Inheritance/Inheritance_and_Access_Control).
