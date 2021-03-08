# Literals

Literals 直译为: "字面值", 是 C++ 提供的可以直接内嵌到源码里的常数. 
每个 Fundamental Type 都有自己的 Literals:

- Boolean Type
  - `true` or `false`
- Character Type
  - `'a'`, `'b'`, ..., '`\n`', '`\r`', ...
- Integer Type
  - `signed`: `10`, `-10`, `100`, `888`, ...
  - `unsigned`: `0u`, `10u`, `100u`, `999u`, ...
  - `long`: `10l`, `-10l`, ...
  - `unsigned long`: `10ul`, `10lu`, ...
- Floating Point Type
  - `float`: `10f`, `10.0f`, `21.f`, `10e5f`
  - `double`: `10.0`, `10.`, `2.13e5`
- Array of Characters
    - `"string"`, `"another long string"`, ...
- Null Pointer
  - `nullptr`: 空指针

运行并观察左边的输出, 回答下面问题:

**小知识**: 
- `auto` 是 C++11 提供的新关键字, 它会让编译器自动从定义值推断 Variable 的 Type. 
  编译器大部分时间都是能够做的这一点的, 毕竟一个值本身会蕴含自己的 Type.
- `typeid` 是 C++11 提供的关键字, 它能推断并返回一个 Variable 或 Type 的信息.