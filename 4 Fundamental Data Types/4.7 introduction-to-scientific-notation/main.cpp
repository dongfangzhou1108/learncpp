/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2024-01-10 14:00:20
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2024-01-10 14:03:10
 * @FilePath: /learncpp/4 Fundamental Data Types/4.7
 * introduction-to-scientific-notation/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// Because it can be hard to type or display exponents in C++, we use the letter
// ‘e’ (or sometimes ‘E’) to represent the “times 10 to the power of” part of
// the equation. For example, 1.2 x 10⁴ would be written as 1.2e4, and 5.9722 x
// 10²⁴ would be written as 5.9722e24.

// 3.14159 would be written as 3.14159e0. Since there are 6 numbers in the
// significand, this number has 6 significant digits.
// e前数字位数 = 有效数字

// When converting to scientific notation, trailing zeros after a decimal are
// considered significant, so we keep them: 科学计数法尾随0能够体现精度