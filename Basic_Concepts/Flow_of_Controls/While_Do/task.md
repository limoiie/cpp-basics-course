# The `while` Statement

C++ 提供 `while` Statement 以支持循环执行.

`while` Statement 语法如下

### Statement `while`

```c++
while (CONDITION_EXPRESSION) {
    STATEMENTS
}
// Step 1: 求值 CONDITION_EXPRESSION;
//   - 若值为 true 时, STATEMENTS 会被执行, 然后跳回 Step 1;
//   - 若值为 false 时, 会直接跳出循环体;
```

### Statement `do while`

```c++
do {
    STATEMENTS
} while (CONDITION_EXPRESSION);
// Step 1: 执行 STATEMENTS
// Step 2: 求值 CONDITION_EXPRESSION
//   - 若值为 true 时, 跳回 Step 1;
//   - 若值为 false 时, 会直接跳出循环体
```

## `while` vs `do while`

两者的执行流序列如下所示:

```c++
while:                            do while:

CONDITION == true              
STATEMENTS                        STATEMENTS
CONDITION == true  -+             CONDITION == true  -+
STATEMENTS         -+- n times    STATEMENTS         -+- n times
CONDITION == false                CONDITION == false
```

可以看到, 在结构上 `while` 会保证每次执行 `STATEMENTS` 前都检查一遍 `CONDITION`;
而 `do while` 则会忽略第一次的条件检查, 在开始时立刻执行一遍 `STATEMENTS`, 然后才会在每次执行 `STATEMENTS` 前都检查一遍 `CONDITION`.
