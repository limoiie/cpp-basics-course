# Revisit Memory Layout in Multiple Inheritance

与 single inheritance 的情况类似:
在 multiple inheritance 情况下, 当 base class 拥有 `virtual` member function 时, derived object 的 memory layout 会因为 virtual table 而有轻微变化:
- 整体 object layout 会往高地址方向移位 8 个字节 (64-bit 系统下);
- 空出来的这 8 个字节存储着指向 object's virtual table 的 pointer.

沿用
[task Memory Layout in Multiple Inheritance](course://Classes/Inheritance/Multiple_Inheritance_Memory_Layout)
里的例子, 只不过这次为 base `class base`
[(*here*)](psi_element://__only_for_anchor_used__memory_layout_multi_base_with_vtable)
和其中一个 derived `class multi_derived`
[(*here*)](psi_element://__only_for_anchor_used__memory_layout_multi_derived_with_vtable)
添加 virtual member function.
四者之间的 inheritance 关系依旧, 如下所示:
```c++
class base;
class derived : public base;
class derived_bro : public base;
class multi_derived : public derived, public derived_bro;
```

此时, `class multi_derived`
[(*here*)](psi_element://__only_for_anchor_used__memory_layout_multi_derived_with_vtable)
的 memory layout 将如下:

![Object Layout of class derived with vtable](pics/multi_derived_vtable.png)

由上可知, 即使是在 multiple inheritance 的情况下, multiple derived memory layout 仍然只是两个 base classes 的 memory layout 的拼接.
此时, multiple derived object 内将有两个 virtual table pointers:
- 第一个 virtual table pointer 指向 `class multi_derived` 的 virtual table;
  在 base type (`class derived`) 的 pointer 或其自身 type (`class multi_derived`) 的 pointer 指向 multiple derived object 时起作用;
- 第二个 virtual table pointer 指向 `class derived_bro` 的 virtual table;
  在 base type (`class derived_bro`) 的 pointer 指向 multiple derived object 时起作用

### Run the Demo

试试运行这里的
[demo for class multi_derive](psi_element://RevisitMultipleInheritanceMemoryLayout_MultiDerivedMemoryLayout_Test)
它会直接打印 `class multi_derive` 的 memory layout 到 console.
请观察代码与输出的 memory layout, 并尝试与上面的示意图一一对应~
