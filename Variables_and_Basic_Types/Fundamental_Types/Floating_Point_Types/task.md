# Floating Point Types

C++ 中用 floating point types (浮点数类型) 表示小数:

- `float` size 32-bit, single precision floating point type (单精度浮点数类型)
- `double` size 64-bit, double precision floating point type (双精度浮点数类型);
  与 `float` 相比, `double` 可表示范围更广、粒度更细的小数
- `long double` size 128-bit, extended precision floating point type (扩展精度浮点数类型); 
  在 x86 和 x86-64 Platform 上通常为 80-bit x87 floating point type
  
C++ 提供了一些 Floating Point Types 相关的特殊常量, 以支持日常计算:

- *`INFINITY`*
  - 无穷大, 可由 非零数 `/ 0.0` 得到
  [(*demo*)](psi_element://FloatingPointTypes_DivideZero_Test);
- *`NAN`*
  - 非数, 可由 `0.0 / 0.0` 得到; 它不等于任何数 (甚至它自己)
  [(*demo*)](psi_element://FloatingPointTypes_NanNotEqualNan_Test);
- `-0.0`
  - 负零; `-0.0` 与 `0.0` 在比较时相等 , 可用于产生负无穷大 *`-INFINITY`*
    [(*demo*)](psi_element://FloatingPointTypes_NegZeroEqualZero_Test)
