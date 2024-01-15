/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2024-01-15 09:05:45
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2024-01-15 10:03:53
 * @FilePath: /learncpp/5 Constants and Strings/5.7
 * inline-functions-and-variables/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// 总结: 没事别用inline即可
// 核心概念: 内联(1)函数替换，弃用(2)将多个相同定义链接到一起(函数/变量)

// However, one downside of using a function is that every time a function is
// called, there is a certain amount of performance overhead that occurs
// 调用函数会产生一定性能开销

// 当遇到 to min() 的调用时，CPU
// 必须存储它正在执行的当前指令的地址（以便它知道以后返回到哪里）以及各种 CPU
// 寄存器的值（以便它们可以在返回时恢复）。然后是参数 x ，必须实例化， y
// 然后初始化。然后执行路径必须跳转到 min()
// 函数中的代码。当函数结束时，程序必须跳回函数调用的位置，并且必须复制返回值才能输出。必须对每个函数调用执行此操作

// [函数需要内联原因]
// 对于小型函数（如上所述 min() ），开销成本可能大于实际执行函数代码所需的时间！
// 在频繁调用小函数的情况下，与就地编写相同的代码相比，使用函数可能会导致显著的性能损失

// 内联函数与宏定义
// 编译期间替换 与 预处理阶段替换

// 为什么不一定能优化性能
// 内联函数过大，导致可执行文件变大，虽然减少内存开销，但是可能导致缓存未命中，降低效率

// Modern optimizing compilers make the decision about when functions should be
// expanded inline.
// 现代编译期决定什么时候发生内联

// 历史用法: 声明函数进行内联操作, 现代编译期可以自行判断(准确于人),
// 因此不建议使用 现代用法: In modern C++, the term inline has evolved to mean
// “multiple definitions are allowed”. 用于表达"允许多重定义”
// ；要求:(1)each translation unit 每个翻译单元需要有完整定义
// (2)多个定义保持相同 如果存在不同将产生未定义行为,
// 建议内联函数放在头文件中定义 The linker will consolidate all inline function
// definitions for an identifier into a single definition (thus still meeting
// the requirements of the one definition rule). 链接器合并单个定义

// 内联的两个含义:(1)编译展开,减少函数调用产生的消耗(弃用)(2)将多个相同的定义合并(现代C++使用)
// implicitly inline:
// (1) 成员函数(类结构体等)
// (2) Constexpr / consteval functions
// (3) 函数模板
// 不太需要关注inline函数的性能优化, 编译器会为我们自动处理