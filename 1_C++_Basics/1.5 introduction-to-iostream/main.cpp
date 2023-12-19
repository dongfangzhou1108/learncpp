/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2023-12-19 16:20:07
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2023-12-19 17:19:20
 * @FilePath: /learncpp/1_C++_Basics/1.5 introduction-to-iostream/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/

#include <iostream> // for std::cout and std::cin

int main() {

  /*
   * 测试用例(1)输入1个数字，enter，再输入一个数字：正常
   * 测试用例(2)输入3个数字，enter，识别出前两个：正常
   * 测试用例(3)输入1个数字，1个字母：第一个数正常，第二个数为0
   * 测试用例(4)先输入整数，后输入小数：第2个数小数部分截断
   * 测试用例(5)先输入小数，后输入整数，第一个小数截断，第二个数为0
   */

  std::cout << "Enter two numbers separated by a space: ";

  int x{}; // define variable x to hold user input (and value-initialize it)
  int y{}; // define variable y to hold user input (and value-initialize it)
  std::cin >> x >>
      y; // get two numbers and store in variable x and y respectively

  std::cout << "You entered " << x << " and " << y << '\n';

  // TODO how std::cin handles invalid input
  // https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/

  return 0;
}