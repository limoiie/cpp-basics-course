# Class Scope

在 class 的 definition 中, 被 `{}` 所包裹起来的区域 (即 class body),
后面再拼接上所有 member functions 的 function scopes 就构成了 class scope.

在 class scope 中 declared 的 name 的 potential name-scope 从 declaration 所在的点开始、直到 class scope 末尾结束.

根据 class scope 的定义可知, 所有的 member function scopes 集中在 class scope 的尾端.
因此, 在其中 declared 的 name 将对所有 member functions 的 function scopes 都可见.