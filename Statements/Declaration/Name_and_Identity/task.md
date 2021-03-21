# Name and Identity

## Identity

根据 cppreference 的定义:

> An *identifier* is an arbitrarily long sequence of digits, underscores, lowercase
> and uppercase Latin letters, and most Unicode characters. 
> *-- by [cppreference#identity](https://en.cppreference.com/w/cpp/language/identifiers)*

在 declaration 中, identity 用于命名 (name): 
- 各种 entities: objects, references, functions, 
enumerators, types, class members, namespaces, templates, template specializations, 
parameter packs, and other entities;
- 各种 labels: goto labels, and other labels.

在 expression 中, identity 可被用作 expression.
Identity expression 的 value 就是 identity 对应的 variables, functions 等

## Name

Name 就是用下列之一来指代 (refer to) 一个 entity:
- an identity
- operator name
  - e.g. `operator+`, `operator bool`, `operator "" _km`
- a template name followed by its argument list 
  - e.g. `MyTemplate<int>`

每一个 entity name 都是通过一个 declaration statement 被引入到 program 当中.
每一个 label name 都是通过一个 goto/labeled statement 被引入到 program 当中.

多个 translation units 间的同一个 name 是否指代同一个 entity, 取决于 
[linkage](https://en.cppreference.com/w/cpp/language/storage_duration#Linkage).

## Qualified Identity/Name

Qualified identity/name 是指拥有如下前缀之一的 identity/name:
- scope resolution `::`
  - e.g. `::global_func(), ::global_var`
- 以 scope resolution `::` 分割的 enumeration, class or namespace names 序列
  - e.g.`std::string::npos`, `::std::cout`

## Qualifier vs Specifier

后续可能会经常看到 qualifier 和 specifier 这两个词, 它们都有 "修饰符" 的意思, 但仍有点区别.
简单来说, qualifier 会修改 name, 比如 cv-qualified `const int` 与 `int` 就是两种不同的 type.
而 specifier 只为 name 附加属性而不更改 name, 比如 `inline void f()` 与 `void f()` 仍是同一个 function `f` (这从不能同时拥有这两种 functions 可以看出).
