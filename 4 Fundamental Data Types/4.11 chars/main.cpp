/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2024-01-10 16:25:20
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2024-01-10 16:34:47
 * @FilePath: /learncpp/4 Fundamental Data Types/4.11 chars/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

// In the meantime, you should only use ASCII characters when working with
// characters (and strings).

int main() {
  std::cout << "Input a keyboard character: "; // assume the user enters "abcd"
                                               // (without quotes)

  char ch{};
  std::cin >> ch; // ch = 'a', "bcd" is left queued.
  std::cout << "You entered: " << ch << '\n';

  // 没有等待输入, 直接使用缓冲区的剩余输入字符
  // Note: The following cin doesn't ask the user for input, it grabs queued
  // input!
  std::cin >> ch; // ch = 'b', "cd" is left queued.
  std::cout << "You entered: " << ch << '\n';

  return 0;
}