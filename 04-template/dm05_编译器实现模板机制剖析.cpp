//
// Created by yanhai on 2019/9/23.
//

/**
 * 思考：
 *     为什么函数模板可以和函数重载放在一起。C++编译器是如何提供函数模板机制的？
 *
 *  首先看编译过程
 *     1. g++ -E demo.cpp -o demo.i // 预处理（头文件包含展开，宏定义展开）
 *     2. g++ -S demo.i -o demo.s   // 编译，生成汇编程序
 *     3. g++ -c demo.s -o demo.o   // 汇编，生成可重定位目标程序（二进制）
 *     4. g++ demo.o -o demo        // 链接，生成可执行目标程序（二进制）
 *
 *  将本程序汇编成.s文件
 *    g++ -S dm05_编译器实现模板机制剖析.cpp -o dm05_编译器实现模板机制剖析.s // 查看.s文件里面会有2个myswap函数实现
 *
 *  函数模板机制结论
 *    1.编译器并不是把函数模板处理成能够处理任意类型的函数
 *    2.编译器从函数模板通过具体类型产生不同的函数
 *    3.编译器会对函数模板进行两次编译
 *      1).在声明的地方对模板代码本身进行编译
 *      2).在调用的地方对参数替换后的代码进行编译
 */

#include <iostream>

template<typename T>
void myswap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}

int main()
{
    {
        int a = 10;
        int b = 20;
        myswap<int>(a, b);
    }
    {
        char a = 'a';
        char b = 'b';
        myswap<char>(a, b);
    }

    return 0;
}
