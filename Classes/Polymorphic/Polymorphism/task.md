# Polymorphism

Polymorphism (多态) 在 wiki 上的一段解释:

> Polymorphism is a common standard programming facility where derived objects can be used as instances of their base object but where the derived objects' methods will be invoked.
> -- *referenced from [wiki](https://en.wikipedia.org/wiki/Template_metaprogramming#Static_polymorphism)*

简单翻译过来, polymorphism 就是:
1. derived object 可以装在 base class type 的 variable 中;
2. 调用 base class type variable 的 function 时, 实际被调用的将是底层对应 derived object 的 function

再看 [Coffee Demo](psi_element://__only_for_anchor_used__expect_polymorphic_content).
我们需要对现有的 coffee 代码进行需求完善:
- 需要对现有的 `content()` 进行配方更新.
  虽然每一杯 coffee 都有配料, 但 derived `class with_milk_t` 和 `class with_sugar_t` 都为 coffee 添加了新配方 (milk, sugar);
- 需要拒绝售卖 `MIDDLE_CUP` 的 with_milk coffee.
  因为老板觉得小杯 (`MIDDLE_CUP`) 的 with_milk coffee 不赚钱

针对需求, 调整如下:
- Derived `class with_milk_t`:
  - 新增 member function `content()`:
    在 base class 的 `content()` 基础上追加了对于 'milk' 的描述
    [(*here*)](psi_element://__only_for_anchor_used__milk_content);
  - 新增 member function `change_cup(cup_e)`:
    当要求更换成 `MIDDLE_CUP` 时, 会直接 `return false`
    [(*here*)](psi_element://__only_for_anchor_used__milk_change_cup);
- Derived `class with_sugar_t`:
  - 新增 member function `content()`: 
    在 base class 的 `content()` 基础上追加了对于 'sugar' 的描述
    [(*here*)](psi_element://__only_for_anchor_used__sugar_content);

此时, 我们希望 `class coffee_t` 的 member function `content()` 和 `chagne_cup(cup_e)` 能表现出 polymorphic 的特性.
即, 当通过 pointer of base type 调用 member function 时, 实际上调用的是 derived object 的 member function with the same name.
只有这样, 我们针对需求的更改才能正常生效.

为了验证 `class coffee_t` 的 member function `content()` 和 `chagne_cup(cup_e)` 是否真的具有 polymorphic 的特性,
我们创建了一个 [demo](psi_element://BaseDerivedClasses_CallWrongMember_Test).
若 C++ 支持 polymorphism 的话,
当我们通过 base type (`class coffee_t`) 来访问 member function `content()` 时, 
调用的应该是 derived object (`class with_milk_t`) 的 `content()`.
但事与愿违, 我们可以从 demo 的运行结果中看到, 实际上被调用的却仍是 base type 的 `content()`.

怎么回事? 难道 C++ 不支持 polymorphism 吗?
C++ 当然支持! 只不过还需要一点小小的调整, 请看下章 [Virtual and Pure Specifier](course://Classes/Polymorphic/Virtual_and_Override_Specifier).
