// 当编译器在没有明确要求的情况下代表我们进行类型转换时，我们称之为隐式类型转换

// Type conversion uses direct initialization to produce a new value of the
// target type from a value of a different type.
// (隐式/显式)类型转换仅仅生成新值, 不改变旧值

/*某些类型转换始终是安全的（例如 int to double
），而其他类型可能会导致值在转换过程中发生更改（例如 double to int
）。不安全的隐式转换通常会生成编译器警告，或者（在大括号初始化的情况下）错误。

This is one of the primary reasons brace initialization is the preferred
initialization form. Brace initialization will ensure we don’t try to initialize
a variable with an initializer that will lose value when it is implicitly type
converted:
这是大括号初始化是首选初始化形式的主要原因之一。
大括号初始化将确保我们不会尝试使用初始值设定项初始化变量，该初始值设定项在隐式类型转换时会丢失值*/

/*C++ supports a second method of type conversion, called explicit type
conversion. Explicit type conversion allow us (the programmer) to explicitly
tell the compiler to convert a value from one type to another type, and that we
take full responsibility for the result of that conversion (meaning that if the
conversion results in the loss of value, it’s our fault). C++
支持第二种类型转换方法，称为显式类型转换。显式类型转换允许我们（程序员）显式告诉编译器将值从一种类型转换为另一种类型，
并且我们对该转换的结果承担全部责任（这意味着如果转换导致值丢失，那是我们的错）。*/

#include <iostream>

int main() {
  /*The static_cast operator will produce undefined behavior if the value being
        converted doesn’t fit in range of the new type.
        如果要转换的值不适合新类型的范围，则static_cast运算符将产生未定义的行为。*/
  unsigned int u{5};
  int s{static_cast<int>(u)}; // return value of variable u as an int
  std::cout << s << '\n';

  return 0;
}