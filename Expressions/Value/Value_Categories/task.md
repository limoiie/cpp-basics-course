# Value Categories

C++ 语言里, 每一个 value 都唯一属于某一个 value category.
不同 value category 的 value 将有着不一样的属性, 可以被 operators 或 functions 区分处理.

## Primary Value Categories

可以把所有 value 分为如下三个互相独立的 value categories:

- **lvalue**
  - 即 Left value (左值).
    这个叫法由来是, 只有该类的 value 可以出现在 assignment expression 中 `operator=` 的左边.
    换句话说, 只有 lvalue 可以被 assigned.
  - lvalue 是满足如下任一条件的 value/expression:
    - 所有拥有 name 且 not-expired 的 value (见 xvalue);
    - return type 为 
      [lvalue reference](course://Variables_and_Basic_Types/Compound_Types/Reference_Type)
      的 function call 或 operator expression
      (returned reference 最终可以上溯至某个 named object, 所以也可以视为拥有 name)
- **xvalue**
  - 即 eXpired value (过期值).
    Expired 意味着一个 named object 即将被 destroyed.
    因此, rvalue 的 members 都是 expired 的.
    虽然作为 members 肯定都有 names, 但 expired members 是 rvalue.
    因为它们是 expired, 不可以再被 assigned.
  - xvalue 是满足如下任一条件的 value/expression:
    - 拥有 name 但 expired 的 value (见 lvalue)
    - return type 为
      [rvalue reference](course://Variables_and_Basic_Types/Compound_Types/Reference_Type)
      的 function call 或 operator expression
      (returned reference 最终可以上溯至某个 named object, 所以也可以视为拥有 name)
- **prvalue**
  - 即 Pure Right value (纯右值).
    名称中的 pure 强调该 value 是原始纯粹的 rvalue 
    (不像 xvalue, 原本为 lvalue, 因为所属 object 是 rvalue 才成为 rvalue).
  - prvalue 是满足如下任一条件的 value/expression:
    - 没有 name 的 value, 如 literals
    - return type 为 non-reference 的 function call 或 operator expression
    
其中, xvalue 和 prvalue 共同构成了 rvalue.

## Mixed Value Categories

有时候人们会把上述 value categories 混合作为一个 value category, 最常用的就是 rvalue.

- **rvalue**
  - 是 xvalue 或 prvalue.
    即除了 lvalue 以外的 value 都是 rvalue.
- **glvalue**
  - 是 lvalue 或 xvalue.
    即所有拥有 name 的 value 都是 glvalue.
    而对于 lvalue 或 xvalue 里 return type 为 reference 的 function call 或 operator expression,
    那些 returned reference 必可上溯至某个 named object, 所以某种程度上也可以视为有 name.


See more on
[reference#value_categories](https://en.cppreference.com/w/cpp/language/value_category).