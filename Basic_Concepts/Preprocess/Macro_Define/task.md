# The Define Directive `#define`

根据 Wikipedia 的描述, Macro 在计算机科学中的本意是:

> A macro in computer science is a rule or pattern that specifies how a certain input should be mapped to a replacement output.
> -- referenced from [Wikipedia#Macro(computer science)](https://en.wikipedia.org/wiki/Macro_%28computer_science%29?wprov=sfla1)

事实上, C/C++ 中 macro 的意思亦是如此.
在项目中经常以同一 pattern 形式出现的代码, 就可以用 macro 来替换.
这不仅达到简化代码的目的, 使用得当还可以增加代码可读性, 方便后期维护调整.

Macro 常被用来给一些常量赋予一个有意义的名字
[(*demo*)](psi_element://MacroDefine_Define_Test).

## Macro Definition

定义一个 macro 需要使用 directive `#define`.
如下定义了一个名为 `MACRO_NAME` 值为 `VAL` 的 macro:

```c++
#define MACRO_NAME VAL
```

## Macro Expanding

在 compilation 之前, macro preprocessor 就会将所有的 macro 全部 expanding 成对应的文本.

这也意味着, macro 只存在于 compilation 阶段之前. 
因为不参与 compilation, macro 不具备任何 type.
它的值, 如上的 `VAL`, 仅仅是单纯的文本.
Macro expanding 会将所有源码中的 `MACRO_NAME` 一字一句地 (literally) 替换成 `VAL`.

什么是 "一字一句地 (literally)" 呢? 一个典型的例子是:

```c++
// before macro processing
#define VAR_NAME age
int VAR_NAME = 10;
```

如上源码在 macro expanding 时, 会将所有的 `VAR_NAME` 全部替换成文本 `age`.
也就是说, 上述源码会被彻底转换成如下的代码:

```c++
// after macro processing
int age = 10;
```

转换后的 "`int age = 10;`" 才是 Compiler 看到的代码.
所以上述代码看似定义了一个名为 `VAR_NAME` 的 variable, 实际上定义的是名为 `age` 的 variable.