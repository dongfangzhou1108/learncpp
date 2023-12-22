/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2023-12-22 15:07:45
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2023-12-22 15:37:56
 * @FilePath: /learncpp/2 Functions and Files/2.5
 * introduction-to-local-scope/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// 复制构造函数，在值传递和返回被调用
// 重载赋值运算符，在[已存在对象]，进行赋值操作时被调用
// 需要注意的是，编译器可能会对构造函数进行优化，如进行RVO（Return Value
// Optimization）或NRVO（Named Return Value
// Optimization），从而避免不必要的构造函数调用

// 函数参数在输入函数时创建并初始化，函数体中的变量在定义点创建和初始化
// 局部变量在定义它的大括号集的末尾（或函数参数，在函数的末尾）以相反的创建顺序销毁

// Define your local variables as close to their first use as reasonable.

int main() {}