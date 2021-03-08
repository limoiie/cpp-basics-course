# Global Function

Global Function 可以在 Project 中的任意源码文件中 Use, 只需要在 Use 前见其 Declaration 即可.

一个经典的 Use Case 如项目代码所示, Global Function [add(int, int)]():
- 其 Definition 放在单独的 Source File [add.cpp](source://src/add.cpp) 中
- 其 Declaration 则放于 Header File [add.h](source://src/add.h) 中
- [task.cpp](source://src/task.cpp) 中, 在 `#include "add.h"` 后 Use 

通过 "将 Declaration 放置于 Header File 中, 并于 Use 前 `#include`" 的方式, 在多文件使用 Global Function 时可以避免冗余重复的 Declaration.
当修改该 Function 的 Signature 时, 也就只需要同步修改这一处 Declaration 即可.

**注**:
与 Variable 不同, Global Function 的 Definition 和 Declaration 都可以加或者不加修饰符 `extern`!
这是因为 Function 默认的 Visible Scope 是 Global, 所以 `extern` 对 Function 是冗余的, 加不加没有影响.
之前的惯例是与 Global Variable 的风格保持一直, 在 Declaration 处加 `extern`, 在 Definition 处不加;
而现在的惯例倾向于都不加 `extern`.
