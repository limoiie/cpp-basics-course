# Destructor

Destructor 是一类特殊的 non-static member function.
它会在一个 object 的 lifetime 结束时被调用, 用来释放在其整个 lifetime 里获取到的资源.

## Syntax

- *decl-specifier-seq*<b>?</b> **~** *class-name* **()**;
- *decl-specifier-seq*<b>?</b> **~** *class-name* **()** `= default`;
- *decl-specifier-seq*<b>?</b> **~** *class-name* **()** `= delete`;

其中,

- *class-name* 是当前的 class name
- *decl-specifier-seq*<b>?</b> 可选项, 是 `friend`, `inline`, `virtual` 的组合

## When Be Called

Destructor 什么时候会被调用? [(*demo*)](psi_element://Constructors_Destructor_Test)
1. program termination, for objects with static storage duration
2. thread exit, for objects with thread-local storage duration
3. end of scope, for objects with automatic storage duration and for temporaries whose life was extended by binding to a reference
4. delete-expression, for objects with dynamic storage duration
5. end of the full expression, for nameless temporaries
6. stack unwinding, for objects with automatic storage duration when an exception escapes their block, uncaught.

## Implicitly-Declared Default Destructor

当一个 class 没有 user-defined destructors 时, compiler 往往会为该 class 提供一个 inline public 的 default destructor.

## Implicitly-Deleted Default Destructor

对于一个 `class T` 来说, 当下列情况发生时, 它的 default destructor 将会被标记为 deleted:
- `T` 有一个 member 不能被 destructed
- `T` 的某一个 direct or virtual base class 不能被 destructed
- 没有可用(或可访问)的 destructor

当一个 class 的 destructor 被标记为 deleted 时, 
我们就只能使用 `new` 来创建其 object, 并且不能使用 `delete` 来释放它 [(*demo*)](psi_element://Constructors_DeletedDestructor_Test).

## Implicitly-Defined Default Destructor

当 implicitly-declared default destructor 没有被标记为 deleted 时, 那么 compiler 就会 implicitly define (generate and compile a function body) 它.
这个 implicitly-defined default destructor 的 function body 将为空.