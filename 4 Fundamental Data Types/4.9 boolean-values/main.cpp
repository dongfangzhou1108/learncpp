/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2024-01-10 14:40:23
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2024-01-10 14:52:28
 * @FilePath: /learncpp/4 Fundamental Data Types/4.9 boolean-values/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// 布尔值实际上并不作为单词“true”或“false”存储在布尔变量中。相反，它们存储为整数：true
// 变成整数 1，false 变成整数
// 0。同样，当计算布尔值时，它们实际上不会计算为“true”或“false”。它们的计算结果为整数
// 0 （false） 或 1 （true）。由于布尔值实际上存储整数，因此它们被视为整数类型。

// std::cout << std::boolalpha; // print bools as true or false
// You can use std::noboolalpha to turn it back off.

#include <iostream>

int main() {
  // Inputting Boolean values
  // 只接受int作为输入, 输入小数后会被截断为整数
  // 经过验证内存中确实仅存储0/1
  bool b{}; // default initialize to false
  std::cout << "Enter a boolean value: ";
  std::cin >> b;
  std::cout << "You entered: " << b << '\n';
  // Allow the user to enter 'true' or 'false' for boolean values
  // This is case-sensitive, so True or TRUE will not work
  std::cin >> std::boolalpha;

  return 0;
}