# The `if` Statement

C++ 提供 `if` Statement 以支持条件执行.

`if` Statement 语法如下

### Statement `if`:

```c++
if (CONDITION_EXPRESSION) {
    STATEMENTS
}
// 当 CONDITION_EXPRESSION 值为 true 时, STATEMENTS 会被执行
```

### Statement `if else`:

```c++
if (CONDITION_EXPRESSION) {
    TRUE_STATEMENTS
} else {
    FALSE_STATEMENTS
}
// 当 CONDITION_EXPRESSION 值为 true 时, TRUE_STATEMENTS 会被执行;
// 否则, FALSE_STATEMENTS 会被执行
```

### Statement `else if`::

```c++
if (CONDITION_EXPRESSION_1) {
    STATEMENTS_1
} else if (CONDITION_EXPRESSION_2) {
    STATEMENTS_2
} // ... 继续嵌套 else if
else {
    STATEMENTS_N
}
// CONDITION_EXPRESSION_X 会按顺序被求值: 
//  - 假设第 n 个 CONDITION_EXPRESSION_n 首次为 true, 那么 STATEMENTS_n 会被执行并跳过剩下的嵌套 else-if
//  - 若所有 CONDITION_EXPRESSION 都为 false, STATEMENTS_N 会被执行
```
