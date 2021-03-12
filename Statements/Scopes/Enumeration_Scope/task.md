# Enumeration Scope

## UnScoped Enum Scope

在 un-scoped enum 的 definition 中, 被 `{}` 所包裹起来的区域 (即 enum body), 再加上 `}` 后的 namespace scope 就是 un-scoped enum scope.

在 un-scoped enum scope 中 declared 的 name 的 potential name-scope 从 declaration 所在的点开始、所在的点开始、直到 un-scoped enum scope 末尾结束.

## Scoped Enum Scope

在 scoped enum 的 definition 中, 被 `{}` 所包裹起来的区域 (即 enum body) 就是 scoped enum scope. 

在 scoped enum scope 中 declared 的 name 的 potential name-scope 从 declaration 所在的点开始、所在的点开始、直到 scoped enum scope 末尾结束.
