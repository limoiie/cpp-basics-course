# Character Types

C++ 中最常见的 Character Type 是 `char`.
除此之外, C++ 还提供了更多的 Character Types 以表示不同字符编码格式的 Character:

- `signed char` Size 8-bit, 表示 Signed Character
- `unsigned char` Size 8-bit, 表示 Unsigned Character
- `char` Size 8-bit, 表示能够被 Target System 最有效率处理的 Character;
  其 Signedness 将视 Compiler 与 Target Platform 而定 
  (ARM and PowerPC 上通常默认为 Unsigned; x86 and x64 上通常默认为 Signed).
  虽然 `char` 的 Size, Signedness 以及 Alignment 与 `signed char` 或 `unsigned char` 之一一致, 但是不同的 Type
- `wchar_t` Size 32-bit (or 16-bit on Windows), 用于表示 Wide Character.
  其 Size 一般足够大以表示任意支持的编码格式 
  (在支持 Unicode 的 System 上为 32-bit; 而在 Windows 上则为 16-bit 用于表示 UTF-16 Character)
- `char16_t` Size 16-bit, 用于表示 UTF-16 Character
- `char32_t` Size 32-bit, 用于表示 UTF-32 Character

See more on [cppreference#types#character_types](https://en.cppreference.com/w/cpp/language/types)