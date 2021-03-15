# Virtual Destructor

你应该也留意到了, 在上章的例子中
[*(demo*,](psi_element://VirtualPureSpecifier_Virtual_Test)
[*demo*)](psi_element://VirtualPureSpecifier_PureVirtual_Test),
我们没有直接 `delete` 掉 type 为 `base *` 的 pointer, 而是先转型回 `derived *`.

这是因为, 在 `delete p_obj` 时, 是根据 pointer `p_obj` 的 type (即 `class base`), 来调用 destructor (即 `class base` 的 destructor).
然而 `p_obj` 实际上指向的是 derived object, 用 **base** class 的 destructor 来 destruct **derived** object, 肯定会造成一部分资源无法被释放 (因为 base class 无法知晓 derived 到底都获取了哪些资源).
用 derived class 的 destructor 来 destruct derived object 才是正确的操作, 因此才有了 `delete (derived *) p_obj`.

回忆上节介绍的 specifier `virtual`, 它会帮我们透过 base type 调用底层真实 object's type 所对应的 function.
因此, 将 base type 的 destructor 用 specifier `virtual` 修饰后 
[(*here*)](psi_element://__only_for_anchor_used__virtual_destructor),
就可以让 `delete` 自动选择正确的 destructor
[*(demo*,](psi_element://VirtualDestructors_Virtual_Test)
[*demo*)](psi_element://VirtualDestructors_PureVirtual_Test).
由于 destructor 的链式机制, 在调用 derived destructor 后, base destructor 会被自动调用.
因此, 整个释放机制将会被完美执行.

所以:
> 当一个 base class 设计出来就是要被 inherit 的话, 在任何时候都应该为它 declare 一个 virtual destructor.