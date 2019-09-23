//
// Created by YANHAI on 2019/9/19.
//

/**
 *  C++提供两种模板机制：函数模板和类模板
 *
 *   所谓函数模板，实际上是建立一个通用函数，其函数类型和形参类型不具体指定，
 *   用一个虚拟的类型来代表。这个通用函数就称为函数模板。
 */

#include <iostream>

using namespace std;

/**
 * 为什么要有模板函数，实现多种类型的变量交换函数
 */
// int类型的
void myswap_int(int &a, int &b)
{
    int c;
    c = a;
    a = b;
    b = c;
}

// char类型的
void myswap_char(char &a, char &b)
{
    char c;
    c = a;
    a = b;
    b = c;
}

void test1()
{
    // int
    {
        int a = 10;
        int b = 20;
        cout << "a: " << a << ", b: " << b << endl;
        myswap_int(a, b);
        cout << "a: " << a << ", b: " << b << endl;
    }

    // char
    {
        char a = 'a';
        char b = 'b';
        cout << "a: " << a << ", b: " << b << endl;
        myswap_char(a, b);
        cout << "a: " << a << ", b: " << b << endl;
    }
}

/**
 * 上面逻辑都一样，就是参数类型不同，有没有统一的函数
 * 使用模板
 */
template<typename T>
void myswap(T &a, T &b)
{
    T c;
    c = a;
    a = b;
    b = c;
}

void test2()
{
    cout << "----------template-----------" << endl;

    // int
    {
        int a = 10;
        int b = 20;
        cout << "a: " << a << ", b: " << b << endl;
        myswap<int>(a, b);  // 显式类型调用
        cout << "a: " << a << ", b: " << b << endl;
        myswap(a, b);  // 自动类型推导
        cout << "a: " << a << ", b: " << b << endl;
    }

    // char
    {
        char a = 'a';
        char b = 'b';
        cout << "a: " << a << ", b: " << b << endl;
        myswap<char>(a, b); // 显式类型调用
        cout << "a: " << a << ", b: " << b << endl;
        myswap(a, b);  // 自动类型推导
        cout << "a: " << a << ", b: " << b << endl;
    }
}

int main()
{
    test1();
    test2();
    return 0;
}
