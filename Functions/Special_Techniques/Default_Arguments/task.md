# Default Arguments

C++ 支持为 function 指定 default arguments (默认传参), 在调用 function 时可以略去指定了 default value 的 arguments. 
如此, 这些被略去的 arguments 就会被 default value 所代替 [(*demo*)](psi_element://DefaultArguments_Simple_Test).

## Calling Function with Default Arguments

Function 的 arguments 是按照 positions 来与 parameter-list 一一对应的.
因此, 当略去了某一个 argument, 在其右边的 arguments 同时都得被略去; 否则, 右边的 arguments 会发生错位.
- 如 [*demo*](psi_element://DefaultArguments_RightMost_Test) 里的一处调用 `foo(1, "ss")`, 
  其只略去了第二个 argument `b`, 所以原本是第三个 argument `c` 的值 `"ss"` 处在了第二位, 这导致 `"ss"` 将会被传给 `b`, 从而发生匹配失败.

也因此, 指定了 default arguments 的 parameters 必须全部集中在 *parameter-list* 的末尾 (trailing, or, right-most).

## Default Arguments in Multi-Declarations

每个 function 可以有多个 re-declarations, 每个 re-declaration 都可以指定 default arguments. 
- re-declarations 不可以 redefine 当前 scope 已有的 default arguments, 即使 default value 保持一致 [(*demo*)](psi_element://DefaultArguments_MultiDeclarationsSameScope_Test)
- 在保证上一条成立的情况下, re-declarations 可以 redefine 其他 scope 已有的 default arguments [(*demo*)](psi_element://DefaultArguments_MultiDeclarations_Test)

通常的做法是, 将 function declaration 放在合适的 header file 里, 且一并指定 default arguments.