# `const`- and `volatile`- Qualified Member Function

一个 member function 在 declare 时, 其 *parameter-list* 后可以加上 qualifier `const`, `volatile` 或 `const volatile`:
```c++
class cls {
    void foo() const volatile;
};
```
被不同的 cv-qualifier 修饰的 function 拥有不同的 type, 因此可以互相 overload:
```c++
class cls {
    void foo();
    void foo() const;
    void foo() volatile;
    void foo() const volatile;
};
```

在一个 `const` (/`volatile`, `const volatile`) qualified member function 内,
只能以同样 `const` (/`volatile`, `const volatile`) qualified 的形式来访问 pointer `this` 指向的 object (`*this`).
这就意味着:
- 通过一个 `const` (/`volatile`, `const volatile`) qualified type 的 object, 
  只能访问它的 `const` (/`volatile`, `const volatile`) qualified member functions
- 在 `const` (/`volatile`, `const volatile`) qualified member function body 内部, 
  只能访问 `const` (/`volatile`, `const volatile`) qualified member functions

当 member function 没有被 cv-qualified 时, 在它的 function body 内访问其所在 class 的其他 members 时没有任何限制.
