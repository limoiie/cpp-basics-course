# Variables

Variables (变量) 为我们提供了一个名称索引的存储空间, 可用于存储、传递数据与信息.
C++ 里的每个 Variable 都必须有一个 Type.

Type 决定了 Variable: 
- 所占内存空间的 Size 与 Layout;
- 所能存储的 Data 取值范围;
- 所有可应用于该 Variable 的 Operations 集合.

## Categories

依据作用 Visible Scope 和 Lifetime, Variable 可分为三大类:

| Category        | Visible Scope      | Lifetime     |
|-----------------|--------------------|--------------|
| Local Variable  | 仅作用于当前代码块     | 离开代码块时销毁 |
| Global Variable | 作用于不同的源码文件间  | 整个程序运行期间 | 
| Static Variable | 仅作用于当前源码文件内  | 整个程序运行期间 | 

<br>

## Declaration - Definition - Use

如下代码所示, Variables 的使用一般分为三个部分:

> ```c++
> /**
>  * FILE main.cpp
>  */
> // necessary for declaration!!
> //  | Type Symbol
> //  |   |  |
> //  V   V  V
> extern int a; // 1. Declaration
> //      |___|
> //        |
> //  Initialization
> void main() {
>   std::cout << a; // 3. Use    
> }
> ```
> 
> ```c++
> /**
>  * FILE a.cpp
>  */
> int a   = 10; // 2. Definition
> ```

1. *Declaration*: 需要指定 Variable 的 **Type** 以及唯一名称 **Symbol**, 且必须用 **`extern`** 标识
2. *Definition*: 在 Variable 的 Type 与 Symbol 的基础上对其值进行 **Initialization**
3. *Use (or Reference)*: 在需要用到的地方引用其 Symbol

三者之间的顺序关系可以是:

```
// 仅适用于 Global Variable
1. Declaration -> Use
       \--> Definition
or
// 适用于 Global/Local/Static Variable
2. Definition -> Use
```

**注**: 
- *Definition 蕴含了 Declaration*. 因为 Definition 也要完全指定 Type 和 Symbol. 
  这意味着当 Definition 在 Use 之前时可以省去 Declaration. 
- *Local/Static Variable 没有 Declaration, 只有 Definition*.
  或者说, 这两种 Variable 的 Declaration 与 Definition 必须合并在一起.
  事实上由于 Local/Static Variable 处于线性的 Function/File 内部, 后置 Definition 除了会让人困惑外没有任何好处. 
