/*
 * @Author: 方洲 董 18746061711@163.com
 * @Date: 2024-01-09 21:55:53
 * @LastEditors: error: error: git config user.name & please set dead value or
 * install git && error: git config user.email & please set dead value or
 * install git & please set dead value or install git install git && error: git
 * config user.email & please set dead value or install git & please set dead
 * value or install git install git && error: git config user.email & please set
 * dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-10 07:00:12
 * @FilePath: \learncpp\4 Fundamental Data Types\4.3
 * object-sizes-and-the-sizeof-operator\main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <iostream>
#include <vector>

//  sizeof
//  不包括对象使用的动态分配的内存 我们将在以后的课程中讨论动态内存分配

// 在现代机器上，基本数据类型的对象速度很快，因此在使用或复制这些类型时通常不应担心性能问题。

// 您可能认为使用较少内存的类型会比使用较多内存的类型更快。这并不总是正确的。CPU
// 通常经过优化以处理特定大小（例如 32
// 位）的数据，并且与该大小匹配的类型可以更快地处理。在这样的机器上，32 位的 int
// 可能比 16 位的 short 或 8 位的 char 更快。
int main() {
  std::vector<int> vec;
  std::cout << sizeof(vec) << std::endl;
}