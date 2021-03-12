# Initialization

## Two Ways to Initialize Member Variables

Non-static member variables 有两种 initialization 的方式:

- 通过 default-member-initializer
  - `{}` initializer
    - e.g.
      如 [*demo*](psi_element://MemberVarInitialization_Initialization_Test) 中 `class coffee` 对
      member variable `milk_percentage, sugar_percentage` 的 initialization
      ```c++
      double milk_percentage { 0.0 };
      double sugar_percentage {};
      ``` 
  - `=` initializer
    - e.g.
      如 [*demo*](psi_element://MemberVarInitialization_Initialization_Test) 中 `class coffee` 对
      member variable `brand` 的 initialization
      ```c++
      std::string brand = "Nescafe";
      ```

- 通过 constructor 的 member-initializer-list
    - e.g.
      如 [*demo*](psi_element://MemberVarInitialization_Initialization_Test) 中 `class coffee` 对
      member variables `price, cup_size, maker` 的 initialization:
      ```c++
      // constructor
      coffee(double price, 
             Cup cup_size, 
             employee const&maker)
              : price(price)
              , cup_size(cup_size)
              , maker(maker) {
      }
      ```

若一个 member variable 既有 default-member-initializer 又出现在某个 constructor 的 member-initializer-list 里,
那么当调用这个 constructor 来构造 object 时, default-member-initializer 将被忽略 [(*demo*)](psi_element://MemberVarInitialization_OverwriteInitialization_Test).

## Order of Initialization

一个 class 里 non-static member variables 的 initialization 顺序只有一个: 
按照在 class 中 declaration 的先后顺序 [(*demo*)](psi_element://MemberVarInitialization_Order_Test).

因此, 为了不引起歧义, 建议 constructor 的 member-initializer-list 按照 declaration 的顺序排序.
