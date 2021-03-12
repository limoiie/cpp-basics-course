# The `auto` Type

往往一个 Variable's Definition 的 Initialization Expression 部分就已经提供了足够的 Type 信息;
然而在 C++11 标准以前, 我们仍需显示地指定 Variable 的 Type.
值得庆幸的是, C++11 引入了 `auto` Type Specifier 来让 Compiler 帮助我们推断出合适的 Type.
