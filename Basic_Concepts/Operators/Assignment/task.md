# Assignment Operator

Assignment Operator (赋值操作符) 用来给 Modifiable Variable 赋值.
其最基本的形式如下:
<br><br>

```c++
a = 10;
```

但要注意区别 Assignment 与 Initialization.
下面的语句**全都不是**合乎语法的 Assignment:
<br><br>

---
```c++
int a = 10;       // initialization, not assignment
const int c = 10; // initialization, not assignment

1024 = k;   // error: literals are not assignable
i + j = k;  // error: arithmetic expressions are not assignable
c = k;      // error: ci is a const (non-modifiable) var
```
---

Assignment Operator 有如下几个性质:
- 它是 Right Associative, 且从右向左被执行
  - i.e.
    ```c++
    a = b = c = 10
    ```
- 它的返回值通常是指向 Assigned Variable 的 Reference
  - i.e.
    ```c++
    (a = 10) = 20;  // equivalent to "a = 10; a = 20;"
    ```
    
## Compounded Assignment Operator

在平时编程中通常会有一种操作是, 在应用了一个 Operator 到 Variable 后再把结果 Assignment 给这个 Variable, 如下:

```c++
for (int val = 0; val < 10; ++val) {
    sum += val; // equivalent to sum = sum + val;
}
```

像 `+=` 这样的 Operator 被称为 Compounded Assignment Operator, 类似的还有:

```c++
 +=    -=    *=    /=    %=
 &=    |=    ^=   <<=   >>=  
&&=   ||=
```

它们都完全等价于:

```c++
a = a op b;
```
