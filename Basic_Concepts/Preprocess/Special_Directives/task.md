# Special Macros and Directives

## Predefined Macro 

Macro Preprocessor 会预定义如下 Macro, 并会在 Preprocessing 时将其分别替换成对应的内容:
- `__FILE__`: Macro 所在的文件名
- `__LINE__`: Macro 所在的行数
- `__func__`: Macro 所在的 Function 名称  
- `__DATE__`: Compilation 的日期
- `__TIME__`: Compilation 的时间

## Special Directives

Directive `#error` 会导致 Macro Preprocessor 产生一条 Compilation Error.
它通常配合 Conditional Compilation 来阻止一些错误的 Compilation 行为:

```c++
#ifdef _WIN32
#error "Not support on Windows systems!"
#endif
```
