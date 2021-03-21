# Aggregate Initialization

当 initialize an object of aggregate type 且 initializer 为 list-initializer.

### Aggregate Type

Aggregate type (集合类型) 是如下 types:
- array type
- class type, 且满足:
    - 没有 private 或 protected non-static data members
    - 没有 user-declared 或 user-defined constructors
    - 没有 base classes
    - 没有 virtual member functions
    - 没有 default member initializers

## Syntax

1. *T* *object* **{** *args*, ... **} ;**
1. *T* *object* = **{** *args*, ... **} ;**

## Explanation

Aggregate initialization 会这样 initialize an object:

- `T` 中每一个 non-static members (或 array element -- 对于 array type 来说), 
  会按照它们在 class 中 declaration 的顺序, 与 list-initializer 中的每一个元素一一对应,
  并被 
  [copy-initialized](course://Statements/Initializations/Copy_Initialization)
  - 如果 list-initializer 的长度小于与 `T` 中 non-static members 的个数, 
    那么剩下的 members 会用 empty initializer-list 执行 copy-list-initialization.
