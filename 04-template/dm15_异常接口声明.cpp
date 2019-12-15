//
// Created by YANHAI on 2019/12/15.
//

/**
 * 异常接口声明
 *  1. 为了加强程序的可读性，可以在函数声明中列出可能抛出的所有异常类型，例如
 *     void func() throw (A,B,C,D);  //这个函数func()能够且只能抛出类型A B C D
 *     及其子类的异常
 *  2. 如果在函数声明中没有包含异常接口声明，则此函数可以抛出任意类型的异常，例如
 *     void func();
 *  3. 一个不抛出任何异常的 函数可以声明为:
 *       void func() throw();
 *     也可以使用noexcept关键字
 *       void func() noexcept;
 *  4. 如果一个函数抛出了它的异常接口声明所不允许的抛出的异常，unexpected函数会被调用
 *     该函数默认行为调用terminate函数终止程序
 */

#include <iostream>

using namespace  std;

class Test {

};

// 只能抛出 int char类型异常
void throw_test1() throw(int, char)
{
    throw Test();
}

// 可以抛出任意类型异常
void throw_test2() noexcept(false)
{
    throw Test();
}

// 不允许抛出任何异常
void throw_test3() noexcept
{
    throw Test();
}

int main()
{
    throw_test1();
    throw_test2();
    throw_test3();
    return 0;
}
