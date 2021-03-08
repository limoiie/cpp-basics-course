# Fundamental Types

在 C++ 里, 每一个 Data 都必须有一个 Type.
C++ 语言的内建 (built-in) 类型有:

- Boolean Type:
  > `bool` 布尔类型, 值为 `true` 或 `false`

- Character Types
  > - `char` or `char8_t`: 8-bit 字符, 用于表示 UTF-8 字符
  > - `char16_t`: 16-bit 字符, 用于表示 UTF-16 字符集
  > - `char32_t`: 32-bit 字符, 用于表示 UTF-32 字符集
  > - `wchar_t`: Win 系统上为 16-bit; 类 Unix, Mac 系统上 32-bit 字符

- Integer Types
  > Integer 的基本类型是 `int`. 它有两类**互相正交**的附加描述符:
  > - 符号 (Signedness, 指定符号描述符后, 基本类型 `int` 可以省略)
  >   - `signed`: 有符号, 默认值
  >   - `unsigned`: 无符号, 非负数
  >   
  > - 大小 (Size, 指定大小描述符后, 基本类型 `int` 可以省略)
  >   - `short`: 至少 16 bits
  >   - `long`: 至少 32 bits
  >   - `long long`: 至少 64 bits
  > 
  > **小提示**: 由于历史遗留问题, 不同的操作系统上 `int`, `long` 的大小并不统一.
  > 早期内存小时, `int` 是 16-bit, `long` 是 32-bit; 
  > 在 32-bit 的系统上时, `int` 是 32-bit, `long` 也是 32-bit;
  > 再后来 64-bit 系统上, `int` 还是 32-bit, 而 `long` 则已经是 64-bit 了. 
  > 更详细的描述请见 Hint: 
  <div class="hint">
    <table>
     <tr style="border-bottom: 1px solid black;">
      <th>Basic Type</th>
      <th>Equivalent Type</th>
      <th>C++ Standard</th>
     </tr>

     <tr>
      <td rowspan="4" style="border-bottom: 1px solid black">short int</td>
      <td>short</td>
      <td rowspan="6" style="border-bottom: 1px solid black">at least <strong>16</strong></td>
     </tr>
     <tr>
      <td>short int</td>
     </tr>
     <tr>
      <td>signed short</td>
     </tr>
     <tr>
      <td style="border-bottom: 1px solid black">signed short int</td>
     </tr>
     <tr>
      <td rowspan="2" style="border-bottom: 1px solid black">unsigned short int</td>
      <td>unsigned short</td>
     </tr>
     <tr>
      <td style="border-bottom: 1px solid black">unsigned short int</td>
     </tr>

     <tr>
      <td rowspan="3" style="border-bottom: 1px solid black">int</td>
      <td>int</td>
      <td rowspan="5" style="border-bottom: 1px solid black">at least <strong>16</strong></td>
     </tr>
     <tr>
      <td>signed</td>
     </tr>
     <tr>
      <td style="border-bottom: 1px solid black">signed int</td>
     </tr>
     <tr>
      <td rowspan="2" style="border-bottom: 1px solid black">unsigned int</td>
      <td>unsigned</td>
     </tr>
     <tr>
      <td style="border-bottom: 1px solid black">unsigned int</td>
     </tr>

     <tr>
      <td rowspan="4" style="border-bottom: 1px solid black">long int</td>
      <td>long</td>
      <td rowspan="6" style="border-bottom: 1px solid black">at least <strong>32</strong></td>
     </tr>
     <tr>
      <td>long int</td>
     </tr>
     <tr>
      <td>signed long</td>
     </tr>
     <tr>
      <td style="border-bottom: 1px solid black">signed long int</td>
     </tr>
     <tr>
      <td rowspan="2" style="border-bottom: 1px solid black">unsigned long int</td>
      <td>unsigned long</td>
     </tr>
     <tr>
      <td style="border-bottom: 1px solid black">unsigned long int</td>
     </tr>

     <tr>
      <td rowspan="4" style="border-bottom: 1px solid black">long long int</td>
      <td>long long</td>
      <td rowspan="6" style="border-bottom: 1px solid black">at least <strong>64</strong></td>
     </tr>
     <tr>
      <td>long long int</td>
     </tr>
     <tr>
      <td>signed long long</td>
     </tr>
     <tr>
      <td style="border-bottom: 1px solid black">signed long long int</td>
     </tr>
     <tr>
      <td rowspan="2" style="border-bottom: 1px solid black">unsigned long long int</td>
      <td>unsigned long long</td>
     </tr>
     <tr>
      <td style="border-bottom: 1px solid black">unsigned short long long</td>
     </tr>

    </table>
  </div>

- Floating Point Types
  浮点数, 用于表示非整形数:
  > - `float`: 单精度 32-bit 浮点数
  > - `double`: 双精度 64-bit 浮点数

- Void Type
  > `void`: 当无返回值时, 函数的 Return Type 需要标明 `void`; 仅此用例!

更多阅读：
[cppreference#types](https://en.cppreference.com/w/cpp/language/types),

<!--
  > - `std::nullptr_t`: 还记得 C 里 Null Pointer_Type 的值为 `NULL` (实际上是一个值为 0 的宏定义) 吗?
  > C++ 里已用一个全新的关键字 `nullptr` 来替代它。
  > 而 `std::nullptr_t` 就是 `nullptr` 的 Type.
-->
