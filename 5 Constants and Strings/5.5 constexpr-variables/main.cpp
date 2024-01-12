/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2024-01-12 16:57:04
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2024-01-12 17:19:47
 * @FilePath: /learncpp/5 Constants and Strings/5.5 constexpr-variables/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// 当您使用 const 关键字声明 const
// 变量时，编译器将隐式跟踪它是运行时常量还是编译时常量。在大多数情况下，除了优化目的之外，这无关紧要，但在少数情况下，C++
// 需要常量表达式。并且只能在常量表达式中使用编译时常量变量。
// const 无法确认是编译期还是运行期常量

// constexpr 变量是隐式 const。const 变量不是隐式 constexpr (const int除外)

/*Best practice 最佳实践

Any constant variable whose initializer is a constant expression should be
declared as constexpr. 任何初始值设定项为常量表达式的常量变量都应声明为
constexpr 。

Any constant variable whose initializer is not a constant expression should be
declared as const. 任何初始值设定项不是常量表达式的常量变量都应声明为 const 。

Caveat: In the future we will discuss some types that are not fully compatible
with constexpr (including std::string, std::vector, and other types that use
dynamic memory allocation). For constant objects of these types, either use
const instead of constexpr, or pick a different type that is constexpr
compatible (e.g. std::string_view or std::array).
注意：将来我们将讨论一些不完全兼容的 constexpr 类型（包括 std::string 、
std::vector 和其他使用动态内存分配的类型）。对于这些类型的常量对象，请使用 const
代替 constexpr ，或者选择与 constexpr 兼容的其他类型（例如 std::string_view 或
std::array ）。*/

// constexpr 的设计目的是为了提高编译时的性能，支持更加灵活的编译时计算和元编程，
// 以及在编译时进行一些静态检查。这有助于提高代码的效率、可读性和可维护性。