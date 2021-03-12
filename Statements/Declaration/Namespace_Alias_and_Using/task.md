# Namespace Alias and Using

当 namespace qualifier 因嵌套多层等原因变得冗长时, C++ 提供了多种访问 namespace 的快捷方式.

## Syntax

Uses of namespaces:

- `using namespace` *ns_name* ; [(*demo*)](psi_element://NamespaceAliasUsing_UseNamespace_Test)
- `using` *ns_name*`::`*name* ; [(*demo*)](psi_element://NamespaceAliasUsing_UseName_Test)
- `namespace` *new_ns_name* = *ns_name* ; [(*demo*)](psi_element://NamespaceAliasUsing_NamespaceAlias_Test)
- `using` *new_name* = *ns_name*`::`*name* ; [(*demo*)](psi_element://NamespaceAliasUsing_NamespaceAlias_Test)

## Explanation

- `using namespace` *ns_name* ;<br>
  将 namespace *ns_name* 中的 names 全都引入到 `using` 所在的 namespace 中;
- `using` *ns_name*`::`*name* ;<br>
  仅引入 namespace *ns_name* 中的 *name*;
- `namespace` *new_ns_name* = *ns_name* ;<br>
  为 namespace 创建 alias
- `using` *new_type_name* = *ns_name*`::`*type* ;<br>
  为 namespace 中的 type 创建 type alias; type alias 与 type 是完全等价的