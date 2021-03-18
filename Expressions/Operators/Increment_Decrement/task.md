# Increment Decrement

Increment/Decrement (自增/自减) 就是把 Operand Variable 加/减 1 后再赋给 Variable.

```c++
++a  // prefix increment
--a  // prefix decrement
a++  // postfix increment
a--  // postfix decrement
```

如上所示, Increment/Decrement 有两个版本, 它们都会对 Variable 加/减 1 后再赋给 Variable.
唯一的区别是它们的返回值 (这个并不一定是操作后 Variable 的值!) 不同:
- Prefix Increment/Decrement (`++a, --a`) 返回的是加/减 1 **后**的值
- Postfix Increment/Decrement (`a++, a--`) 返回的是加/减 1 **前**的值

## Task

还记得之前说过 Operator 的本质与 Function 相似吗?
尝试在**不用** Increment/Decrement Operator 的情况下用 Function 实现与之相似的功能吧!

左边已经在 Function [prefix_increment](psi_element://prefix_increment) 里实现了 Prefix Increment,
请仿造着完成剩下的三个 Function~