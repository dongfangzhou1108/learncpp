/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2023-12-20 14:35:53
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2023-12-20 16:28:27
 * @FilePath: /learncpp/1 C++ Basics/1.9
 * introduction-to-literals-and-operators/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// 运算符 operator + 操作数 operands
// 按照操作数个数，可以分为 一元 Unary / 二元 Binary / 三元 Ternary / 空 Nullary

// 运算符关注 Return values and side effects
// Return values: int x = 5;
// side effects: std::cout << x; 将x打印到控制台

// Both operator= and operator<< (when used to output values to the console)
// return their left operand. Thus, x = 5 returns x, and std::cout << 5 returns
// std::cout. This is done so that these operators can be chained.
// 链式调用，返回对象本身(引用)，因此 = 重载，返回对象引用
int main() {}