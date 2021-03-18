# The `auto` Type

当为一个 variable 进行 initialization 时, 我们常常是能从 initialization 部分推断出 variable type 的.
然而在 C++11 标准以前, 我们仍需显示地指定 variable 的 type.

值得庆幸的是, C++11 引入了 `auto` type specifier 来让 compiler 帮助我们从 initialization 部分推断出合适的 type.
也因此, 当我们使用 `auto` 作为 variable type 时, 一定要同时进行 initialization (否则, compiler 无从推断 type).