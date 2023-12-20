/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2023-12-20 09:01:53
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2023-12-20 09:26:09
 * @FilePath: /learncpp/1 C++ Basics/1.6
 * uninitialized-variables-and-undefined-behavior/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

int main() {
  // 未初始化，该变量的默认值是该内存地址中恰好已经存在的任何（垃圾）值
  // define an integer variable named x
  int x; // this variable is uninitialized because we haven't given it a value

  // print the value of x to the screen
  std::cout << x
            << '\n'; // who knows what we'll get, because x is uninitialized

	// Implementation-defined behavior [实现定义行为]，即语法行为由编译器决定，如sizeof(int)
	// 与 unspecified behavior [未定义行为]，一样，应该尽量避免
  return 0;
}