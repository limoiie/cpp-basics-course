# Advise on Overloading

Overloading 可以让我们避免仅仅因为 parameter lists 不同而为相似的一段逻辑创建不同的 function names.
如 function `print`, 假如没有 overloading 机制的话, 我们需要定义一系列诸如 `print_int`, `print_str`, ... 的 function names, 
不仅 type 信息冗余, 使用起来也十分不方便. 

```c++
void print(int);
void print(const char*);
```

但 overloading 不能滥用. 
当两个 functions 做不同的事情时, overloading 可能并不是一个好的选择.
如下两个 functions:

```c++
void move_file(const char *);
void move_window(int, int);
```

第一个 function 移动文件, 而第二个 function 移动窗口; 
此时若强行使用 overloading, 则会让 function names 丢失一定的信息:

```c++
void move(const char *);
void move(int, int);
```

在这种情况下反而保留不同的 functions names 可以让代码更容易理解.