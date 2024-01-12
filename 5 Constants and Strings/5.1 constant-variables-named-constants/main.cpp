/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2024-01-12 15:02:29
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2024-01-12 15:17:21
 * @FilePath: /learncpp/5 Constants and Strings/5.1
 * constant-variables-named-constants/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// 常量是在程序执行过程中不能更改的值

// 命名常量是与标识符关联的常量值
// const int MAX_SIZE = 100; // 使用 const 关键字定义的命名常量
// #define PI 3.14159        // 使用 #define 预处理指令定义的命名常量

// 文本常量是不与标识符关联的常量值
// double height = 10.0; // 10.0 是字面值常量

// 判断标准 是否绑定对象

// Don’t use const when passing by value.
// Don’t use const when returning by value. 返回值为临时对象, 会被销毁

// 首选常量变量而不是预处理器宏
// 宏定义为文本替换, 有可能在不需要的地方被替换
// 难以调试

