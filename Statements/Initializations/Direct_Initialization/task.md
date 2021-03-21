# Direct Initialization

当 object 在 construction 时指定 initializer 为其某个 constructor 的 arguments 时, direct initialization (直接初始化) 会被执行.

## Syntax

1. *T* *object* **(** *args*, ... **) ;**<br>
2. *T* *object* **{** *arg* **} ;**
3. *T* **(** *args*, ... **) ;**
4. `new` *T* **(** *args*, ... **)**
5. *Class* `::` *Class* **(**...**)** `:` *member* **(** *args*, ... **)** **{** ... **}**

## Explanation

在下列情况下 direct initialization 会被执行:

1. *T* *object* **(** *args*, ... **) ;**
   - 当 define a variable 而 initializer 为 `T` 某个 constructor 的 arguments 时
2. *T* *object* **{** *arg* **} ;**
   - 当 define a variable 而 T 为 non-class type 时
3. *T* **(** *args*, ... **) ;**
   - 当 create a temporary object 而 initializer 为 `T` 某个 constructor 的 arguments 时
4. `new` *T* **(** *args*, ... **)**
   - 当调用 `new` 来 create an object 而 initializer 为 `T` 某个 constructor 的 arguments 时
5. *Class* `::` *Class* **(**...**)** `:` *member* **(** *args*, ... **)** **{** ... **}**
   - 当 initialize a data member 而 initializer 为 `T` 某个 constructor 的 arguments 时
    
## Effect

Direct initialization 会这样 initialize an object of type `T`:
- 如果 `T` 是一个 class type, 那么 `T` (或 base type) 对应的 constructor 会被调用来 initialize object;
- 如果 `T` 是一个 array type, 那么 program 是 ill-formed (不能被成功 compiled);
- 如果 `T` 是一个 non-class type, 且只有一个 `arg`
  - 而且 arg type 是一个 class type, 那么对应的
    [conversion operator](course://Functions/Operator_Functions/Overload_Type_Conversion_Operators)
    会被调用来 initialize object;
  - 而且 arg type 是 `std::nullptr_t` 同时 `T` 是 bool, 那么 value 会被 initialized as `false`
- 否则,
  [standard conversions](course://Expressions/Conversions/Standard_Conversion)
  会被执行来 initialize object