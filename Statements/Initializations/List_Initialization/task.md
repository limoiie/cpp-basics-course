# List Initialization

当 object 在 construction 时指定 list-initializer 时, default initialization (默认初始化) 会被执行.

## Syntax

### direct-list-initialization

1. *T* *object* **{** *args*, ... **} ;**
2. *T* **{** *args*, ... **}**
3. `new` *T* **{** *args*, ... **}**
4. *Class* `::` *Class* **(**...**)** `:` *member* **{** *args*, ... **}** **{** ... **}**

### copy-list-initialization

1. *T* *object* = **{** *args*, ... **} ;**
2. *function* **(** **{** *args*, ... **}** **)**
3. `return` **{** *args*, ... **}** **;**

## Explanation

### direct-list-initialization

如下列情况下会执行 direct list initialization:

1. *T* *object* **{** *args*, ... **} ;**
    - 当 define a variable 而 initializer 为 list-initializer 时
2. *T* **{** *args*, ... **}**
    - 当 create a nameless temporary 而 initializer 为 list-initializer 时
3. `new` *T* **{** *args*, ... **}**
    - 当调用 `new` 来 create an object 而 initializer 为 list-initializer 时
4. *Class* `::` *Class* **(**...**)** `:` *member* **{** *args*, ... **}** **{** ... **}**
    - 当 initialize a data member 而 initializer 为 list-initializer 时

### copy-list-initialization

如下列情况下会执行 copy list initialization:

1. *T* *object* = **{** *args*, ... **} ;**
    - 当 define a variable 而 initializer 为 "`=` list-initializer" 时
2. *function* **(** **{** *args*, ... **}** **)**
    - 当 pass argument by value 而 initializer 为 list-initializer 时
3. `return` **{** *args*, ... **}** **;**
    - 当 return result as value 而 initializer 为 list-initializer 时

## Effect

List initialization 会这样 initialize an object of type `T`:
- 如果 `T` 是一个 aggregate class, 而且 list-initializer 只有一个元素, 
  - 那么 object 会被
  [copy initialized](course://Statements/Initializations/Copy_Initialization)
  (for copy-list-initialization)
  或
  [direct initialized](course://Statements/Initializations/Direct_Initialization)
  (for direct-list-initialization)
- 如果 `T` 是一个 
  [aggregate type](https://en.cppreference.com/w/cpp/language/aggregate_initialization),
  - 那么 
  [aggregate initialization](course://Statements/Initializations/Aggragate_Initialization)
  会被执行
- 如果 `T` 是 `std::initializer_list` 的一个特化 (specialization),
  - 那么 object 会被
  [copy initialized](course://Statements/Initializations/Copy_Initialization)
  (for copy-list-initialization)
  或
  [direct initialized](course://Statements/Initializations/Direct_Initialization)
  (for direct-list-initialization)
- 如果 `T` 是一个 class type, 而且 `T` 有 constructor 接收 `std::initializer_list`
  - 那么对应的 constructor 会被调用来 initialize object
- 如果 `T` 是一个 non-class type, 而且 list-initializer 只有一个元素
  - 那么 object 会被
    [copy initialized](course://Statements/Initializations/Copy_Initialization)
    (for copy-list-initialization)
    或
    [direct initialized](course://Statements/Initializations/Direct_Initialization)
    (for direct-list-initialization)
- 如果 list-initializer 为 `()` 或 `{}`, 那么 object 会被
  [value initialized](course://Statements/Initializations/Value_Initialization)
