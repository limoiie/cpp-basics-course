# Directive `#include`

Directive `#include` 用于导入指定头文件 (header file) 的代码到当前源码文件中.
更具体地, macro processor 会在 macro expanding 期间, 把 directive `#include` 所指定的头文件内的所有内容直接**复制**到当前位置.

## Syntax

Directive `#include` 有两种使用 syntax:

1. `#include <` *header-file-path* `>`
2. `#include "` *header-file-path* `"`

其中 *header-file* 就是头文件于 including-paths 的相对路径

## Explanation

1. `#include <` *header-file-path* `>`
    - 该形式会在标准的 [including path list](https://gcc.gnu.org/onlinedocs/cpp/Search-Path.html) 中搜索指定 *header-file-path* 
2. `#include "` *header-file-path* `"`
    - 该形式会把当前源文件所在路径也扩充到 including path list 中
