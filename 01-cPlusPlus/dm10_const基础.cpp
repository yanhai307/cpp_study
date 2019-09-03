//
// Created by YANHAI on 2019/4/21.
//

#include <iostream>

using namespace std;

int main()
{
    int a = 10;

    // b 和 c 效果是一样的, 代表一个常整型数
    const int b = 10;
    int const c = 20;

    // d是一个指向常整型数的指针， const修饰的是指针所指向的内存空间，
    // 所指向的内存空间数据不能被修改，但是本身可以修改
    const int *d;

    // e是一个常指针， const修饰的变量e本身，
    // 指针变量不能被修改，但是他指向的内存空间可以被修改
    int *const e = &a;

    // f是一个指向常整型的常指针
    // 指针和他所指向的内存空间，均不能被修改
    const int *const f = &b;

    return 0;
}

struct Teacher {
    char name[32];
    int age;
};

// 指针所指向的内存空间，不能被修改
int operatorTeacher01(const Teacher *pT)
{
//    pT->age = 10;
    pT = NULL;
    return 0;
}

// 指针变量本身不能被修改
int operatorTeacher02(Teacher *const pT)
{
    pT->age = 10;
//    pT = NULL;
    return 0;
}

// 指针变量本身以及所指向的内存空间均不可被修改
int operatorTeacher03(const Teacher *const pT)
{
//    pT->age = 10;
//    pT = NULL;
    printf("age: %d\n", pT->age);
    return 0;
}

/*
 * const的好处，合理的利用const
 *  1. 指针做函数参数，可以有效的提高代码的可读性，减少bug
 *  2. 清楚的分清参数的输入和输出特性
 */

