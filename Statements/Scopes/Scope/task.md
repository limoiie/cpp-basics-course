# Scope

在 C++ program 中, (绝大部分) scopes 是以 `{}` 界定的一块块区域 (可能并不连续).
每一个 scope 都为在其中 declared 的 names 限定了 potential name-scope<sup>1</sup> (潜在命名作用域):
在某一点 declare 的 name, 只在从该 declaration 点开始、直到所在 scope 末尾结束的这部分可见.

可将 scope 划分为如下几种:

1. Block scope
2. Function parameter scope
3. Namespace scope
4. Class scope
5. Enumeration scope
6. Template parameter scope

在前两种 scope 中 defined 的 variables/reference,
在进入 name-scope 时会发生 construction(/binding), 
并在退出 name-scope 时发生 deconstruction(/unbinding).

<sup>1</sup>: 这里的 name-scope 在 [cppreference](https://en.cppreference.com/w/cpp/language/scope) 中其实也是被称为 scope 的.
但是考虑到:
1. 广泛意义上的 scopes (如 block scope, namespace scope 等等) 的开闭符号清晰, 起止明确 (由 `{}` 界定); 
   而 declared name 的 scope 只是其 enclosing scope 的片段, 起止受后续 declaration 的影响 [(*demo*)](psi_element://Scopes_Scope_Test);
2. 广泛意义上的 scopes 限定了其内 declared name 的 scope;
   而这些 declared name 的 scope 并不具备为其他 name 限定 scope 的能力

所以, 广泛意义上的 scopes 和 declared name 的 scopes 在概念上实际是有所区别. 
为了更好地将两者区分开, 我们在后续章节中称后者为 name-scope, 
而任何不带 'name-' 前缀的 scope 都将指的是广泛意义上的 scope (如上列表).
