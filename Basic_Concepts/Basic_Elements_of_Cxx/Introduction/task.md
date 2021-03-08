# Basic Elements of C++
C++ 语言三大元素: Type (类型), Data (数据) 和 Operation (操作)。
作为一门语言本身, C++ 不仅原生地为每一个元素提供了基础实现, 还提供了一套完整的机制供程序员对这些元素进行自定义扩充。

|                  | Type             | Data      | Operation   |
|:----------------:|------------------|-----------|-------------|
| **C++ Built-in** | Fundamental Type | Literals  | Operators   |
| **Customizable** | Classes          | Variables | Functions   |

如上表所示, 第一行是 C++ 对三大元素的基础支持, 第二行是为程序员提供的自定义化机制。
于 Type 而言, C++ 内建 (built-in) 了 Fundamental Type (如 int, long 等), 并允许程序员通过定义 Class 来创建自己的 Type。

左边这段简单的代码 (计算圆和长方形的面积) 一一展示了这些元素。
现实世界里 C++ 项目可能更加庞大和复杂, 但其包含的基本元素也无外乎于此。
<br><br>

<!-- 
## Type (类型)
在 C++ 里, Data 一定要有
Type 为 Data 赋予了语义, 没有 Type 标识的 Value 只是毫无意义的 01 串。
Literal 和 Variable 有 Type, 如 `int`, `long`, `double` 等;
Function 有 Type, 如 Function `main` 的类型是 `int (*)()`;
Class 也有 Type, 其 Type 即为其本身。
<br><br>

| Type     |      Data      |  Function |
|----------|:-------------:|------:|
| col 1 is |  left-aligned | $1600 |
| col 2 is |    centered   |   $12 |
| col 3 is | right-aligned |    $1 |

## Data (数据)
Variable, Function 和 Class 都是 Data: 
- Variable 定义和承载目标信息, 如名称、住址、身高等;
- Function 定义了相关信息的处理逻辑, 它在 C++ 内部实现中实际上是一个指向一连串指令的指针;
- Class 则将前两者以模块化的方式封装起来, 使得代码逻辑结构更清晰, 方便代码复用与维护。

而 C++ 程序员们 (包括绝大多数其他语言的程序员) 的主要任务就是如何合理的设计与组织它们，以可维护、高效率的方式，来实现预期制定的需求，并完成一个具体的项目。
<br><br>
 -->

## 自定义元素的三个步骤
程序员的主要工作就是创建各种自定义的三大元素来实现目标需求。
留意左边代码里的注释, 每种自定义元素 (Class, Variable, Function) 的使用都分三个步骤:
- Declaration 标识元素的 Type;
- Definition 定义元素的具体实现;
- Use 引用元素

其中有几点需要注意:
- 自定义都遵循 Declaration -> Definition -> Use 的先后顺序;
  - 其中 Function 有些例外, 它的 Definition 可以出现在 Use 之后;
- Definition 本身也是 Declaration, 因为它也提供了元素具体的 Type;


**注:** 其实对于 Variables 而言, 情况稍微有点复杂:
- Global Variable 和 Static Member Variable 支持 Declaration 和 Definition 分开;
剩余 Variables 的 Declaration 与 Definition 是一体的, 不可分开成两行。
例如 "`int circle_radius;`", 虽然没有指定具体的数值, 但它仍然是 Variable `circle_radius` 的定义。

<!-- <li>Insert the &percnt;<code>IDE_NAME</code>&percnt; macro,
which will be replaced by the actual IDE name.
For example, <strong>%IDE_NAME%</strong>.</li><br>

<li>Insert PSI elements, by using links like
<code>&lt;a href="psi_element://link.to.element"&gt;element description&lt;/a&gt;</code>.
To get such a link, right-click the class or method
and select <strong>Copy Reference_Type</strong>.
Then press &amp;shortcut:EditorPaste;
to insert the link where appropriate.
For example, a
<a href="psi_element://java.lang.String#contains">link to the "contains" method</a>.</li> -->
