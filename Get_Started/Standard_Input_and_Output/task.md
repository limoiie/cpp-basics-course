# Standard Input and Output

## 标准输入流
`std::cin` 是 C++ 标准库定义的标准输入流, 它提供了支持所有 Fundamental Type 的 BinOperator Function "`operator>>(Type &)`".
这意味着对于 Fundamental Type 的 Variables, 你可以采用 "`std::cin >> some_var >> other_var;`" 的形式将输入到 Console 的数据存储到对应的 Variables 中.
多个变量输入默认以**空格**或**回车**分割. 
<br><br>

## 标准输出流
C++ 标准库定义了三种输出流, 提供了支持所有 Fundamental Type 的 BinOperator Function "`operator<<(Type &)`". 如下表所示: 

| 符号        | 描述                     |
|-------------|-------------------------|
| `std::cout` | C++ 标准输出流 (带缓存)   |
| `std::cerr` | C++ 标准错误输出流 (无缓存)|
| `std::clog` | C++ 标准错误输出流 (带缓存)|

它们的区别主要有两点:
1. 正常输出流 or 错误输出流.
    - Unix 系统设计为了方便将错误信息同正常的运行输出清晰的区分开, 设立了独立的错误输出流和正常输出流. 
      C/C++ 作为 Unix 系统的实现语言就继承了这一思想.
2. 是否带缓存?
    - 每在 Console 打印出一个字符串都要进行一次耗资源的系统调用. 
      当连续打印多个字符串时, 更高效的方式是将它们拼接成一个长字符串一次打印出来, 这就是缓存输出流. 
      错误输出流有些例外, 它需要无缓存版本, 是因为在程序异常退出时, 缓存会导致一部分信息未来得及被打印.

运行右侧代码并观察输出, 回答下列问题: