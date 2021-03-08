# The `for` Statement

当循环体的执行流与某一小些 Variables 密切相关时, C++ 提供了更方便易读的 `for` Statement

`for` Statement 语法如下

### Statement `for`

```c++
for (INIT_STATEMENT; 
     CONDITION_EXPRESSION;
     UPDATE_STATEMENT) {
    STATEMENTS
}
// 其中的 INIT_STATEMENT 和 UPDATE_STATEMENT 可以为空
```

执行流序列如下示意:

```c++
INIT_STATEMENT
CONDITION_EXPRESSION == true -+
STATEMENTS                    + loop n times
UPDATE_STATEMENT             -+
CONDITION_EXPRESSION == false
```

## `for` vs `while`

Statement `for` 几乎完全等价于 Statement `while`.
可将上述 Statement `for` 的语法用 Statement `while` 改写:

```c++
INIT_STATEMENT
while (CONDITION_EXPRESSION) {
    STATEMENTS
    UPDATE_STATEMENT
}
```

"几乎完全" 说明还有些细微的区别, 你看出来了吗?
是的! 在 INIT_STATEMENT 里定义的 Variable 的 Lifetime 将不同:
- Statement `for` 的 INIT_STATEMENT 定义的 Variable 在 `for` 循环结束是就销毁了;
- Statement `while` 版 INIT_STATEMENT 定义的 Variable 将会在退出循环时依旧可用.
