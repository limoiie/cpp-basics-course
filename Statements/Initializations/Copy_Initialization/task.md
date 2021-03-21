# Copy Initialization

当 object 在 construction 时指定 initializer 为 other object 时, copy initialization (复制初始化) 会被执行.

## Syntax

1. *T* *object* `=` *other* **;**
2. `f` **(** *T* *other* **)**
3. `return` *other* **;**
4. *T* *array* **\[** *N* **\]** = **{** *other* **} ;**

## Explanation

1. *T* *object* = *other* **;**
   - 当 define a variable 而 initializer 形为 "`=` *other*" 时
2. `f` **(** *T* *other* **)**
   - 当 pass argument by value 时
3. `return` *other* **;**
   - 当 return result as value 时
4. *T* *array* **\[** *N* **\]** = **{** *other* **} ;**
   - 当 define an array 而 initializer 形为 "`=` **{** *other* **}**" 时
   
## Effect 

Copy initialization 会这样 initialize an object of type `T`:
- 如果 `T` 是一个 class type
  - 而且 *other*'s type 在去掉 cv-qualifier 之后也是 `T` (或 derived from `T`), 那么 class 对应的
    [copy constructor](course://Classes/Constructors/Copy_Constructor)
    会被调用 (有的话) 来 initialize object;
  - 而且 *other*'s type 在去掉 cv-qualifier 之后不是 `T` (或 derived from `T`), 
    - 而且 *other*'s type 也是一个 class type,
      那么对应的
      [user-defined conversion sequence](course://Expressions/Conversions/User_Defined_Conversion)
      会被执行 (有的话) 来 initialize object;
- 如果 `T` 是一个 array type, 那么 array 的每一个元素都会被 copy-initialized
- 否则的话,
  [standard conversion](course://Expressions/Conversions/Standard_Conversion)
  会被执行来 initialize object
  