# Reference Type

Reference (引用) 用于为 Variable 创建 Alias.
任何对 Reference 的操作都等价于操作 Reference 所指向的 Variable.
<br><br>

## Syntax

Reference 有两种形式:

1. *type* `&` *attr*<strong>?</strong> *declarator*
2. *type* `&&` *attr*<strong>?</strong> *declarator*

其中:

- *type* 是被 Referenced 的 Variable 的 Type
- *declarator* 是该 Reference 的名称
- *attr*? 是可选的 Attributes List, 通常为空

## Explanation

1. *type* `&` *attr*<strong>?</strong> *declarator*
   是 *lvalue-reference*, 用于指向已存在的 Object (*lvalue*)
2. *type* `&&` *attr*<strong>?</strong> *declarator*
   是 *rvalue-reference*, 用于指向 Temporary Object (*rvalue*), 
