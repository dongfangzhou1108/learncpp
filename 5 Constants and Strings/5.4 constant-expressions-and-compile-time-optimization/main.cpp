/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2024-01-12 16:22:24
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2024-01-12 16:38:35
 * @FilePath: /learncpp/5 Constants and Strings/5.4
 * constant-expressions-and-compile-time-optimization/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// 常量表达式与编译期优化

// 编译期间计算部分表达式
// 这种优化使我们的编译花费更长的时间（因为编译器必须做更多的工作），
// 但是由于表达式只需要在编译时（而不是每次运行程序时）计算一次，
// 因此生成的可执行文件速度更快，并且使用的内存更少。

// Const 非整型变量始终是运行时常量（即使它们具有常量表达式初始值设定项）。
// 如果需要这些变量作为编译时常量，请将它们定义为 constexpr 变量
// 不是常量表达式的表达式有时称为运行时表达式

// Constant expressions - 常量表达式, 简单理解为编译期可以计算出的值
// in modern C++, [constexpr] variables are preferred 而不是const
