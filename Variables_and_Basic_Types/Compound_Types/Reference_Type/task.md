# Reference Type

Reference (引用) 用于为 object 创建 alias (别名)
[(*demo*)](psi_element://Reference_LValueReference_Test).
任何对 reference 的操作都等价于操作 reference 所指向的 variable.
甚至, reference 与所指向的 variable 拥有相同的 memory address.

不过, reference 在 initialization 之后不可以再次被 assignment.
也就是说, 每个 reference 只可 bind 一次 object.

## Syntax of Reference

Reference 有两种形式:

1. *type* `&` *attr*<strong>?</strong> *declarator*
2. *type* `&&` *attr*<strong>?</strong> *declarator*

其中:

- *type* 是被 referenced 的 variable 的 type
- *declarator* 是该 reference 的名称
- *attr*? 是可选的 attributes list, 通常为空

## Explanation

1. *type* `&` *attr*<strong>?</strong> *declarator*
     - 是 *lvalue-reference*, 用于指向 named object [(*lvalue*)](course://Expressions/Value/LValue_and_RValue)
     - 可以用于 function argument 的 pass-by-lvalue-reference
       [(*demo*)](psi_element://Reference_PassByLValueReference_Test)
     - 也可以用于 function return 的 return-as-lvalue-reference
       [(*demo*)](psi_element://Reference_ReturnAsLValueReference_Test)
2. *type* `&&` *attr*<strong>?</strong> *declarator*
     - 是 *rvalue-reference*, 用于指向 temporary object [(*rvalue*)](course://Expressions/Value/LValue_and_RValue), 
     - 可以用于 function argument 的 pass-by-rvalue-reference
       [(*demo*)](psi_element://Reference_PassByRValueReference_Test)
     - 也可以用于 function return 的 return-as-rvalue-reference
       [(*demo*)](psi_element://Reference_ReturnAsRValueReference_Test)

注意, rvalue-reference 用来接收 (指向) rvalue, 但它本身却是一个 lvalue.
