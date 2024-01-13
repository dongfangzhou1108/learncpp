/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2024-01-13 09:15:58
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2024-01-13 09:25:27
 * @FilePath: /learncpp/5 Constants and Strings/5.6
 * the-conditional-operator/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// ?: 条件算符提供了一种速记方法，用于执行特定类型的 if-else 语句
// c ? x ： y	If conditional c is true then evaluate x, otherwise evaluate y

// 由于条件运算符的操作数是表达式而不是语句，因此可以在需要表达式的地方使用条件运算符
// constexpr bool inBigClassroom { false };
// constexpr int classSize { inBigClassroom ? 30 : 20 };

// 由于 C++ 将大多数运算符的计算优先级置于条件运算符的计算之上，
// 因此使用条件运算符编写未按预期计算的表达式非常容易
// int x { 2 };
// int y { 1 };
// int z { 10 - x > y ? x : y };

// The type of the expressions must match or be convertible
// c ? x ： y 保证 xy类型 一致 或者可以 安全转换

// So when should you use the conditional operator?
// 初始化对象/函数参数设置/返回等 [二选一] 情况