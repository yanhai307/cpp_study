//
// Created by YANHAI on 2019/5/3.
//

/*
 * 1. 函数重载的概念
 *   函数重载
 *     用同一个函数名定义不同的函数
 *     当函数名和不同的参数搭配时函数的含义不同
 *  2. 函数重载的判断标准
 *    函数重载至少满足下面的一个条件
 *      参数个数不同
 *      参数类型不同
 *      参数顺序不同
 *  3. 函数返回值不是函数重载的判断标准
 *  难点：
 *    重载函数和默认参数混搭
 *    重载函数和函数指针
 */

#include <iostream>
using namespace std;

void myPrint(int a)
{
    cout << "a: " << a << endl;
}

void myPrint(const char *p)
{
    cout << "p: " << p << endl;
}

void myPrint(int a, int b)
{
    cout << "a: " << a << ", b: " << b << endl;
}

// 函数返回值不是函数重载的判断标准
//int myPrint(int a, int b)
//{
//    cout << "a: " << a << ", b: " << b << endl;
//}


int main1()
{
    myPrint(10);
    myPrint("hello world");
    myPrint(1, 2);
    return 0;
}

/*
 * 函数重载的注意事项
 *      函数重载在本质上是相互独立的不同函数（静态链编）
 *      函数重载的函数类型是不同的
 *      函数返回值不能作为函数重载的依据
 *      函数重载是由函数名和参数列表决定的。
 */
// 函数重载是发生在一个类里面的

//-------------------------

/*
 * 函数默认参数 和 函数重载 在一起
 */
int func(int a, int b, int c=0)
{
    return a+b+c;
}

int func(int a, int b)
{
    return a+b;
}

int main2()
{
//    func(10, 20); // 函数调用时，会产生二义性，编译失败
    func(10, 20, 30);
    return 0;
}

int main()
{
    main1();
    main2();
    return 0;
}