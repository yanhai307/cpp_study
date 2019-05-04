//
// Created by YANHAI on 2019/4/21.
//

#include <iostream>
using namespace std;

//const 和 #define的相同之处

int main1()
{
#define A 1
#define B 2
    int a = 10;
    int b = 20;

    const int c = 10;
    const int d = 20;

    // 这种写法，有些编译器可以编译通过，有些编译器编译不通过
    int array1[a+b];

    // 下面都是可以编译通过的
    int array2[A+B];
    int array3[c+d];

    return 0;
}

/* const 和#define 的区别
 * C++中的const常量类似于宏定义
 *     const int c = 5;  === #define c 5
 * C++中的const常量与宏定义不同
 *     const常量由编译器处理的，提供类型检查和作用域检查
 *     宏定义由预处理器处理，单纯的文本替换
 */

void fun1()
{
#define a 10
    const int b = 20;
//#undef a
}

void fun2()
{
    printf("a = %d\n", a);
//    printf("b = %d\n", b);
}

int main()
{
    fun1();
    fun2();
    return 0;
}

/*
 * 结论：
 *   C语言中的const变量
 *     C语言中的const变量是只读变量，有自己的存储空间
 *   C++中的const常量
 *     可能分配存储空间，也可能不分配存储空间
 *     当const常量为全局，并且需要在其它文件中使用，会分配存储空间
 *     当使用&操作符，取const常量的地址时，会分配存储空间
 *     当 const int &a = 10; const修饰引用时，也会分配存储空间
 */
