# Whether Two Parameter Lists Differ

根据 overloading 的定义, 两个 overloaded functions 的 parameter lists 应该可区分的.
那么问题来了, 什么样的两个 parameter lists 是可以区分开的呢?

若存在一个 parameter list instance 在不进行 type conversion 的情况下就能被两个 functions 正确接收时,
那么这两个 functions 的 parameter lists 就是不可区分的.
在明确这一点后, 我们就可以罗列一些影响 parameter lists 是否可区分的因素:

## When not Differ

两个看起来不同的 parameter lists 有可能是相同的.
如下因素无法用来区分两个 parameter lists:
- 省略 parameter name
  - e.g. 如下两个 functions 是同一个 function
  ```c++
  void print(int a);
  void print(int); // error: redeclare
  ```
- type aliases
  - e.g. 如下两个 functions 是同一个 function
  ```c++
  using int32_t = int
  void print(int32_t a);
  void print(int a); // error: redeclare
  ```
- top-level `const`
  - e.g. 如下两个 functions 是同一个 function
  ```c++
  void print(int const a);
  void print(int a); // error: redeclare 
  ```

## When Differ

如下因素可以用来区分两个 parameter lists：
- 不同长度的 parameter lists
  - e.g. 如下两个 functions 可以 overload
  ```c++
  void print(int a);
  void print(int a, int b);
  ```
- reference/pointer to a const or a non-const
  - e.g. 如下两个 functions 可以 overload
  ```c++
  void print(int &a);
  void print(int const& a);
  ```