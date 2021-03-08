# Integer Types

Integer 的基本类型是 `int`. 它有两种**互相正交**的附加 Modifiers:
- Signedness (符号)
  - `signed`: 有符号, (default)
  - `unsigned`: 无符号, 非负数
- Size (尺寸)
  - `short`: 至少 16 bits
  - `long`: 至少 32 bits
  - `long long`: 至少 64 bits

Integer Type 有如下三个性质:
- Integer Type 默认是 signed 的, 所以 `signed` 可省略
- 另外, 指定任意一个 Modifier 后, 基本类型 `int` 可省略
- 还有, Type `int` 与 `long` 的 Size 得视操作系统而定

详细信息可见下表:

| Type Specifier            | Equivalent Type           | C++ Standard | LP32 | ILP32 | LLP64 | LP64 | 
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



由于历史遗留问题, 不同的操作系统上 `int`, `long` 的大小并不统一.
早期内存小时, `int` 是 16-bit, `long` 是 32-bit;
在 32-bit 的系统上时, `int` 是 32-bit, `long` 也是 32-bit;
再后来 64-bit 系统上, `int` 还是 32-bit, 而 `long` 则已经是 64-bit 了.