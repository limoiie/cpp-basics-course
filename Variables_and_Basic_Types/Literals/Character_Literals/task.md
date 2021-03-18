# Character Literals

## Syntax of Literal

对应于不同的 character types, character literals 有多种形式
[(*demo*)](psi_element://CharacterLiterals_Char_Test):

1. `'`*c-char*`'` (with type `char`)
2. `u'`*c-char*`'` (with type `char16_t`)
3. `U'`*c-char*`'` (with type `char32_t`)
4. `L'`*c-char*`'` (with type `wchar_t`)
5. `'`*c-char-sequence*`'` (with type `int`)
6. `L'`*c-char-sequence*`'` (with type `wchar_t`)

其中:

- *c-char* 
  - 任一来自 Source Character Set 的 character (e.g. `a, b, +, -, ...`)
  - 任一 [Escaped Sequence](https://en.cppreference.com/w/cpp/language/escape) (e.g. `\t, \r, ...`)
  - 任一 [Universal Character](https://en.cppreference.com/w/cpp/language/escape) (e.g. `...`)
- *c-char-sequence* - 一个或多个 *c-char*s

## Explanation

1. `'`*c-char*`'` 用于表示普通的 character literal 
   - e.g. `'a', '\n', '\13', ...`
2. `u'`*c-char*`'` 用于表示 UTF-16 character literal
   - e.g. `u'貓'`
3. `U'`*c-char*`'` 用于表示 UTF-32 character literal
   - e.g. `U'貓'` 或 `U'🍌'`
4. `L'`*c-char*`'` 用于表示 wide character literal
   - e.g. `L'β'` 或 `L'貓'`
5. `'`*c-char-sequence*`'` 普通的 multi-character literal; 极少用到, 依情况支持
    - e.g. `'AB'`
6. `L'`*c-char-sequence*`'` wide multi-character literal; 极少用到, 依情况支持
    - e.g. `L'AB''`
