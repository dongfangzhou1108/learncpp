/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2023-12-29 15:25:12
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2024-01-04 14:57:14
 * @FilePath: /learncpp/2 Functions and Files/2.10
 * introduction-to-the-preprocessor/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// [预处理器]
// https://en.cppreference.com/w/cpp/language/translation_phases
// The entire process of preprocessing, compiling, and linking is called
// translation. If you’re curious, here is a list of translation phases. As of
// the time of writing, preprocessing encompasses phases 1 through 4, and
// compilation is phases 5 through 7.

// When the preprocessor has finished processing a code file, the result is
// called a translation unit. This translation unit is what is then compiled by
// the compiler.
// 当预处理器处理完代码文件后，结果称为翻译单元。这个翻译单元是编译器随后编译的内容。

// [宏定义]
// The #define directive can be used to create a macro. In C++, a macro is a
// rule that defines how input text is converted into replacement output text.
// 宏是定义如何将输入文本转换为替换输出文本的规则
// There are two basic types of macros: object-like macros, and function-like
// macros.有两种基本类型的宏：类对象宏和类函数宏

// #define PRINT_JOE
// #ifdef PRINT_JOE
// [宏只会导致非预处理器命令的文本替换] 由于 #ifdef PRINT_JOE
// 是预处理器命令，因此文本替换不适用于此命令中的PRINT_JOE

int main() {}