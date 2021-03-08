# The If-Else Directives `#if`, `#endif`, `#else`, `#elif`, `#ifdef`, `#ifndef`

If-Else Directives 主要用于 Conditional Compilation.
Conditional Compilation (条件编译) 是指通过构造 Macro Expression, 在 Macro Processing 阶段输出不同的源码给 Compiler.

让我们先看一个简单的例子:

```c++
void what_is_this_os() {
#if defined __unix__ // 判断是否定义了 Macro __unix__
    std::cout << "This is UNIX OS!" << std::endl;
#endif
}
```

在 Unix 系统上, Compilers 会隐式地 (implicitly) 定义一个 Macro `__unix__`.
所以在 Unix 系统上编译上述源码时, Macro Preprocessor 会在 Compilation 阶段前将其转换成如下代码:
```c++
// on Unix OS after Macro Processing
void what_is_this_os() {
    std::cout << "This is UNIX OS!" << std::endl;
}
```

而在非 Unix 系统上时, Directives `#if` 和 `#endif` 之间的源码将在 Compilation 前就被删除掉:
```c++
// on non-Unix OS after Macro Processing
void what_is_this_os() {
}
```

## Directives `#if`, `#endif`

上述例子中的 Directives `#if`, `#endif` 是 Conditional Compilation 的基本要素, 基本语法如下所示:

```c++
#if MACRO_EXPRESSION
CPP_STATEMENTS
#endif
```

只有当 `MACRO_EXPRESSION` 为 `true` 时, 其内部的 `CPP_STATEMENTS` 才会被保留至 Compilation 阶段; 否则, `CPP_STATEMENTS` 将会被删除.

在 `MACRO_EXPRESSION` 中:
- 可以使用的 Operands:
  - Integer Type 的 Literals
  - Boolean Type 的 Literals
  - Character Type 的 Literals
  - Macro
- 可以使用的 Operators:
  - `defined` 用于判断 Macro 是否已经被定义. 若已被定义, 返回 true; 否则, 返回 false.
  - Logical Operator `&&`, `||`, `!`
  - Comparison Operator `==`, `!=`, `<`, `>`, `<=`, `>=`
  - Arithmetic Operator `+`, `-`, `*`, `/`, `%`
  - Bitwise Operator `|`, `&`, `~`, `^`, `>>`, `<<`


## Directive `#ifdef`, `#ifndef`

Directive `#ifdef` 和 Directive `#ifndef` 分别是 `#if defined` 和 `#if !defined` 的简写.
<br><br>

## Directives `#else`, `#elif`

Directives `#else`, `#elif` 可以和上述 Directives 构成 If-Else 句法.
一个更深入的例子如下:

```c++
#if defined __unix__ // __unix__ is usually defined by compilers targeting Unix systems
# include <system>   // # 后可加空格
#elif defined _WIN32 // _WIN32 is usually defined by compilers targeting Windows systems
# include <windows.h>
#endif
```

在 Unix 系统上, `#include <system>` 会被保留;
反之在 Windows 系统上, `#include <windows.h>` 会被保留.