# The Define Directive `#define`

根据 Wikipedia 的描述, Macro 在计算机科学中的本意是:

> A macro in computer science is a rule or pattern that specifies how a certain input should be mapped to a replacement output.
> 
> -- Referenced from [Wikipedia#Macro(computer science)](https://en.wikipedia.org/wiki/Macro_%28computer_science%29?wprov=sfla1)

事实上, C/C++ 中 Macro 的意思与作用亦是如此.
<br><br>

## Macro Definition

定义一个 Macro 的方式是使用 Directive `#define`.
如下定义了一个名为 `MACRO_NAME` 值为 `VAL` 的 Macro:

```c++
#define MACRO_NAME VAL
```

Macro 常被用来给一些常量赋予一个有意义的名字:

```c++
#define ALL_DAYS_PER_YEAR 365
#define PI 3.141592654
#define OPERATING_SYSTEM_NAME "Ubuntu"
// ...
```

## Macro Expanding

Macro Processing 发生在 Compilation 之前的 Preprocessing 阶段.
具体来说, 在 Compiler 进行 Compilation 之前, Macro Preprocessor 会将所有的 Macro 全部替换成对应的文本.
也就是说, Macro 只存在于 Compilation 阶段之前! 
<br><br>

请注意, 因为不参与 Compilation, Macro 不具备任何类型.
它的值, 如上的 `VAL`, 仅仅是单纯的文本.
Macro Processing 会将所有源码中的 `MACRO_NAME` 一字一句地 (literally) 替换成 `VAL`.

什么是 "一字一句地 (literally)" 呢? 一个典型的例子是:

```c++
// before macro processing
#define VAR_NAME age
int VAR_NAME = 10;
```

如上源码在 Macro Processing 时, 会将所有的 `VAR_NAME` 全部替换成文本 `age`.
也就是说, 上述源码会被彻底转换成如下的代码:

```c++
// after macro processing
int age = 10;
```

转换后的 "`int age = 10;`" 才是 Compiler 看到的代码.
所以上述代码看似定义了一个名为 `VAR_NAME` 的 Variable, 实际上定义的是名为 `age` 的 Variable.