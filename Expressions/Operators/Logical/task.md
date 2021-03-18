# Logical Operator

Logical Operator (逻辑运算符) 进行简单的"与、或、非"这三种逻辑运算.

```c++
a && b
a || b
!a
```

Logical Operator 的 Return Type 是 `bool`.
若 Logical 成立, 返回 `true`; 否则返回 `false`.

你或许也注意到了: 逻辑运算还有异或操作, 为什么没有异或对应的 Operator 呢?
实际上异或操作等价于 Comparison Operator '`!=`' (不等于).
可观察如下第四个有关异或的真值表:

与真值表:

| `a`     | `b`     | `a && b` |
|:-------:|:-------:|:--------:|
| `true`  | `true`  | `true`   |
| `true`  | `false` | `false`  |
| `false` | `true`  | `false`  |
| `false` | `false` | `false`  |

或真值表:

| `a`     | `b`     | `a or b` |
|:-------:|:-------:|:--------:|
| `true`  | `true`  | `true`   |
| `true`  | `false` | `true`   |
| `false` | `true`  | `true`   |
| `false` | `false` | `false`  |

非真值表:

| `a`     | `!a`    |
|:-------:|:-------:|
| `true`  | `false` |
| `false` | `true`  |

异或真值表:

| `a`     | `b`     | `a ^ b`  | `a != b` |
|:-------:|:-------:|:--------:|:--------:|
| `true`  | `true`  | `false`  | `false`  |
| `true`  | `false` | `true`   | `true`   |
| `false` | `true`  | `true`   | `true`   |
| `false` | `false` | `false`  | `false`  |
