# Namespace Scope

所有具有相同 qualified name 的 namespace 按照出现的先后顺序拼接在一起共同构成了一个 namespace scope.

在 namespace scope 中 declared 的 name 的 potential name-scope 从 declaration 所在的点开始、直到 namespace scope 末尾结束.
注意一个 name 可以通过 `using-directive` 直接或间接地拓展其 declaration 到多个 namespace 当中, 
所以其完整的 potential name-scope 是与这些 namespaces 对应的多个 potential name-scopes 的集合. 

C++ 的 source code 最上层的 scope ("file scope" 或 "global scope") 其实同样是一个 namespace,
因此也被称为 "global namespace scope".