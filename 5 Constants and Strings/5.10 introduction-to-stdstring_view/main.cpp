/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2024-01-23 11:34:59
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2024-01-23 11:49:25
 * @FilePath: /learncpp/5 Constants and Strings/5.10
 * introduction-to-stdstring_view/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// C++ 17

// std::string_view provides read-only access to an existing string (a C-style
// string, a std::string, or another std::string_view) without making a copy.
// Read-only means that we can access and use the value being viewed, but we can
// not modify it. 只读访问, 无需复制

// string view 可以通过 const char, string, string view 初始化

// string view 不允许隐式转换

// Assigning a new string to a std::string_view causes the std::string_view to
// view the new string. It does not modify the prior string being viewed in any
// way. 重新分配 string view, 不改变原对象

// 支持 constexpr - 编译期常量