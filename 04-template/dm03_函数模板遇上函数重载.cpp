//
// Created by yanhai on 2019/9/23.
//

/**
 * 函数模板不允许自动类型转换
 * 普通函数能够进行自动类型转换
 */

#include <iostream>

using std::cout;
using std::endl;

template<typename T>
void myswap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
    cout << "我是模板函数..." << endl;
}

void myswap(int a, char b)
{
    cout << "我是普通函数..." << endl;
}

int main()
{
    int a = 10;
    char b = 'z';

    // 普通函数的调用，可以进行隐式类型转换
    myswap(a, b);
    myswap(b, a);   // 隐式的类型转换

    // 调用模板函数（本质：类型参数化），将严格的按照类型进行匹配，不会进行自动类型转换
    myswap(a, a);

    return 0;
}
