# Access Control

在经典的 object-oriental programming 中, encapsulation 是一个非常重要的概念.
Encapsulation 要求对 member 的 accessibility 进行 control, 一般分为三个等级:
- public members: 可以在 class 外部通过该 class 的 object 正常访问
- private members: 无法在 class 外部访问
- protected members: 可以在该 class 的 subclass 中访问;
除此之外, 无法 class 外部访问

C++ 中提供了 3 keywords 来支持这个概念: `public`, `protected` 和 `private`.
