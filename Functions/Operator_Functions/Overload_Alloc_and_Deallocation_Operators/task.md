# Overload Allocation and Deallocation Operators

Allocation/Deallocation operators 被用来在 heap 上创建/释放指定大小的 memory space.

详情请见 [reference#operator new](https://en.cppreference.com/w/cpp/memory/new/operator_new), 本文不作涉猎.

**注意**: 该 `operator new/delete` 并不是我们在 heap 上创建 object 时所用的 keyword `new`.
后者会先调用前者创建 memory space, 然后根据 initialization strategy 调用合适的 constructor 来 initialize 刚创建出来的 memory space;

## Syntax

1. `operator new` <br>
   `operator new` *[]*
2. `operator delete` <br>
   `operator delete` *[]*