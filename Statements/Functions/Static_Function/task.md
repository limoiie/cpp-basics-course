# Static Function

Static Function (静态函数) 被 `static` 修饰, 其 Visible Scope 只限在当前源码文件中.

Static Function 经典的 Use Case 如下:

```c++
static void log(double f); // 1. Declaration

void sum(double a, double b) {
    log(a);  // 3. Use
    log(b);  // 
    return a + b;
}

void log(double f) { // 2. Definition
    // print some log info about f to Console
}
```

Static Function 的 Declaration, Definition 和 Use 与 Global Function 基本一致, 除了:
1. 前缀修饰符不同.
   Static Function 的 Declaration 必须用 `static` 修饰; 
   而 Global Function 则用 `extern` (也可省略不加)；
2. Visible Scope 不同.
   Static Function 只能在 Declaration 所处的源码文件内 Use;
   而 Global Function 则对任意源码文件都可见.

## Task

左边项目中有 5 个源码文件, 设计说明如下:
- [log.cpp](source://src/log.cpp), [log.h](source://src/log.h): 
  定义了一个 Function [f_log](psi_element://f_log#2)
  用于计算对数
- [add.cpp](source://src/add.cpp), [add.h](source://src/add.h):
  定义了一个 Function [f_add](psi_element://f_add)
  用于计算两数之和
- [task.cpp](source://src/task.cpp)
  定义了一个 Function [compute](psi_element://compute),
  其通过调用 [add.cpp](source://src/add.cpp) 的 Function [f_add](psi_element://f_add) 以及 [log.cpp](source://src/log.cpp) 的 Function [f_log](psi_element://f_log#2) 来计算对数之和.

然而, [add.cpp](source://src/add.cpp) 中也定义了一个 Function [f_log](psi_element://f_log) 用来输出日志信息.
这导致了在 Function [compute](psi_element://compute) 中 Use 的 [f_log](psi_element://f_log) 有歧义.
可以点击下方的 CHECK 按钮, 观察并分析错误信息.

请在不改变 Function 名称的情况下, 通过使用 `static` 来缩小问题 Function 的 Visible Scope, 从而修正 BUG. 