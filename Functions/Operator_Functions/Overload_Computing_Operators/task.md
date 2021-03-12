# Overload Computing Operators

## Syntax

可以 overload 的 computing operators 的 syntax 如下所示:

1. `operator` *op*

其中,

*op* 是如下任意一个 operator symbol:
- infix
  ```c++
  +, -, *, /, %, ^, &, |, ~, =, <, >, +=, -=, *=, /=, &=, ^=, &=, |=, <<, >>, <<=, >>=, ==, !=, <=, >=, &&, ||
  ```
- prefix
  ```c++
  +, -, *, ~, !, ++, --
  ```
- postfix
  ```c++
  ++, --, ->*, ->
  ```
- call ```()```
- index ```[]```

## Signature of Overloaded Operator

如上, 同一个 operator symbol 可能对应不同的 operators.
例如, operator symbol `+` 既可以是 infix 也可以是 prefix.
为了 overload 这些多义的 operator symbols,
需要靠着不同的 signatures 来区分彼此:

| Form     | Call Form  | Signature as member function | Signature as function   |   |
|----------|------------|------------------------------|-------------------------|---|
| prefix   | `@a`       | `(a).operator@ ()`           | `operator@ (a)`         | [*demo*](psi_element://OverloadComputingOperators_Prefix_Test)  |
| infix    | `a@b`      | `(a).operator@ (b)`          | `operator@ (a, b)`      | [*demo*](psi_element://OverloadComputingOperators_Infix_Test)  |
| infix*   | `a=b`      | `(a).operator= (b)`          | *forbidden*             | [*demo*](psi_element://OverloadComputingOperators_InfixAssign_Test)  |
| postfix  | `a@`       | `(a).operator@ (0)`          | `operator@ (a, 0)`      | [*demo*](psi_element://OverloadComputingOperators_Postfix_Test)  |
| postfix* | `a->`      | `(a).operator-> ()`          | *forbidden*             | [*demo*](psi_element://OverloadComputingOperators_PostfixMemberAccess_Test)  |
| call     | `a(b...)`  | `(a).operator() (b...)`      | *forbidden*             | [*demo*](psi_element://OverloadComputingOperators_Call_Test)  |
| index    | `a[b]`     | `(a).operator[] (b)`         | *forbidden*             | [*demo*](psi_element://OverloadComputingOperators_Index_Test)  |

上表格中, `@` 代表着所有可用的 operator symbols, 在 infix 和 postfix 的情况下有一点点例外:
- 在 infix form 下, `@` 要除去例外 `operator=`
- 在 postfix form 下, `@` 要除去例外 `operator->`

## Member Operator or Non-Member Operator?

在大多数情况下, member operator 更有优势:
1. member operator 基本覆盖了 non-member operator 的功能;
2. member operator 可以直接访问到 class 内的 private member;
  而 non-member operator 则不可以.

上述第 1 条有例外 [(*demo*)](psi_element://OverloadComputingOperators_Infix_Test):
当 infix operator 需要支持 associative 特性时, 只有 non-member operator 可以实现;
而 member-operator 则要求其所属 object 必须在左侧 (i.e. `a + 1`), 因此无法实现 (i.e. `1 + a`).

除此之外, 优先建议将 operator 定义成 member operator 的形式.

## Restriction

在 overload 这些 operators 时, 要保证至少有一个 operand 是 class type 或 enumeration type 的.
另外:

- 如下 operators 不可以被 overloaded:
  - `::` (scope resolution)
  - `.` (member access)
  - `.*` (member access through pointer to member)
  - `?:` (ternary conditional)
- 不可以创建新的 operators, 如 `**`, `<>` 等等;
- 不可以改变现有 operators 的 precedence, grouping 或 operands 的个数;
- `operator->` 的 overloads 必须返回一个 pointer-like 的值:
  - 要么返回一个 raw pointer
  - 要么返回一个 overload 了 `operator->` type 的 object
- `operator&&` 或 `operator||` 的 overloads 会丧失 short-circuit evaluation 机制

除此之外, C++ 对 operators 的 parameter lists 和 return type 没有任何额外的 restriction.
