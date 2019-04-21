//
// Created by YANHAI on 2019/4/21.
//
#include <iostream>

//#include <stdio.h>

int main1()
{
    const int a = 10;
//   a = 11;

    int *p = NULL;
    p = (int *)&a;
    *p = 20;
    printf("a: %d\n", a);
    return 0;
}

//上述代码在C语言中，将会打印  a: 20
// 在C++中，则会打印 a: 10

// C语言中的const是一个“冒牌货”
// C++语言中 const是一个真正的常量

/*
 * 解释：
 *    C++编译器对const常量的处理
 *    当碰见常量声明时，在符号表中放入常量
 *    编译过程中如发现对使用常量则直接以符号表中的值替换
 *    编译过程中如发现对 const使用extern或者&操作符，则给对应的常量分配存储空间(兼容C)
 */

// 下面证明，p指向的内存，和a是不同的
int main2()
{
    const int a = 10;
//   a = 11;

    int *p = NULL;
    p = (int *)&a;
    *p = 20;
    printf("a: %d\n", a);
    printf("*p: %d\n", *p);

    printf("&a: %p\n", a);
    printf("&a: %p\n", &a);
    printf("p: %p\n", p);
    return 0;
}

/*
 * 结论：
 *  C语言中的const变量
 *    C语言中const变量是只读变量，有自己的存储空间
 *  C++中的const变量
 *    可能分配存储空间，也可能不分配存储空间
 *    当const常量为全局，并且需要在其他文件中使用，会分配存储空间
 *    当使用&操作符去const常量的地址，会分配存储空间
 */

// const 分配内存的时机， 是在编译器编译期间

int main()
{
    int a;
    const int b = 10;
    int c;

    printf("&a = %p\n", &a);
    printf("&b = %p\n", &b);
    printf("&c = %p\n", &c);
}

// 打印结果发现，a b c地址是连续的，b的地址位于a和c之间
// 因此 const 分配内存的时机并不是在 printf("&b = %p\n", &b); 时才分配的
