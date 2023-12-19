extern int a; // ok不用包含头文件， 变量只要声明即可
extern void fun();

/*
 * 添加extern声明，可以让编译器把“寻找定义”这件事情推迟到链接阶段，而不会在编译阶段报“没有定义”的错误。
 */

int main() {
  fun();

  return 0;
}