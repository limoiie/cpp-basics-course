# Static Variables

Static Variables (静态变量) 是指定义在*全局区域*但用 `static` 修饰的变量.
*全局区域*是指 Functions 和 Classes 的外部区域.

Static Variables 的两个属性:
- Visible Scope:
  对**同一源文件**下处于其 Declaration 或 Definition 之后的代码都可见
- Lifetime:
  当整个程序退出时才会被销毁, 期间会一直占用内存; 因此, 程序中要尽量减少使用 Static Variable.

Global Variable 与 Static Variable 的**唯二区别**是 1) Visible Scope 不同, 2) Static Variable 没有前置 Declaration.
当你定义的 Global Variable 不想被除当前源文件外其他文件内的代码使用的话, 你可以在 Global Variable 的 Definition 前加上 `static` 使其变成 Static Variable.

如下是 Static Variable 的使用示例:
<br><br>

---
```c++
/** 
 * FILE other.cpp
 */
static int a = 10; // Global Variable Definition
```
---

<br>

---
```c++
/**
 * FILE main.cpp
 */
extern int a; // 没有效果! Variable a 只在 other.cpp 内可见

static int b = 10; // Static Variable Definition

static int c; // Static Variable Definition!!

int main() {
    return b + c; // Global Variable Use
} // a, b, c, d destroy after this, but not immediately

static int d = 10; // 该变量无法在 Function main() 中使用
```
---

其中不难看出, 对于 Static Variables:
- 没有而且不允许独立的 Declaration
- Definition 可以没有初始化语句 (如上例中的 `int c`)
- 只对 Definition 所在的源码文件内可见; 或者说, 只能在 Definition 所在的源码文件内使用
<br><br>

## Task

阅读左边的源码 `task.cpp`, `math_stuff.cpp` 和 `other_lib.cpp`.
先 CHECK 一下看看 Compiler 报什么错?
然后尝试用 Static Variable 的相关知识解决一下～
