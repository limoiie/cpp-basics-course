# Floating Point Types

C++ 中的小数用 Floating Point Types.

- `float` Size 32-bit, single precision floating point type
- `double` Size 64-bit, double precision floating point type; 
  与 `float` 相比, `double` 可表示范围更广、粒度更细的小数
- `long double` Size 128-bit, extended precision floating point type; 
  在 x86 和 x86-64 Platform 上通常为 80-bit x87 floating point type
  
C++ 提供了一些 Floating Point Types 相关的特殊常量, 以支持日常计算:

- `INFINITY`: 用于表示无穷大, 任何非零数除以 `0.0` 都会得到 `INFINITY`;
- `-0.0`: 负零; `-0.0` 与 `0.0` 在比较时相等, 可用于产生负无穷大 `-INFINITY`;
- `NAN`: 用于表示非零数, 可由 `0.0 / 0.0` 得到; 它不等于任何 Type 的数 (甚至它自己);