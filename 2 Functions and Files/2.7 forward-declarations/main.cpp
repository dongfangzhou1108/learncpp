/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2023-12-22 16:47:23
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2023-12-22 17:20:28
 * @FilePath: /learncpp/2 Functions and Files/2.7 forward-declarations/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// 函数的前向声明
// (1) 正向声明用于告知编译器是否存在已在不同代码文件中定义的某个函数 -
// 针对不同文件 (2) Forward declarations can also be used to define our
// functions in an order-agnostic manner - 针对不同定义顺序 (3) there are times
// when we have two functions that call each other - 解决函数循环依赖

// 类的前向声明 class foo;

// 变量的前向声明 extern int* foo;

#include <iostream>

extern int foo;
int main() {
  // 不允许在一个函数内部前向声明变量
  // extern int foo;
  int foo{0};

  std::cout << "[main]\n";
}