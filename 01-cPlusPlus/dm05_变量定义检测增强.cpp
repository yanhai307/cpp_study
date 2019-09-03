//
// Created by YANHAI on 2019/4/21.
//

// 在C语言中，重复定义多个同名的全局变量是合法的
// 在C++中，不允许定义多个同名的全局变量
// C语言中多个同名的全局变量最终会被链接到全局数据区的同一个地址空间上

// 下面代码使用VC++6.0和gcc编译器都可以正常编译通过
/*
#include <stdio.h>
int g_var;
int g_var = 1;

int main()
{
    printf("g_var = %d\n", g_var);
    return 0;
}
*/

// 在C++中则编译不通过
#include <iostream>

// 打开下面的注释，则编译不通过，
// C++编译器 直接拒绝这种二义性的做法
int g_var;
//int g_var = 1;

int main()
{
    printf("g_var = %d\n", g_var);
    return 0;
}
