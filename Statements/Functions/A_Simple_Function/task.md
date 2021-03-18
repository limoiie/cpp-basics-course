# Function

Function (函数) 定义了一段通用的代码逻辑.
在 C++ 中, Function 的 Signature 由 Function 的输入 Types (Parameter Types) 和输出 Type (Return Type) 组成.

Signature 决定了 Function:
- 接受什么 Type 的 Parameters
- 返回什么 Type 的结果

## Declaration - Definition - Use

如下代码所示, Function 的使用一般分为三个部分:

> ```c++
> // optional, for global declaration only
> //  |     Symbol
> //  |       |
> //  V       V
> extern int add(int a, int b); // 1. Declaration
> //      ^       ^      ^
> //      +-------|------+
> //          Signature  
> 
> int main() {
>   std::cout << add(1, 2); // 3. Use
>   return 0;    
> }
>
> int add(int a, int b) { // 2. Definition
>     return a + b;
> }
> ```

1. *Declaration*: 需要指定 Function 的 **Signature** 以及唯一名称 **Symbol**, 可用 **`extern`** 标识
2. *Definition*: 在 Variable 的 Type 与 Symbol 的基础上对其值进行 **Initialization**
3. *Use (or Reference)*: 在需要用到的地方引用其 Symbol

三者之间的顺序关系可以是:

```
1. Declaration -> Use
       \--> Definition
or
2. Definition -> Use     
```

## Categories

依据 Visible Scope, Function 可分为两大类:

| Category        | Visible Scope      |
|-----------------|--------------------|
| Global Function | 作用于不同的源码文件间  |
| Static Function | 仅作用于当前源码文件内  |
