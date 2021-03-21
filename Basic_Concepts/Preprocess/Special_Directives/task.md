# Special Macros and Directives

## Special Macro 

Macro preprocessor 会预定义如下 macro, 并会在 macro expanding 时将其分别替换成对应的内容:
- `__FILE__`: macro 所在的文件名
- `__LINE__`: macro 所在的行数
- `__func__`: macro 所在的 function 名称  
- `__DATE__`: compilation 的日期
- `__TIME__`: compilation 的时间

## Special Directives

Directive `#error` 会导致 macro preprocessor 产生一条 compilation error.
它通常配合 conditional compilation 来阻止一些错误的 compilation 行为:

```c++
#ifdef _WIN32
#error "Not support on Windows systems!"
#endif
```
