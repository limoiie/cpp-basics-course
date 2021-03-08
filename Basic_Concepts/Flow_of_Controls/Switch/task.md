# The `switch` Statement

当 `if else` 序列较长 (比如超过三个) 时, 可用 `switch` Statement 提高可读性.

`switch` Statement 语法如下

### Statement `switch`

```c++
switch (VALUE_EXPRESSION) {
    case CONSTEXPR_1:
        STATEMETNS_1;
    case CONSTEXPR_2:
        STATEMETNS_2;
        break;
    // more cases...
    default:
        break;
}
// 当 VALUE_EXPRESSION 值等于某个 case 的 CONSTEXPR_i 时, 
// 程序执行流会跳转至那个 case 继续执行, 直到遇见 break 时跳出 switch.
```
