# Static Member Variables

Static Member Variables (静态成员变量) 可以理解为拥有当前 class scope 的 global variables.
同一个 class 的 static member variables 与 objects 互相独立, 所有 objects 共享一份 static member variables.

## Declaration

Declare 一个 static member variable 的方式很简单, 只需要在 variable 的 declaration 之前加上 `static` 即可.
C++11 不允许在 class body 内对 static member variable 进行 initialization.
Constant static member variable 是个例外, 它必须在 declaration 处 initialization.

## Definition

Non-constant static member variables 的 initialization 需要在 class 外部进行.
与 global variables 的 definition 一样, non-constant static member variables 的 definition 需要放到合适的 cpp 文件中, 以免重复定义.

## Usage

使用 static member variables 的方式非常简单, class name 与 variable name 之间加上 `::` 即可.
