# Directive `#include`

Directive `#include` 可以导入其他文件的代码到当前源码文件中.
其有两种导入形式:

- `#include <iostream>`
  - 该形式会在标准的 Compiler Include Path 中搜索指定头文件
- `#include "iostream"`
  - 该形式会把源文件所在路径也扩充到头文件搜索路径中
    
Macro Processor 会把 `#include<iostream>` 这一行直接替换成头文件 `iostream` 内的所有文本内容.