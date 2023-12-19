/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2023-12-19 11:24:23
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2023-12-19 16:04:38
 * @FilePath:
 * /learncpp/1_C++_Basics/1_4_variable_assignment_and_initialization/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

class copy_operator_test {
public:
  copy_operator_test() {
    i_ = new int(100);
    std::cout << "copy_operator_test()" << std::endl;
  }

  /*
   * 返回引用类型的原因是：保证与标量类型(int)相同，能够连续赋值，并支持链式调用
   */
  copy_operator_test &
  operator=(const copy_operator_test &rval) { // 重载赋值运算符
    i_ = new int(*(rval.i_));
    std::cout
        << "copy_operator_test &operator=(const copy_operator_test &rval) "
        << std::endl;
    return *this;
  }

  copy_operator_test &operator=(const int &rval) { // 重载赋值运算符
    i_ = new int(rval);
    std::cout << "copy_operator_test &operator=(const int &rval)" << std::endl;
    return *this;
  }

  int *i_ = nullptr;
};

class test_list_initialization {
public:
  test_list_initialization(const int &a, const int &b) : a_{a}, b_{b} {}

  int a_, b_;
};

int main() {
  /*
   * assigenment operator 赋值运算符，在对象存在情况下被调用，并且返回引用类型
   * 本质上，运算符是一种函数，需要对象存在
   * copy_operator_test c1 = 10; 该语句执行时对象并不存在，因此会报编译错误
   * copy_operator_test c1; c1 = 10; c1 = 10 时刻对象已经存在，所以可以通过编译
   */
  // copy_operator_test c1 = 10;
  copy_operator_test c1;
  c1 = 10;

  /*
   * 变量初始化，按照时间顺序，以C++11为界限，分为两个阶段，C++11后推荐列表{}初始化
   * 按照初始化方式，分为：
   * 1）默认初始化default
   * 2）复制初始化copy，通过=赋值，隐式转换时调用，如函数传值和按值返回
   * 3）直接初始化direct，通过()构造，显式转换时调用
   * TBD原因：
   * 1）基于()的直接初始化，可能与[函数声明]产生歧义
   * 2）https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es23-prefer-the--initializer-syntax
   */
  //  from core guidelines
  auto x1{7};    // x1 is an int with the value 7
  auto x2 = {7}; // x2 is an initializer_list<int> with an element 7
  // auto x11 {7, 8};    // error: two initializers
  auto x22 = {7, 8}; // x22 is an initializer_list<int> with elements 7 and 8

  // https://stackoverflow.com/questions/51166807/initializer-list-with-auto-contains-multiple-expressions
  // TODO: auto t1{1, 2}; can not compile, associate with [auto]
  // auto t1{1, 2};
  test_list_initialization t2{1, 2};
}