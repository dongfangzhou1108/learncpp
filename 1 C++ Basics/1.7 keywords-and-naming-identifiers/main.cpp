/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2023-12-20 09:34:15
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2023-12-20 13:49:08
 * @FilePath: /learncpp/1 C++ Basics/1.7
 * keywords-and-naming-identifiers/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
int main() {
  // keywords 关键字 -> 不能作为变量名
  // special identifiers [特殊]标识符 ->
  // [特殊]在于，特定上下文中具备特殊含义，其他场景作为标识符无特殊含义
  int override = 0;

  // a good rule of thumb is to make the length of an identifier proportional
  // to how widely it is used
  // 避免[标识符]过长/过短，影响程序理解，描述详细程度取决于应用频率
  // In any case, avoid abbreviations (unless they are common/unambiguous).
  // 尽量避免使用缩写
  // For variable declarations, it is useful to use a comment to describe what a
  // variable is going to be used for, or to explain anything else that might
  // not be obvious.
	// 为不清晰变量增加注释
}