/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2024-01-08 15:20:57
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2024-01-08 15:21:15
 * @FilePath: /learncpp/2 Functions and Files/2.12 header-guards/square.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "square.h"  // square.h is included once here

int getSquarePerimeter(int sideLength)
{
    return sideLength * getSquareSides();
}