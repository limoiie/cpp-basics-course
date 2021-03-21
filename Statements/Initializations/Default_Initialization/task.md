# Default Initialization

当 object 在 construction 时指定 no initializer 时, default initialization (默认初始化) 会被执行.

## Syntax 

1. *T* *object* **;**
2. `new` *T*

## Explanation

如下两种情况下会执行 default initialization:

1. *T* *object* **;**
    - 当 define a variable 而不指定 initializer 时
2. `new` *T*
   - 当调用 `new` 来 create an object 而不指定 initializer 时
    
## Effect

Default initialization 会这样 initialize an object of type `T`:
- 如果 `T` 是一个 class type, 那么 class 的 
  [default constructor](course://Classes/Constructors/Default_Constructor)
  会被调用 (有的话) 来 initialize object;
- 如果 `T` 是一个 array type, 那么 array 的每一个元素都会被 default-initialized;
- 否则, 不做任何事: automatic storage duration 的 object 将为 indeterminate values (任何值都有可能!).
