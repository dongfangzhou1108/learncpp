/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2024-01-10 13:34:55
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2024-01-10 13:56:08
 * @FilePath: /learncpp/4 Fundamental Data Types/4.5
 * fixed-width-integers-and-size-t/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// C++ officially adopted these fixed-width integers as part of C++11. They can
// be accessed by including the <cstdint> header, where they are defined inside
// the std namespace
// e.g. std::int16_t

// 例如，对于表示ASCII字符的场景，char
// 是常见的选择，因为ASCII字符的值在0到127之间。而在需要确保数值非负并且大于255时，比如处理字节数据或颜色值等，unsigned
// char
// 可能更适合，因为它能表示的范围更大。在涉及位运算和原始数据处理的情况下，使用
// unsigned char 通常更为合适。

// 8
// 位固定宽度整数类型通常被视为字符而不是整数值（这可能因系统而异）。在大多数情况下，首选
// 16 位固定整型类型

// std::size_t is defined as an unsigned integral type, and it is typically used
// to represent the size or length of objects.
// std::size_t 保证是无符号的，至少为 16
// 位，但在大多数系统上将等同于应用程序的地址宽度。也就是说，对于 32
// 位应用程序， std::size_t 通常为 32 位无符号整数，对于 64 位应用程序，
// std::size_t 通常为 64 位无符号整数
int main() {}