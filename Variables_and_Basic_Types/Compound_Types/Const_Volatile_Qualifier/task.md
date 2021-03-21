# The `const` and `volatile` qualifier

Qualifier `const`/`volatile` 可用来 qualify 任意 type,
qualified object (object of qualified type) 会具有 constness/volatility 特性.

- `const` defines that the type is *constant*
- `volatile` defines that the type is *volatile*
- `const volatile` defines that the type is both *constant* and *volatile*

## Explanation

- `const` const object 是*只读常量*, 一旦被 initialized 后就是 non-mutable (不可被修改的)
  - e.g. `const int a = 10;`
- `volatile` volatile object 是*无常量*, 从程序员视角来看, 使用方式和性质与普通 variable 无异;
  而对于 compiler 来说, 在任何情况下都不能把 volatile object 当成常量进行诸如约减之类的优化, 因为 volatile object 是不稳定不可靠的;
  它常用在多线程或嵌入式设备等硬件可靠性较差的运行环境下 
  - e.g. 如下一段代码
    ```c++
    int i = 0;
    while (i == 0) {
        std::cout << i << std::endl;
    } 
    ```
    因为 variable `i` 在循环体内从未更改, 所以看似 `while` 的条件应该始终为 `true`;
    正常情况下 compiler 会直接将其替换成 `true` 以提高运行效率;
    然而:
    - 在多线程的情况下, variable `i` 会被其他线程修改;
    - 在硬件设备不可靠的情况下, variable `i` 的仍然会由于外界因素 (bit flip) 而改变;

    因此, 在上述任何情况下对 variable `i` 进行约减优化都会导致难以察觉的优化.
    在这种情况下, qualifier `volatile` 就可以避免因 compiler 优化而破坏原先的设计意图.
- `const volatile` const volatile object 既是 const object 又是 volatile object.

## Conversion between cv-qualified Types

cv-qualifiers 之间有 cv-qualified 程度大小之分:

- unqualified < const
- unqualified < volatile
- unqualified < const volatile
- const < const volatile
- volatile < const volatile

一个 cv-qualified references/pointers 可以被 implicitly converted 成 cv-qualified 程度更大的 type.
