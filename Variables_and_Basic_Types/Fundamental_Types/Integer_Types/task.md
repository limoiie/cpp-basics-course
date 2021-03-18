# Integer Types

Integer 的基本类型是 `int`. 
但通过指定不同的 modifiers, 可以从 integer type `int` 中派生出众多具有不同 signedness 和不同 size 的 integer types.
如 `short int`, `unsigned long int`, 等等.

## Modifiers

基本类型 `int` 前可以加上 modifiers 来派生出新的 integer types.
一共有两种**互相正交**的 modifiers:

- signedness (符号)
  - `signed`: 有符号, (default)
  - `unsigned`: 无符号, 非负数
- size (尺寸)
  - `short`: 至少 16 bits
  - `long`: 至少 32 bits
  - `long long`: 至少 64 bits

为了便于日常使用, integer type 可在特殊情况下进行简写:
- integer type 默认是 signed 的, 所以 modifier `signed` 可省略
  [(*demo*)](psi_element://IntegerType_DefaultSigned_Test)
- 另外, 指定任意一个 modifier 后, 基本类型 `int` 可省略
  [(*demo*)](psi_element://IntegerType_DefaultInt_Test)

另外, 你应该也注意到了, 在介绍 size modifier 的时候, 我用了"至少"这个词.
这是因为出于历史遗留的原因, type `int` 和 `long int` 的 size 得视操作系统的 data model 而定, C++ standard 并没有给一个确定的标准.

## Data Models *

不同的 data model 对 fundamental type 的默认 size 有着不同的定义.
随着互联网的蓬勃发展, 海量信息数据化, 不仅 memory space 的大小依摩尔定律呈指数型增长, 人们对于计数的量级也有了越来越高的需求.
因此, 程序语言默认的 size of integer type 也在随之增长.
为了兼容旧的系统, C++ standard 对每一种 data model 都提供了特化支持.

现在被广泛接受的 data models 有如下四种 (你可以运行一下这个
[demo](psi_element://IntegerType_IntegerTypeSize_Test),
看看你的计算机运行着哪个 data model):

- (32 bit systems) **LP32** or 2/4/4 (int is 16-bit, long and pointer are 32-bit) 
  - Win16 API
- (32 bit systems) **ILP32** or 4/4/4 (int, long, and pointer are 32-bit);
  - Win32 API
  - Unix and Unix-like systems (Linux, macOS)
- (64 bit systems) **LLP64** or 4/4/8 (int and long are 32-bit, pointer is 64-bit)
  - Win64 API
- (64 bit systems) **LP64** or 4/8/8 (int is 32-bit, long and pointer are 64-bit)
  - Unix and Unix-like systems (Linux, macOS)

剩下其他的 data models 都非常少见.
比如, ILP64 (8/8/8: int, long, and pointer are 64-bit) 只出现早期的 64-bit Unix systems (e.g. UNICOS on Cray) 中.

## Integer Type Specification *

下表总结了所有可用的 integer types, 它们的等价形式, 及其与不同 data models 的对应关系: 

| Modified Type             | Equivalent Type           | C++ Standard | LP32 | ILP32 | LLP64 | LP64 | 
|:--------------------------|:-------------------------:|:------------:|:----:|:-----:|:-----:|:----:|
| `short`                   | `short int`               | at least 16  | 16   | 16    | 16    | 16   | 
| `short int`               | `short int`               | -            | -    | -     | -     | -    |
| `signed short`            | `short int`               | -            | -    | -     | -     | -    |
| `signed short int`        | `short int`               | -            | -    | -     | -     | -    |
| `unsigned short`          | `unsigned short int`      | -            | -    | -     | -     | -    |
| `unsigned short int`      | `unsigned short int`      | -            | -    | -     | -     | -    |
|---                        |---                        |----------    |      |       |       |      |
| `int`                     | `int`                     | at least 16  | 16   | 32    | 32    | 32   |
| `signed`                  | `int`                     | -            | -    | -     | -     | -    |
| `signed int`              | `int`                     | -            | -    | -     | -     | -    |
| `unsigned`                | `unsigned int`            | -            | -    | -     | -     | -    |
| `unsigned int`            | `unsigned int`            | -            | -    | -     | -     | -    |
|---                        |---                        |----------    |      |       |       |      |
| `long`                    | `long int`                | at least 32  | 32   | 32    | 32    | 64   | 
| `long int`                | `long int`                | -            | -    | -     | -     | -    |
| `signed long`             | `long int`                | -            | -    | -     | -     | -    |
| `signed long int`         | `long int`                | -            | -    | -     | -     | -    |
| `unsigned long`           | `unsigned long int`       | -            | -    | -     | -     | -    |
| `unsigned long int`       | `unsigned long int`       | -            | -    | -     | -     | -    |
|---                        |---                        |----------    |      |       |       |      |
| `long long`               | `long long int`           | at least 64  | 64   | 64    | 64    | 64   |
| `long long int`           | `long long int`           | -            | -    | -     | -     | -    |
| `signed long long`        | `long long int`           | -            | -    | -     | -     | -    |
| `signed long long int`    | `long long int`           | -            | -    | -     | -     | -    |
| `unsigned long long `     | `unsigned long long int`  | -            | -    | -     | -     | -    |
| `unsigned long long int`  | `unsigned long long int`  | -            | -    | -     | -     | -    |
