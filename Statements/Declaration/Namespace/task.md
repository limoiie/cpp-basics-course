# Namespace

Namespaces (命名空间) 提供了一种可以避免 name conflict 的方法, 这在大型项目中非常有用.
在不同 namespaces 里, 可以 declare 具有相同 name 的 symbols.

## Syntax

除了正常使用的 namespace, C++ 还提供了两种特殊的 namespaces: inline namespace 和 anonymous namespace.
它们的 syntax 如下所示

- Definitions of namespaces:
  - `namespace` *ns_name* `{` *ns_body* `}` [*(demo)*](psi_element://Namespace_Namespace_Test)
  - inline `namespace` *ns_name* `{` *ns_body* `}` [*(demo)*](psi_element://Namespace_InlineNamespace_Test)
  - `namespace` `{` *ns_body* `}` [*(demo)*](psi_element://Namespace_AnonymousNamespace_Test)

- Accessing the *name* in a namespace:
  - *ns_name*`::`*name*

## Explanation

- Definitions of namespaces:
    - `namespace` *ns_name* `{` *ns_body* `}`<br>
      是正常的 namespace definition;
      在其中 declared 的 names 会被放置在一个 scope named *ns_name* 中;

    - inline `namespace` *ns_name* `{` *ns_body* `}`<br>
      是 inline namespace definition; 在该 namespace 内的 names 对于其 enclosing namespace 也是可见的;
      
    - `namespace` `{` *ns_body* `}`<br>
      是 anonymous namespace definition; 在该 namespace 内的 names 对于其 enclosing namespace 也是可见的;
      - anonymous namespace 与 inline namespace 的区别是: 前者只能通过 enclosing namespace 访问到其内部的 names;
        而后者则还可以通过正常的 namespace 
        
- Accessing the name in a namespace
  - *ns_name*`::`*name*<br>
    如此访问 namespace 内的 name; 若 namespace 有多层时, 各层 namespace 的 *ns_name* 也是通过 `::` 串联起来
