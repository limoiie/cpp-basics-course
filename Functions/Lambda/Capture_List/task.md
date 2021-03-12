# Capture List

Lambda expression 中的 *capture-list* 是一个以逗号隔开的 *capture elements* 序列.
这些 *capture elements* 指定了外部的哪些 names 被 capture 到了 lambda body 里, 从而可以在 lambda body 内被访问到.

Lambda 有两种 capture 方式:
- by-reference: 在 lambda body 里访问到的是 captured names 的 reference
- by-copy: captured names 会直接被 copy 到 lambda body 里

除了 *capture elements*, *capture-list* 还可以在列表开始指定一个 *capture-default*:
- `&` : 默认以 by-reference 的方式 capture 外部所有的 visible names [(*demo*)](psi_element://CaptureList_CaptureDefaultByReference_Test)
- `=` : 默认以 by-copy 的方式 capture 外部所有的 visible names [(*demo*)](psi_element://CaptureList_CaptureDefaultByCopy_Test)

## Syntax of *capture element*

每一个 *capture element* 基本上对应了一个 name, 具体 syntax 如下:

1. *identifier*
1. *identifier...*
1. *&identifier*
1. *&identifier...*
1. *this*

其中,
- *identifier* 就是 captured name

## Explanation for Syntax of *capture element*

1. 以 by-copy 的方式 capture *identifier* [(*demo*)](psi_element://CaptureList_CaptureByCopy_Test)
1. 以 by-copy 的方式 capture *identifier...* (Pack expansion)
1. 以 by-reference 的方式 capture *identifier* [(*demo*)](psi_element://CaptureList_CaptureByReference_Test)
1. 以 by-reference 的方式 capture *identifier...* (Pack expansion)
1. 以 by-reference 的方式 capture 当前 object 的所有 members [(*demo*)](psi_element://CaptureList_CaptureThis_Test)
