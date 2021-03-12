# The `const` and `volatile` Qualifier

Qualifier `const`/`volatile` 可用来 Qualify 任意 Type,
使用 Qualified Type 声明的 Variable 会具有 Constness/Volatility 特性.

- `const` defines that the type is *constant*
- `volatile` defines that the type is *volatile*

## Explanation

- `const` 使得 Qualified Variable 变成只读常量
  - e.g. `const int a = 10;`
- `volatile` 标记 Variable 为不稳定的、容易发生改变的, 从而阻止 Compiler 将 unchanged Qualified Variable 当作常量进行优化;
  它常用在多线程或嵌入式设备等硬件可靠性较差的运行环境下 
  - e.g. 如下一段代码
    ```c++
    int i = 0;
    while (i == 0) {
        std::cout << i << std::endl;
    } 
    ```
    因为 Variable `i` 在循环体内从未更改, 所以 `while` 的条件始终为 `true`;
    正常情况下 Compiler 会直接将其替换成 `true` 以提高运行效率;
    然而在硬件设备不可靠的情况下 Variable `i` 的仍然会由于外界因素而改变,
    上述代码可能就是为了检测这种改变. 
    在这种情况下, Qualifier `volatile` 就可以避免因 Compiler 优化而导致的 BUG.
