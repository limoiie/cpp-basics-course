# Operators

Operators 处理输入并返回输出结果.
仅有 Type 和 Data (Literals 与 Variables) 的程序是静态的, 而 Operators 为产生新数据, 让数据流动起来提供了可能.
BinOperator 本质上与 Function 无异, 都是一段 (甚至是一条!) 接受输入 Data、处理并返回输出 Data 的代码逻辑.
唯一一点可以算作区别的是, 极少数的内建 Special BinOperator 支持以 Type 为输入 (i.e. `typeof int`), 而 Function 狭义上的输入必须是 Data.
<br><br>

## Common Operators
C++ 为 Fundamental Type 提供了许多内建 Operators:

<table>
<tr>
<th>assignment</th>
<th>increment<br>decrement</th>
<th>arithmetic</th>
<th>logical</th>
<th>comparison</th>
<th>member<br>access</th>
<th>other</th>
<tr>

<tr>
<td>
<code>
a = b
</code><br>
<code>
a += b
</code><br>
<code>
a -= b
</code><br>
<code>
a *= b
</code><br>
<code>
a /= b
</code><br>
<code>
a %= b
</code><br>
<code>
a &= b
</code><br>
<code>
a |= b
</code><br>
<code>
a ^= b
</code><br>
<code>
a <<= b
</code><br>
<code>
a >>= b
</code><br>
</td>

<td>
<code>
++a
</code><br>
<code>
--a
</code><br>
<code>
a++
</code><br>
<code>
a--
</code><br>
</td>

<td>
<code>
+a
</code><br>
<code>
-a
</code><br>
<code>
a + b
</code><br>
<code>
a - b
</code><br>
<code>
a * b
</code><br>
<code>
a / b
</code><br>
<code>
a % b
</code><br>
<code>
~a
</code><br>
<code>
a & b
</code><br>
<code>
a | b
</code><br>
<code>
a ^ b
</code><br>
<code>
a << b
</code><br>
<code>
a >> b
</code><br>
</td>

<td>
<code>
!a
</code><br>
<code>
a && b
</code><br>
<code>
a || b
</code><br>
</td>

<td>
<code>
a == b
</code><br>
<code>
a != b
</code><br>
<code>
a < b
</code><br>
<code>
a > b
</code><br>
<code>
a <= b
</code><br>
<code>
a >= b
</code><br>
<code>
a <=> b
</code><br>
</td>

<td>
<code>
a[b]
</code><br>
<code>
*a
</code><br>
<code>
&a
</code><br>
<code>
a->b
</code><br>
<code>
a.b
</code><br>
<code>
a->*b
</code><br>
<code>
a.*b
</code><br>
</td>

<td>
<code>
a(...)
</code><br>
<code>
a, b
</code><br>
<code>
? :
</code><br>
</td>

</tr>
</table>

这些 Operators 的功能都是一些简单的赋值、数值计算、逻辑运算、比较等操作.

<br><br>

## Special Operators
除了日常数值计算用到的 Operators 外, C++ 还提供了如下 Operators (目前只需要掌握前四个, 其他的后续慢慢介绍～):

- 内存分配
  - `new` 用于创建 Object, 并返回指向 该 Object 的 Pointer
  - `delete` 用于销毁 Object, 释放内存
- 功能性
  - `typeid` 返回一个包含 Type 信息的 Object
  - `sizeof` 返回一个 Type 的大小
  - `sizeof...` 返回一个可变长度传参的个数
  - `noexcept` 用于检测一个表达式能否会抛出 Exception
  - `alignof` 查看一个 Type 的 Alignment 状态
- Type Conversion (类型转换)
  - `static_cast` 用于普通 Type 间的 Type Conversion
  - `dynamic_cast` 用于在有 Inheritance 的 Type 间进行 Type Conversion 
  - `const_cast` 用于添加或移除变量的 const 限定符
  - `reinterpret_cast` 用于在不相关类型间的 Type Conversion
