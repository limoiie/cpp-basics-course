# String Literals

String literals 是由 character literals 组成的数组
[(*demo*)](psi_element://StringLiterals_String_Test),
支持多行书写
[(*demo*)](psi_element://StringLiterals_MultiLineString_Test).

## Syntax of Literals

详尽的 syntax 如下:

1. `"`*c-char-sequence*`"` (with type `const char[N]`)
2. `L"`*c-char-sequence*`"` (with type `const wchar_t[N]`)
3. `u"`*c-char-sequence*`"` (with type `const char16_t[N]`)
4. `U"`*c-char-sequence*`"` (with type `const char32_t[N]`)
5. *prefix*<strong>?</strong>`R"`(*raw-characters*)`"`

其中:

- *c-char-sequence* 是由一个或多个 *c-char* 
  (见 [task Character Literals](course://Variables_and_Basic_Types/Literals/Character_Literals)) 组成的序列
- *prefix* 就是 `u, U, L` 之一

## Explanation

1. `"`*c-char-sequence*`"` 
   - narrow multibyte string literal
2. `L"`*c-char-sequence*`"` 
   - wide string literal
3. `u"`*c-char-sequence*`"` 
   - UTF-16 string literal
4. `U"`*c-char-sequence*`"` 
   - UTF-32 string literal
5. *prefix*<strong>?</strong>`R"`(*raw-characters*)`"` 
   - raw string literal;
     在其内的 escape character 都不会被 escape
     [(*demo*)](psi_element://StringLiterals_RawStringLiteral_Test), 
     常用于书写正则表达式
