//
// Created by YANHAI on 2019/5/3.
//

#include <iostream>
using namespace std;

/*
 * 函数占位参数
 *   占位参数只有参数类型声明，而没有参数声明
 *   一般情况下，在函数体内部无法使用占位参数
 */
void myFunc(int a, int b, int)
{
    cout << "in myFunc: a: " << a << ", b: " << b << endl;
}

int main1()
{
    // 函数占位参数 函数调用时 必须写够参数
//    myFunc(1, 2);
    myFunc(1, 2, 3);
    return 0;
}

/*
 * 可以将占位参数与默认参数结合起来使用
 *  意义：
 *    为以后的程序的扩展留下线索
 *    兼容C语言程序中可能出现的不规范写法
 *
 */

void myFunc2(int a, int b, int = 0)
{
    cout << "in myFunc2: a: " << a << ", b: " << b << endl;
}

int main2()
{
    // 都可以
    myFunc2(1, 2);
    myFunc2(1, 2, 3);
    return 0;
}

int main()
{
    main1();
    main2();
    return 0;
}