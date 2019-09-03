//
// Created by YANHAI on 2019/4/27.
//

/*
 * 函数返回值是引用（引用当左值）
 */

#include <iostream>

using namespace std;

int getAA1()
{
    int a;
    a = 10;
    return a;
}

// 返回a的本身，返回a的一个副本10
int &getAA2()
{
    int a;  // 如果返回栈上的引用，有可能会有问题
    a = 10;
    // 返回引用，其实是返回的a的内存地址，C++编译器帮我们取了地址
    return a;
}

int *getAA3()
{
    int a;
    a = 10;
    return &a;
}

/*
 * 当函数返回值为引用时
 *   若返回栈变量
 *     不能成为其他引用的初始值
 *     不能作为左值使用
 */
int main01()
{
    int a1;
    int a2;

    a1 = getAA1();  // 10
//    a2 = getAA2();  // 10

//    int &a3 = getAA2(); //a3存放的是局部变量a的内存地址

    cout << "a1: " << a1 << endl;
//    cout << "a2: " << a2 << endl;
//    cout << "a3: " << a3 << endl;

    return 0;
}

int getBB1()
{
    static int b = 10;
    b++;
    return b;
}

int &getBB2()
{
    static int b = 10;
    b++;
    return b;
}

int *getBB3()
{
    static int b = 10;
    b++;
    return &b;
}

/*
 * 当函数返回值为引用时
 *   如返回静态变量或者全局变量
 *     可以成为其他引用的初始值
 *     即可作为右值使用，也可作为左值使用
 */
int main02()
{
    int b1;
    int b2;
    b1 = getBB1();
    b2 = getBB2();
    int &b3 = getBB2();

    cout << "b1: " << b1 << endl;
    cout << "b2: " << b2 << endl;
    cout << "b3: " << b3 << endl;
    return 0;
}

//- -------作左值使用-------------
//
int getCC1()
{
    static int c = 10;
    c++;
    return c;
}

int &getCC2()
{
    static int c = 10;
    c++;
    cout << "int getCC2: c: " << c << endl;
    return c;
}

int main03()
{
//    getCC1() = 100; 相当于 11 = 100;
    getCC2() = 100; // 函数返回值是一个引用，并且当左值
    getCC2();   // 用于打印c的值，是否被修改
    return 0;
}

int main()
{
    main01();
    main02();
    main03();
    return 0;
}

/*
 * C++链式编程中，经常用到引用，运算符重载专题
 */
