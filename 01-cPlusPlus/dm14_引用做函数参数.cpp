//
// Created by YANHAI on 2019/4/24.
//


#include <iostream>

using namespace std;

// 这种方式是无法对实参完成交换的，要想交换必须对实参取地址传入
void swap01(int a, int b)
{
    int c;
    c = a;
    a = b;
    b = c;
}

// 通过传入实参的地址，再通过取地址*进行赋值，完成交换
void swap02(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

// 形参a就是实参x的别名，修改a就是修改x，b同理
void swap03(int &a, int &b)
{
    int c;
    c = a;
    a = b;
    b = c;
}

int main()
{
    int x = 10;
    int y = 20;

    swap01(x, y);
    cout << "x: " << x << ", y: " << y << endl;

    swap02(&x, &y);
    cout << "x: " << x << ", y: " << y << endl;

    swap03(x, y);
    cout << "x: " << x << ", y: " << y << endl;
    return 0;
}

/*
 * 引用的意义：
 *  1.引用作为其他变量的别名而存在，因此在一些场合可以代替指针
 *  2.引用相对于指针来说具有更好的可读性和实用性
 */
