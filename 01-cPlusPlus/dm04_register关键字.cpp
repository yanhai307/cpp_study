//
// Created by YANHAI on 2019/4/21.
//

// register关键字 请求编译器让变量a直接放在寄存器里面，速度快
// 在C语言中register修饰的变量 不能取地址，但是在C++里面做了下面内容
// 1. register关键字的变化
//    register关键字请求“编译器”将局部变量存储于寄存器中
//    C语言中无法取得register变量地址
//    在C++中依然支持register关键字
//    C++编译器有自己的优化方式，不使用register也可以做优化
//    C++中可以取得register变量的地址
// 2. C++编译器发现程序中需要取register变量的地址时，register对变量的声明变得无效。
// 3. 早期C语言编译器不会对代码进行优化，因此register变量是一个很好的补充。

// 下面代码使用VC++6.0或者gcc编译会报错，
/*
#include <stdio.h>
int main()
{
    register int a = 0;
    printf("&a = %p\n", &a);    // error: address of register variable ‘a’ requested
    return 0;
}
*/

// 在C++中是可以编译通过的
#include <iostream>

int main()
{
    // register关键字是不推荐使用的，并且 在C++17中不兼容register关键字
    register int a = 0;
    printf("&a = %p\n", &a);
    return 0;
}
