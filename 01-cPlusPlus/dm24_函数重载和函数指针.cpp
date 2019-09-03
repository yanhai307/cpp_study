//
// Created by YANHAI on 2019/5/3.
//

/*
 * 函数重载和函数指针结合
 *   当使用重载函数名对函数指针进行赋值时
 *   根据重载规则挑选与函数指针参数列表一致的候选者
 *   严格匹配候选者的函数类型与函数指针的函数类型
 */
#include <iostream>

using namespace std;

void myfunc(int a)
{
    cout << "a: " << a << endl;
}

void myfunc(const char *p)
{
    cout << "p: " << p << endl;
}

void myfunc(int a, int b)
{
    cout << "a: " << a << ", b: " << b << endl;
}

///*
// * 函数指针 基础的语法
// *   声明一个函数类型
typedef void (myTypeFunc)(int a, int b);
//myTypeFunc *myfuncp = NULL;  // 定义一个函数指针， 这个指针指向函数的入口地址

// *   声明一个函数指针类型
typedef void (*myPTypeFunc)(int a, int b);
//myPTypeFunc myfuncp = NULL; //通过函数指针类型 定义了 一个函数指针

// *   定义一个函数指针变量
void (*myVarPFunc)(int a, int b);
// */

// void myfunc(int a, int b)


int main()
{
    myPTypeFunc myfuncp = myfunc;
    myfuncp(1, 2);

//    myfuncp(1);
//    myfuncp("aaa");

    return 0;
}

