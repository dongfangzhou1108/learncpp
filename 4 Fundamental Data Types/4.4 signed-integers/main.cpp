/*
 * @Author: dongfangzhou 18746061711@163.com
 * @Date: 2024-01-10 07:20:08
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2024-01-10 13:22:56
 * @FilePath: /learncpp/4 Fundamental Data Types/4.4 signed-integers/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

//  C++ 只保证整数具有特定的最小大小，而不是它们具有特定的大小

// 对于数学倾向，n 位有符号变量的范围为 -2^(n-1) 到 2^(n-1) -1。

// C++
// 标准做出了这样的笼统声明：“如果在计算表达式期间，结果未以数学方式定义或不在其类型的可表示值范围内，则行为未定义”。通俗地说，这称为溢出。

// Be careful when using integer division, as you will lose any fractional parts
// of the quotient.
// 使用整数除法时要小心，因为您将丢失商的任何小数部分。

// Many developers (and some large development houses, such as Google) believe
// that developers should generally avoid unsigned integers.
// unexpected behavior can result when you mix signed and unsigned integers
// 尽量不要使用无符号整数, 尤其不要混合使用
int main() {}