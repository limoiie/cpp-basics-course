# Local Variables

Local Variables (局部变量) 是指定义在 Code Block (Statement Scope) 内部的变量.
Code Block (Statement Scope) 是指被 "`{}`" 包裹起来的一段连续区域.

Local Variables 的两个属性:
- Visible Scope: 
  仅对位于 Definition 后且与 Local Variable 属于同一 Code Block (Statement Scope) 的代码可见
- Lifetime:
  当程序的执行流退出 Code Block 时, 定义于其内的 Local Variable 都会按照定义的顺序立即被销毁

下面示例中的 Variable `a`, `b`, `c` 均是 Local Variable:
<br><br>

---
```c++
void foo(int c) { // Function 的 Code Block
    int b = 0;
    
    { // 独立 Code Block
        int a = 0;
    } // a destroys here
    
    if (true) { // if 的 Code Block
        int a = 0;
    } // a destroys here
    
    while (true) { // while 的 Code Block
        int a = 0;
    } // a destroys here
    
    if (true) {
        // Nest 的 Code Block
        if (true) { 
            int a = 0;
        } // a destroys here
    }

} // both b and c destroy here
```
---

如上被 "`{}`" 包裹起来的都是 Code Block, 此外可注意到 Code Block 能够 Nested 在更大的 Code Block 内.
当代码执行到 Code Block 的 "`}`" 处时, 在其内部定义的所有 Local Variables 都会被销毁.
<br><br>

## Task

浏览左边代码, 请在**保持代码结构**的基础上, 通过调整 Variable 的 Definition 位置来修正 Function 的实现!