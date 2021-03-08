# A More Real Class

上个例子里 Class `Address` 被声明和定义在 cpp File 中, 这意味着 Class `Address` 只会在当前文件中使用 (除非有人 `#include` 这个 cpp File!).
但在实际项目中, Class 会被定义在 Header File 从而可以被其他 Source File 看见 (`#include`) 并使用.

左边的项目在上一个例子的基础上进行了调整, 从而更加贴近真实案例.
项目中定义了:

- Class [Address](psi_element://Address)
  - [Address.h](source://src/Address.h) 里是该 Class 的 Definition
  - [Address.cpp](source://src/Address.cpp) 里是该 Class 的 Implementation
- Function [create_dummy_address()](psi_element://create_dummy_address),
  用于创建一个 Class [Address](psi_element://Address) 的 Object 
  - [create_dummy_address.h](source://create_dummy_address.h) 里是该 Function 的 Declaration;
    同时, 因为使用到了 Class `Address` 作为 Return Type, 这里需要一个 Class `Address` 的 Declaration
  - [create_dummy_address.cpp](source://create_dummy_address.cpp) 里是该 Function 的 Definition;
    同时, 因为使用到了 Class `Address` 的具体 Member, 所以 Class `Address` 的 Definition 在这里必须可见.
    因此, 这里需要 `#include "Address.h"`
- Function [main()](psi_element://main)
  - [main.cpp](src/main.cpp) 调用 Function [create_dummy_address()](psi_element://create_dummy_address) 创建一个 Class [Address](psi_element://Address) 的 Object,
    并调用该 Object 的 Member Function [print_info()](psi_element://Address::print_info)

为方便解析 Class 的三个部分, 现将项目剪切如下:

```c++
//// File create_dummy_address.h
struct Address; // 1. Declaration
Address *create_dummy_address();
// ^
// +-- 3. Use only the Type

//// File Address.h
struct Address { // 2. Definition
    // ...
};

//// File create_dummy_address.cpp
Address *create_dummy_address() {
    Address *p_a = new Address(); // 4. Use the Member
    // ...
}

//// File Address.cpp
void Address::print_info() { // 5. Implementation
    // ...
}
```

1. *Declaration*: 需要指定 Class 的名称 **Symbol**
2. *Definition*: 需要给出所有 Member Variable 和 Member Function 的 **Declaration**
3. *Use Only the Type*: 当只是将 Class 当作一个 Type, 而不 Access 任何其 Member 时, 只需要看见 *Declaration* 即可 
4. *Use the Members*: 当 Use 了任意 Member, 整个 Class 的 **Definition** 就需要对 Use Site (使用的地方) 可见
5. *Implementation*: 可以在 *Definition* 内部, 也可以单独放到一个 Source File 中. 
   前者在 Header File 中, 修改 *Implementation* 时会导致 `#include` 该 Header File 的所有 Source File 都重新编译;
   后者就可以极大程度避免这种情况.