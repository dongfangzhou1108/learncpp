#include <iostream>

template <typename T> class Auto_ptr1 {
  T *m_ptr;

public:
  // Pass in a pointer to "own" via the constructor
  Auto_ptr1(T *ptr = nullptr) : m_ptr(ptr) {}

  // The destructor will make sure it gets deallocated
  ~Auto_ptr1() { delete m_ptr; }

  // Overload dereference and operator-> so we can use Auto_ptr1 like m_ptr.
  T &operator*() const { return *m_ptr; }
  T *operator->() const { return m_ptr; }
};

// A sample class to prove the above works
class Resource {
public:
  Resource() { std::cout << "Resource acquired\n"; }
  ~Resource() { std::cout << "Resource destroyed\n"; }
  void sayHi() { std::cout << "Hi!\n"; }
};

void someFunction() {
  Auto_ptr1<Resource> ptr(new Resource()); // ptr now owns the Resource

  int x;
  std::cout << "Enter an integer: ";
  std::cin >> x;

  if (x == 0)
    return; // the function returns early

  // do stuff with ptr here
  ptr->sayHi();
}

void Auto_ptr1_exception() {
  try {
    Auto_ptr1<Resource> res1(new Resource());
    Auto_ptr1<Resource> res2(res1); // Alternatively, don't initialize res2 and
                                    // then assign res2 = res1;
  } catch (...) {
  }
}

void passByValue(Auto_ptr1<Resource> res) {}

void Auto_ptr1_exception_2() {
  Auto_ptr1<Resource> res1(new Resource());
  passByValue(res1);
}

// Move semantics means the class will transfer ownership of the object rather
// than making a copy
template <typename T> class Auto_ptr2 {
  T *m_ptr;

public:
  Auto_ptr2(T *ptr = nullptr) : m_ptr(ptr) {}

  ~Auto_ptr2() { delete m_ptr; }

  // A copy constructor that implements move semantics
  Auto_ptr2(Auto_ptr2 &a) // note: not const
  {
    m_ptr = a.m_ptr;   // transfer our dumb pointer from the source to our local
                       // object
    a.m_ptr = nullptr; // make sure the source no longer owns the pointer
  }

  // An assignment operator that implements move semantics
  Auto_ptr2 &operator=(Auto_ptr2 &a) // note: not const
  {
    if (&a == this)
      return *this;

    delete m_ptr;      // make sure we deallocate any pointer the destination is
                       // already holding first
    m_ptr = a.m_ptr;   // then transfer our dumb pointer from the source to the
                       // local object
    a.m_ptr = nullptr; // make sure the source no longer owns the pointer
    return *this;
  }

  T &operator*() const { return *m_ptr; }
  T *operator->() const { return m_ptr; }
  bool isNull() const { return m_ptr == nullptr; }
};

void test_Auto_ptr2() {
  Auto_ptr2<Resource> res1(new Resource());
  Auto_ptr2<Resource> res2; // Start as nullptr

  std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
  std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

  res2 = res1; // res2 assumes ownership, res1 is set to null

  std::cout << "Ownership transferred\n";

  std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
  std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
}

void analyse_Auto_ptr2() {
  // implements move semantics through the copy constructor and assignment
  // operator

  // first:
  // passing a std::auto_ptr by value to a function will cause your resource to
  // get moved to the function parameter (and be destroyed at the end of the
  // function when the function parameters go out of scope). Then when you go to
  // access your auto_ptr argument from the caller (not realizing it was
  // transferred and deleted), you’re suddenly dereferencing a null pointer.
  // Crash!

  // second:
  // std::auto_ptr always deletes its contents using non-array delete. This
  // means auto_ptr won’t work correctly with dynamically allocated arrays

  // third:
  // auto_ptr doesn’t play nice with a lot of the other classes in the standard
  // library, including most of the containers and algorithms. This occurs
  // because those standard library classes assume that when they copy an item,
  // it actually makes a copy, not a move.
}

int main() {
  someFunction();

  // shallow copies: free(): double free detected in tcache 2, Aborted (core
  // dumped)
  // Auto_ptr1_exception();
  // Auto_ptr1_exception_2();

  test_Auto_ptr2();

  // The core problem with the design of std::auto_ptr is that prior to C++11,
  // the C++ language simply had no mechanism to differentiate “copy semantics”
  // from “move semantics”.

  return 0;
}