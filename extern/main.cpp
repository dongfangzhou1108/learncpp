extern int a; // ok不用包含头文件， 变量只要声明即可
extern void fun();

int main() {
  fun();

  return 0;
}