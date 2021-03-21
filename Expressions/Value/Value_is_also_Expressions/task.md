# Value

在 C++ 语言中, **value** (值) 指代那些可供 program code (程序代码) 操作的实体 (entity).
Value 可以用于 object 的 initialization, 也可作为 operands 同 operator 一起组成新的 expression.

Value 与 expression 可以看作是同一个概念来自不同角度的解释:
- value 强调的是 expression 计算 (evaluation) 后的结果
- 而 expression 则强调的是 value 具体的计算 (evaluation) 过程

比如说, value 可被视为 sub-expression 以当做 operands, 同 operator 一起组成新的 expression;
而 expression 则可被视为 value 用来 initialize 某一个 object.

C++ 中的每一个 value 都可以用两个独立的属性刻画: *type* 和 
[*value category*](course://Expressions/Value/Value_Categories). 
每一个 value 都有一个 type;
并且每一个 value 都只属于三大主要 value categories 之一: *lvalue*, *prvalue*, *xvalue*.
