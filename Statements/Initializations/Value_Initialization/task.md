# Value Initialization

当 object 在 construction 时指定 empty initializer 时, value initialization (值初始化) 会被执行.

## Syntax

1. *T* *object* **{} ;**
2. *T* **{}**<br>
   *T* **()**
6. `new` *T* **{}**<br>
   `new` *T* **()**
4. *Class* `::` *Class* **(**...**)** `:` *member* **{}** **{** ... **}**<br>
   *Class* `::` *Class* **(**...**)** `:` *member* **()** **{** ... **}**
   
## Explanation

Empty initializer 即为 **{}** or **()**.

1. *T* *object* **{} ;**
   - 当 define a variable 而指定 empty initializer 时
2. *T* **{}**<br>
   *T* **()**
   - 当 create a nameless temporary 而指定 empty initializer 时
6. `new` *T* **{}**<br>
   `new` *T* **()**
   - 当调用 `new` 来 create an object 而指定 empty initializer 时
4. *Class* `::` *Class* **(**...**)** `:` *member* **{}** **{** ... **}**<br>
   *Class* `::` *Class* **(**...**)** `:` *member* **()** **{** ... **}**
   - 当 initialize a data member 而指定 empty member initializer 时

## Effect

Value initialization 会这样 initialize an object of type `T`:
- 如果 `T` 是一个 class type,
  - 且 `T` 没有可用的
    [default constructor](course://Classes/Constructors/Default_Constructor) 时,
    object 会被 default-initialized
  - 且 `T` 有一个可用的
    [default constructor](course://Classes/Constructors/Default_Constructor) 时,
    object 会先被 zero-initialized 然后被 default-initialized
- 如果 `T` 是一个 array type, 那么 array 的每一个元素都会被 value-initialized;
- 否则, object 会被 zero-initialized