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
}