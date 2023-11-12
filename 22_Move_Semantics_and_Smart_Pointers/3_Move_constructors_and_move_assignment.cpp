// The move constructor and move assignment are called when those functions have
// been defined, and the argument for construction or assignment is an rvalue.

// 类显式定义拷贝构造赋值或者析构函数, 编译器不会自动生成移动构造赋值函数,
// 类会使用拷贝构造代替移动构造

// However, if we construct an object or do an assignment where the argument is
// an r-value, then we know that r-value is just a temporary object of some
// kind. Instead of copying it (which can be expensive), we can simply transfer
// its resources (which is cheap) to the object we’re constructing or assigning.
// This is safe to do because the temporary will be destroyed at the end of the
// expression anyway, so we know it will never be used again!

// you might think about implementing the move constructor and move assignment
// operator using std::swap(). However, this is a bad idea, as std::swap() calls
// both the move constructor and move assignment on move-capable objects, which
// would result in an infinite recursion.
// You can implement the move constructor and move assignment using your own
// swap function, as long as your swap member function does not call the move
// constructor or move assignment.(swap实现移动语义)

// While deleting only the move constructor and move assignment may seem like a
// good idea if you want a copyable but not movable object, this has the
// unfortunate consequence of making the class not returnable by value in cases
// where mandatory copy elision does not apply.(删除移动构造赋值,
// 函数无法按值返回对象, 取决于编译期-g++可以)

#include <iostream>

template <typename T> class Auto_ptr3 {
  T *m_ptr;

public:
  Auto_ptr3(T *ptr = nullptr) : m_ptr(ptr) {}

  ~Auto_ptr3() { delete m_ptr; }

  // Copy constructor
  // Do deep copy of a.m_ptr to m_ptr
  Auto_ptr3(const Auto_ptr3 &a) {
    m_ptr = new T;
    *m_ptr = *a.m_ptr;
  }

  // Copy assignment
  // Do deep copy of a.m_ptr to m_ptr
  Auto_ptr3 &operator=(const Auto_ptr3 &a) {
    // Self-assignment detection
    if (&a == this)
      return *this;

    // Release any resource we're holding
    delete m_ptr;

    // Copy the resource
    m_ptr = new T;
    *m_ptr = *a.m_ptr;

    return *this;
  }

  T &operator*() const { return *m_ptr; }
  T *operator->() const { return m_ptr; }
  bool isNull() const { return m_ptr == nullptr; }
};

class Resource {
public:
  Resource() { std::cout << "Resource acquired\n"; }
  ~Resource() { std::cout << "Resource destroyed\n"; }
};

Auto_ptr3<Resource> generateResource() {
  Auto_ptr3<Resource> res{new Resource};
  return res; // this return value will invoke the copy constructor
}

template <typename T> class Auto_ptr4 {
  T *m_ptr;

public:
  Auto_ptr4(T *ptr = nullptr) : m_ptr(ptr) {}

  ~Auto_ptr4() { delete m_ptr; }

  // Copy constructor
  // Do deep copy of a.m_ptr to m_ptr
  Auto_ptr4(const Auto_ptr4 &a) {
    m_ptr = new T;
    *m_ptr = *a.m_ptr;
  }

  // Move constructor
  // Transfer ownership of a.m_ptr to m_ptr
  Auto_ptr4(Auto_ptr4 &&a) noexcept : m_ptr(a.m_ptr) {
    a.m_ptr = nullptr; // we'll talk more about this line below
  }

  // Copy assignment
  // Do deep copy of a.m_ptr to m_ptr
  Auto_ptr4 &operator=(const Auto_ptr4 &a) {
    // Self-assignment detection
    if (&a == this)
      return *this;

    // Release any resource we're holding
    delete m_ptr;

    // Copy the resource
    m_ptr = new T;
    *m_ptr = *a.m_ptr;

    return *this;
  }

  // Move assignment
  // Transfer ownership of a.m_ptr to m_ptr
  Auto_ptr4 &operator=(Auto_ptr4 &&a) noexcept {
    std::cout << "Move assignment" << std::endl;
    // Self-assignment detection
    if (&a == this)
      return *this;

    // Release any resource we're holding
    delete m_ptr;

    // Transfer ownership of a.m_ptr to m_ptr
    m_ptr = a.m_ptr;
    a.m_ptr = nullptr; // we'll talk more about this line below

    return *this;
  }

  T &operator*() const { return *m_ptr; }
  T *operator->() const { return m_ptr; }
  bool isNull() const { return m_ptr == nullptr; }
};

Auto_ptr4<Resource> generateResource_2() {
  Auto_ptr4<Resource> res{new Resource};
  return res; // this return value will invoke the move constructor
}

// supports move semantics but not copy semantics
template <typename T> class Auto_ptr5 {
  T *m_ptr;

public:
  Auto_ptr5(T *ptr = nullptr) : m_ptr(ptr) {}

  ~Auto_ptr5() { delete m_ptr; }

  // Copy constructor -- no copying allowed!
  Auto_ptr5(const Auto_ptr5 &a) = delete;

  // Move constructor
  // Transfer ownership of a.m_ptr to m_ptr
  Auto_ptr5(Auto_ptr5 &&a) noexcept : m_ptr(a.m_ptr) { a.m_ptr = nullptr; }

  // Copy assignment -- no copying allowed!
  Auto_ptr5 &operator=(const Auto_ptr5 &a) = delete;

  // Move assignment
  // Transfer ownership of a.m_ptr to m_ptr
  Auto_ptr5 &operator=(Auto_ptr5 &&a) noexcept {
    // Self-assignment detection
    if (&a == this)
      return *this;

    // Release any resource we're holding
    delete m_ptr;

    // Transfer ownership of a.m_ptr to m_ptr
    m_ptr = a.m_ptr;
    a.m_ptr = nullptr;

    return *this;
  }

  T &operator*() const { return *m_ptr; }
  T *operator->() const { return m_ptr; }
  bool isNull() const { return m_ptr == nullptr; }
};

class Name {
private:
  std::string m_name;

public:
  Name(std::string name) : m_name{name} {}

  Name(const Name &name) = default;
  Name &operator=(const Name &name) = default;

  Name(Name &&name) = delete;
  Name &operator=(Name &&name) = delete;

  const std::string &get() { return m_name; }
};

Name getJoe() {
  Name joe{"Joe"};
  return joe; // error: Move constructor was deleted
}

int main() {
  // Auto_ptr3<Resource> mainres;
  // mainres =
  //     generateResource(); // this assignment will invoke the copy assignment

  // Auto_ptr4<Resource> mainres_2;
  // mainres_2 =
  //     generateResource_2(); // this assignment will invoke the move
  //     assignment
  Auto_ptr4<Resource> mainres_3 =
      generateResource_2(); // do not invoke Move assignment(返回值优化)

  Name n{getJoe()};
  std::cout << n.get() << '\n';

  return 0;
}