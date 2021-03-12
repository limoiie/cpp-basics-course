# Lambda Expression

如上一章节介绍, lambda expression 用来构建一个 lambda.
其完整的 syntax 如下所示:

## Syntax

1. **\[** *capture-list* **] (** *parameter-list* **)** `->` *return-type* **{** <br>
  &#20;&#20;&#20;&#20;*function-body* <br>
  **}**

2. **\[** *capture-list* **] (** *parameter-list* **)** **{** <br>
  &#20;&#20;&#20;&#20;*function-body* <br>
  **}**

3. **\[** *capture-list* **]** **{** <br>
  &#20;&#20;&#20;&#20;*function-body* <br>
  **}**

其中

- *capture-list* 是以逗号分隔的 *captures* (见下一章) 序列
- *parameter-list* 是 parameters 序列, 同 named functions
- *return-type* 是 return type, 同 named functions

## Explanation

1. 是最完整的 lambda syntax [(*demo*)](psi_element://LambdaExpression_SyntaxOne_Test)
2. 当 *return-type* 未指定时, compiler 会根据 *function-body* 中的 `return` 语句自动推断;
   若其中无 `return`, *return-type* 则为 `void` [(*demo*)](psi_element://LambdaExpression_SyntaxTwo_Test)
3. 当 *parameter-list* 为空时, 包裹其外的 `()` 也可以省略 [(*demo*)](psi_element://LambdaExpression_SyntaxThree_Test)