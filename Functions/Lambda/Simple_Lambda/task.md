# Simple Lambda

Lambda 本质上是一个 unnamed function object, 由 lambda expression 构建得到.

## Define a Simple Lambda

[*Demo*](psi_element://Lambda_Simple_Test) 提供了一个简单的例子, 其中的 `is_in_area` 就是一个 lambda.
Lambda `is_in_area` 的功能是判断所给的坐标 `x, y` 是否在给的区域内.
若是, 返回 `true`; 否则, 返回 `false`.

用来构建 lambda `is_in_area` 的 lambda expression 有着如下的形式:

**\[** *capture-list* **] (** *parameter-list* **)** `->` *return-type* **{** <br> 
&#20;&#20;&#20;&#20;*function-body* <br>
**}**

上述形式中的 *return-type*, *parameter-list* 和 *function-body* 与在 function definition 中的意义一致.

## Call a Lambda

调用 lambda 的方式与 function 完全一致: lambda name 加上与 *parameter-list* 相匹配的 arguments:

```c++ 
is_in_area(15, 15);
```

## Capture Variables 

Lambda 与 function 在功能上最大的不同是, lambda 可以通过 *capture-list* 来 capture 当前 scope 内的 variables.

上述 lambda `is_in_area` 的 *capture-list* 是 `&`, 这意味着以 reference 的方式捕获当前 scope 中所有的 variables.
因此, 在 lambda `is_in_area` 的 function body 里可以直接使用 lambda 外部的 variables (如 `top, right` 等).
这为后续的多次调用提供了极大的便利 -- 每次调用都可省去 4 个 variables (`top`, `right`, `top`, `bottom`) 的传递. 
