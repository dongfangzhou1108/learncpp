/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2023-12-22 11:24:28
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2023-12-22 11:48:18
 * @FilePath: /learncpp/2 Functions and Files/2.2
 * function-return-values-value-returning-functions/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// #include <cstdlib> // for EXIT_SUCCESS and EXIT_FAILURE
// 如果要最大限度地提高可移植性，则应仅使用 0 或 EXIT_SUCCESS
// 表示成功终止，或使用 EXIT_FAILURE 表示终止不成功。

// don’t repeat yourself [DRY]: 简洁易于维护
#include <iostream>

int returnFive() { return 5; }

int main() {
  // 以下两种形式都代表函数地址
  std::cout << returnFive << '\n';
  std::cout << &returnFive << '\n';

  return 0;
}