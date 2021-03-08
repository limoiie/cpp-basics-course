# Global Variables

Global Variables (全局变量) 是指定义在*全局区域*的变量.
*全局区域*是指 Functions 和 Classes 的外部区域.

Global Variables 的两个属性:
- Visible Scope:
  对处于其 Declaration 或 Definition 之后的代码都可见
- Lifetime:
  当整个程序退出时才会被销毁, 期间会一直占用内存; 因此, 程序中要尽量减少使用 Global Variable.
  
如下是 Global Variable 的实际使用示例:
<br><br>

---
```c++
/** 
 * FILE other.cpp
 */
int a = 10; // Global Variable Definition
```
---

<br>

---
```c++
/**
 * FILE main.cpp
 */
extern int a; // Global Variable Declaration

int b; // Global Variable Definition Only

// NOTE!! 不建议这样做!! 即用 extern 修饰 Definition; 虽然这样是正确的 C++ 语句, 但除了造成歧义外没有任何意义
extern int c = 10;
// int c = 10;  error: Redefinition of 'c'

int main() {
    return a + b + c; // Global Variable Use
} // a, b, c destroy after this, but not immediately
```
---

其中不难看出, 对于 Global Variables:
- 关键字 `extern` 是区分 Declaration 和 Definition 的关键; 带 `extern` 的是 Declaration
- Definition 可以没有初始化语句 (如上例中的 `int b`)
- 一般的 Use Case 是在需要使用 Global Variable 的文件进行 Declaration
<br><br>

## Task

阅读左边的源码 `task.cpp` 和 `math_stuff.cpp`, 在两处 `/* global_pi=3.14 */` 分别补充 Global Variable `global_pi` 的 Declaration 和 Definition.