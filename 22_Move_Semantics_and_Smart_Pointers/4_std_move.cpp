#include <iostream>
#include <string>

// In C++11, std::move is a standard library function that casts (using
// static_cast) its argument into an r-value reference, so that move semantics
// can be invoked. Thus, we can use std::move to cast an l-value into a type
// that will prefer being moved over being copied.

// std::move can be used whenever we want to treat an l-value like an r-value
// for the purpose of invoking move semantics instead of copy semantics. 

template <class T> void myswapCopy(T &a, T &b) {
  T tmp{a}; // invokes copy constructor
  a = b;    // invokes copy assignment
  b = tmp;  // invokes copy assignment
}

template <class T> void myswapMove(T &a, T &b) {
  T tmp{std::move(a)}; // invokes move constructor
  a = std::move(b);    // invokes move assignment
  b = std::move(tmp);  // invokes move assignment
}

int main() {
  std::string x{"abc"};
  std::string y{"de"};

  std::cout << "x: " << x << '\n';
  std::cout << "y: " << y << '\n';

  myswapCopy(x, y);

  std::cout << "x: " << x << '\n';
  std::cout << "y: " << y << '\n';

  return 0;
}