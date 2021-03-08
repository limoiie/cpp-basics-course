# Character Literals

## Syntax

对应于不同的 Character Types, Character Literals 有多种形式:

1. `'`*c-char*`'` (Type `char`)
2. `u'`*c-char*`'` (Type `char16_t`)
3. `U'`*c-char*`'` (Type `char32_t`)
4. `L'`*c-char*`'` (Type `wchar_t`)
5. `'`*c-char-sequence*`'` (Type `int`)
6. `L'`*c-char-sequence*`'` (Type `wchar_t`)

其中:

- *c-char* 
  - 任一来自 Source Character Set 的 Character (e.g. `a, b, +, -, ...`)
  - 任一 [Escaped Sequence](https://en.cppreference.com/w/cpp/language/escape) (e.g. `\t, \r, ...`)
  - 任一 [Universal Character](https://en.cppreference.com/w/cpp/language/escape) (e.g. `...`)
- *c-char-sequence* - 一个或多个 *c-char*s

## Explanation

1. `'`*c-char*`'` 用于表示普通的 Character Literal 
   - e.g. `'a', '\n', '\13', ...`
2. `u'`*c-char*`'` 用于表示 UTF-16 Character Literal
   - e.g. `u'貓'`
3. `U'`*c-char*`'` 用于表示 UTF-32 Character Literal
   - e.g. `U'貓'` 或 `U'🍌'`
4. `L'`*c-char*`'` 用于表示 Wide Character Literal
   - e.g. `L'β'` 或 `L'貓'`
5. `'`*c-char-sequence*`'` 普通的 Multi-Character Literal; 极少用到, 依情况支持
    - e.g. `'AB'`
6. `L'`*c-char-sequence*`'` Wide Multi-Character Literal; 极少用到, 依情况支持
    - e.g. `L'AB''`
