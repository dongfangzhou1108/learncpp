/*
 * @Author: dongfangzhou1108 18746061711@163.com
 * @Date: 2024-01-08 15:20:34
 * @LastEditors: dongfangzhou1108 18746061711@163.com
 * @LastEditTime: 2024-01-08 15:24:11
 * @FilePath: /learncpp/2 Functions and Files/2.12 header-guards/square.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef SQUARE_H
#define SQUARE_H

// Note that the goal of header guards is to prevent [a code file] from receiving
// more than one copy of a guarded header. By design, header guards do not
// prevent a given header file from being included (once) into separate code
// files. This can also cause unexpected problems.

int getSquareSides() { return 4; }

int getSquarePerimeter(
    int sideLength); // forward declaration for getSquarePerimeter

#endif