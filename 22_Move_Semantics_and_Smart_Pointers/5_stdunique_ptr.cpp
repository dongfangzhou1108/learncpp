#include <iostream>
#include <memory>  // for std::unique_ptr
#include <utility> // for std::move

// Use std::make_unique() instead of creating std::unique_ptr and using new
// yourself.
// https://stackoverflow.com/questions/37514509/advantages-of-using-stdmake-unique-over-new-operator
// https://stackoverflow.com/questions/22571202/differences-between-stdmake-unique-and-stdunique-ptr-with-new
// prevents the unspecified-evaluation-order leak triggered by expressions like
// foo(unique_ptr<X>(new X), unique_ptr<Y>(new Y))

class Resource {
public:
  Resource() { std::cout << "Resource acquired\n"; }
  ~Resource() { std::cout << "Resource destroyed\n"; }
};

std::unique_ptr<Resource> createResource() {
  return std::make_unique<Resource>();
}

int main() {
  std::unique_ptr<Resource> res1{new Resource{}}; // Resource created here
  std::unique_ptr<Resource> res2{};               // Start as nullptr

  std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
  std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

  // res2 = res1; // Won't compile: copy assignment is disabled
  res2 = std::move(res1); // res2 assumes ownership, res1 is set to null

  std::cout << "Ownership transferred\n";

  std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
  std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

  // move semantics will be employed to transfer the Resource from the return
  // value to the object assigned
  auto ptr{createResource()};

  return 0;
} // Resource destroyed here when res2 goes out of scope