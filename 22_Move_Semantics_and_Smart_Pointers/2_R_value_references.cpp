// L-value references to const objects are particularly useful because they
// allow us to pass any type of argument (l-value or r-value) into a function
// without making a copy of the argument.

// R-value references have two properties that are useful. First, r-value
// references extend the lifespan of the object they are initialized with to the
// lifespan of the r-value reference (l-value references to const objects can do
// this too). Second, non-const r-value references allow you to modify the
// r-value!(对标const L-value)

// You should almost never return an r-value reference, for the same reason you
// should almost never return an l-value reference. In most cases, you’ll end up
// returning a hanging reference when the referenced object goes out of scope at
// the end of the function.(一般不返回引用)

#include <iostream>

class Fraction {
private:
  int m_numerator;
  int m_denominator;

public:
  Fraction(int numerator = 0, int denominator = 1)
      : m_numerator{numerator}, m_denominator{denominator} {}

  friend std::ostream &operator<<(std::ostream &out, const Fraction &f1) {
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
  }
};

void fun(const int &lref) // l-value arguments will select this function
{
  std::cout << "l-value reference to const: " << lref << '\n';
}

void fun(int &&rref) // r-value arguments will select this function
{
  std::cout << "r-value reference: " << rref << '\n';
}

int main() {
  // example 1
  auto &&rref{Fraction{3, 5}}; // r-value reference to temporary Fraction
  std::cout << rref << '\n';   // f1 of operator<< binds to the temporary, no
                               // copies are created.

  // example 2
  int &&iref{5}; // because we're initializing an r-value reference with a
                 // literal, a temporary with value 5 is created here
  iref = 10;
  std::cout << iref << '\n';

  // example 3
  int x{5};
  fun(x); // l-value argument calls l-value version of function
  fun(5); // r-value argument calls r-value version of function

  // example 4: Rvalue reference variables are lvalues
  int &&ref{5};
  fun(ref);

  return 0;
} // rref (and the temporary Fraction) goes out of scope here