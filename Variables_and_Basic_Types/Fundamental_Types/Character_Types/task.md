# Character Types

C++ 中最常见的 character type 是 `char`.
除此之外, C++ 还提供了更多不同 size
[(*demo*)](psi_element://CharactersType_Size_Test)
不同性质的 character types 以表示不同字符编码格式的 character:

- `signed char` size 8-bit, 表示 signed character
- `unsigned char` size 8-bit, 表示 unsigned character
- `char` size 8-bit, 表示能够被 target system 最有效率处理的 character;
  其 signedness 将由 compiler 与 target platform 而定 
  (ARM and PowerPC 上通常默认为 unsigned; x86 and x64 上通常默认为 signed)
- `wchar_t` size 32-bit (or 16-bit on Windows), 用于表示 wide character.
  其 size 一般足够大以表示任意支持的编码格式 
  (在支持 unicode 的 system 上为 32-bit; 而在 Windows 上则为 16-bit 用于表示 UTF-16 character)
- `char16_t` size 16-bit, 用于表示 UTF-16 character
- `char32_t` size 32-bit, 用于表示 UTF-32 character

以上 character types 中, 虽然 `char` 的 size, signedness 以及 alignment 与 `signed char` 或 `unsigned char` 之一一致, 但是它们是不同的 type.
`wchar_t` 与 `char16_t` 或 `char32_t` 也是同理
[(*demo*)](psi_element://CharacterTypes_Similarity_Test).

See more on [cppreference#types#character_types](https://en.cppreference.com/w/cpp/language/types)