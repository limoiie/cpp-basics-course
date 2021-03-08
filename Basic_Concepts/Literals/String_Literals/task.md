# String Literals

## Syntax

String Literals 是 Character Literals 的数组. 有如下形式:

1. `"`*c-char-sequence*`"` (Type `const char[N]`)
2. `L"`*c-char-sequence*`"` (Type `const wchar_t[N]`)
3. `u"`*c-char-sequence*`"` (Type `const char16_t[N]`)
4. `U"`*c-char-sequence*`"` (Type `const char32_t[N]`)
5. *prefix*<strong>?</strong>`R"`(*raw-characters*)`"`

其中:

- *c-char-sequence* 是由一个或多个 *c-char* (见 [Character Literals](course://Basic_Concepts/Literals/Character_Literals)) 组成的序列
- *prefix* 就是 `u, U, L` 之一

## Explanation

1. `"`*c-char-sequence*`"` 是 Narrow Multibyte String Literal
2. `L"`*c-char-sequence*`"` 是 Wide String Literal
3. `u"`*c-char-sequence*`"` 是 UTF-16 编码的 String Literal
4. `U"`*c-char-sequence*`"` 是 UTF-32 编码的 String Literal
5. *prefix*<strong>?</strong>`R"`(*raw-characters*)`"` 
   是 Raw String Literal, 常用于书写正则表达式.
  在其内的 Escape Character 都不会被 Escape:
   - e.g. `R"(abc\n\tabc)" == "abc\\n\\tabc"`