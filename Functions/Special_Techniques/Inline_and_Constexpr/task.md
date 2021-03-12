# The `inline` and `constexpr` Specifier

在真实项目中存在着很多非常简短但使用频率特别高的 functions.
这些 functions 甚至简短到其调用操作<sup>1</sup>本身就占了整个执行过程的一大半时间.

为了减少因 function 调用而产生的时间开销, C++ 提供了如下几个用来修饰 function 的 specifiers:
- `inline`
- `constexpr`

## The `inline` Specifier

被指定为 `inline` 的 function 通常会被 expanded *in line*, 这也是 `inline` 名字的由来.
一旦被 expanded *in line*, function 的调用就可被避免, 因此也就减少了 function 的调用次数.
指定 `inline` 的方式很简单, 只需要在 function declaration 前加上 `inline` 即可 [(*demo*)](psi_element://circle_area).

注意: 标记为 `inline` 的 functions 并不一定都会被 expanded *in line* 
- 大部分 compilers 是不会 inline 一个 recursive function 的, 因为这样的会陷入 expand 的死循环;
- 此外, compilers 会结合 function 的长度与调用频率等, 来估量其复杂度;
  复杂度超出一定阈值的 function 也不会被 inline;
  如有 75 行 statements 的 function, 即使指定了 `inline`, 通常也是不可能被 inline 的.

## The `constexpr` Specifier

被指定了 `constexpr` 的 function 可以被用在 constant expression 中 [(*demo*)](psi_element://InlineAndConstexpr_Constexpr_Test).
而 constant expression 则是可在 compilation 期间被计算的 expression, 其计算结果将被当作 constant 用来替换原来的 constant expression.

<sup>1</sup>回忆一下, function 的调用操作:
1. 需要为 function 创建对应的 stack 空间, 并在 function 退出时释放;
2. 需要保存 function context (registers, 等);
3. 需要 pass arguments, 必要时 by-copy;
4. 需要为 local variables 进行 initialization;
