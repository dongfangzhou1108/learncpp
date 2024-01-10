/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2024-01-10 14:10:56
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2024-01-10 14:32:30
 * @FilePath: /learncpp/4 Fundamental Data Types/4.8
 * floating-point-numbers/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// float 6-9 significant digits, typically 7 ±1.18 x 10-38 to ±3.4 x 1038 and
// 0.0 double 15-18 significant digits, typically 16 浮点数位数 按照有效位数
// 记录

// When outputting floating point numbers, std::cout has a default precision of
// 6 -- that is, it assumes all floating point variables are only significant to
// 6 digits (the minimum precision of a float), and hence it will truncate
// anything after that. 输出浮点数时，std：：cout 的默认精度为 6 -
// 也就是说，它假设所有浮点变量仅对 6
// 位（浮点数的最小精度）有效，因此它将截断之后的任何内容。

#include <iomanip> // for output manipulator std::setprecision()
#include <iostream>

int main() {
  // 1e+09 经过验证确实无法保存过多位数
  float f = 1000000001.1;
  std::cout << f << std::endl;

  // Output manipulators (and input manipulators) are sticky -- meaning if you
  // set them, they will remain set.
  // 输出操纵器（和输入操纵器）是粘性的，这意味着如果设置它们，它们将保持设置状态。
  std::cout << std::setprecision(17); // show 17 digits of precision
  std::cout << 3.33333333333333333333333333333333333333f
            << '\n';      // f suffix means float
  std::cout << f << "\n"; // 1000000000

  // Best practice 最佳实践
  // Favor double over float unless space is at a premium, as the lack of
  // precision in a float will often lead to inaccuracies.
  // 除非空间有限，否则最好使用双倍而不是浮点数，因为浮点数缺乏精度通常会导致不准确。

  // Rounding errors make floating point comparisons tricky
  // 浮点数很难使用，因为二进制（数据的存储方式）和十进制（我们的思维方式）数字之间存在不明显的差异。考虑分数
  // 1/10。在十进制中，这很容易表示为 0.1，我们习惯于将 0.1 视为具有 1
  // 位有效数字的易于表示的数字。但是，在二进制中，十进制值 0.1
  // 由无限序列表示：0.00011001100110011...因此，当我们将 0.1
  // 分配给浮点数时，我们会遇到精度问题。
  std::cout << std::setprecision(17);
  double d1{1.0};
  std::cout << d1 << '\n';
  double d2{0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 +
            0.1}; // should equal 1.0
  std::cout << d2 << '\n';

  // 关于舍入误差的最后一点说明：数学运算（如加法和乘法）往往会使舍入误差增加。因此，即使
  // 0.1 在第 17 位有效数字中有一个舍入误差，当我们将 0.1 加 10
  // 次时，舍入误差已经爬到了第 16
  // 位有效数字。继续操作将导致此错误变得越来越严重。
  // TODO 舍入误差对于SLAM影响
  // A corollary of this rule is: be wary of using floating point numbers for
  // financial or currency data.
  // 这条规则的推论是：谨慎使用浮点数来处理金融或货币数据。

  // https://float.exposed/0x3dcccccd
  // 如果您想更深入地了解浮点数如何以二进制形式存储，请查看此工具。

  // NaN and Inf: not a number(不是数字), infinity number(无穷大)
  // 完全避免除以 0.0，即使您的编译器支持它。

  // summary
  /*
   * Floating point numbers are useful for storing very large or very small
   * numbers, including those with fractional components.
   * 浮点数可用于存储非常大或非常小的数字，包括具有小数分量的数字。
   * Floating point numbers often have small rounding errors, even when the
   * number has fewer significant digits than the precision. Many times these go
   * unnoticed because they are so small, and because the numbers are truncated
   * for output. However, comparisons of floating point numbers may not give the
   * expected results. Performing mathematical operations on these values will
   * cause the rounding errors to grow larger.
   * 浮点数通常具有较小的舍入误差，即使数字的有效位数少于精度。很多时候，这些数字被忽视了，因为它们太小了，而且这些数字在输出时被截断了。
   * 但是，浮点数的比较可能无法给出预期的结果。对这些值执行数学运算将导致舍入误差变大。
   */
}