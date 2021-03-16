# Multiple Inheritance

再看 [Coffee Demo](psi_element://__only_for_anchor_used__coffee_multiple_inheritance).
既然有了 with_milk coffee 和 with_sugar coffee, 为什么不能组合一下再做一个 with_milk_sugar coffee 呢?

说干就干, 这个
[demo](psi_element://MultipleInheritance_SomethingWrong_Test)
就通过同时 inherit `class with_milk_t` 和 `class with_sugar_t` 组合了一个 `class with_milk_and_sugar_t`:
- member function `content()`: 拼接了 `class with_milk_t` 和 `class with_sugar_t` 的 `content()`
  - 思路: with_milk_sugar coffee 本身就 with_milk coffee 和 with_sugar coffee 组合成的, 配料表自然也是拼接了;
- member function `change_cup(cup_e)`: 沿用了 `class with_milk_t` 里的 `change_cup(cup_e)`
  - 思路: with_milk_sugar coffee 也是 with_milk coffee 的一种, 老板同样觉得小杯不赚钱,
    所以继续沿用 `class with_milk_t` 的换杯策略

但在实际运行中却出现了一个严重的 bug: `class with_milk_and_sugar_t` 的 object 在换杯后, 出现了杯子大小错乱的情况!
可运行 [demo](psi_element://MultipleInheritance_SomethingWrong_Test) 复现 bug,
能发现调用 `content()` 输出了: 
> `"Nescafe in super cup with milk 0.100000 && Nescafe in big cup with sugar 0.200000"`

输出中前后半段的杯子大小不一致( `"super cup"` 和 `"big cup"`). 

这个 bug 的原因很好理解. 根据
[task Revisit Multiple Inheritance Memory Layout](course://Classes/Polymorphic/Revisit_Multiple_Inheritance_Memory_Layout)
可知, 实际上 multiple derived class (`class with_milk_and_sugar_t`) 里有两份 base class (`class coffee_t`) 的 memory layout, 
同时也有两个 virtual table pointers.
当执行 `with_milk_and_sugar_t::content` 时, `with_milk_t::content` 和 `with_sugar_t::content` 会在各自 memory layout 中运行, 也就出现了上述冲突.

那么有没有什么方法解决这个问题呢? 有, virtual inheritance, 请见下节.

