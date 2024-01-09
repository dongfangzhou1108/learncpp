/*
 * @Author: 方洲 董 18746061711@163.com
 * @Date: 2024-01-09 21:55:53
 * @LastEditors: 方洲 董 18746061711@163.com
 * @LastEditTime: 2024-01-09 22:10:25
 * @FilePath: \learncpp\4 Fundamental Data Types\4.3
 * object-sizes-and-the-sizeof-operator\main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <iostream>
#include <vector>

//  sizeof
//  不包括对象使用的动态分配的内存 我们将在以后的课程中讨论动态内存分配
int main() {
  std::vector<int> vec;
  std::cout << sizeof(vec) << std::endl;
}