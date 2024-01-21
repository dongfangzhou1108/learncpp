// Constexpr 函数可以在编译时计算, 也可以在运行时计算

// According to the C++ standard, a constexpr function that is eligible for
// compile-time evaluation must be evaluated at compile-time if the return value
// is used where a constant expression is required. Otherwise, the compiler is
// free to evaluate the function at either compile-time or runtime.
// 省流: 只有入参和返回值都是 constexpr 一定编译期计算

// C++ 20 consteval 强制编译期运算, 必须 inline (声明定义不能分开)

int main() {}