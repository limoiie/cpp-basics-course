# Ref-Qualified Member Function

一个 member function 在 declare 时, 其 *parameter-list* 后可以加上 qualifier `&`, 或 `&&`:
```c++
class cls {
    void foo() &;
    void foo() &&;
};
```

注意: ref-qualified member function 与 cv-qualified member function 无法互相 overload.

与 cv-qualifier 相同的是, 当通过一个 object 访问它的 qualified member 时, compiler 会首先尝试将该 object 的 type 转型成拥有 member's qualifier 的 type.
只有转型成功, 才能通过此 object 访问到此 qualified member. 
当受访 member 是 member function 时, 在该 function body 里所见到的 `this` object 的 type 也将是转型后的.
