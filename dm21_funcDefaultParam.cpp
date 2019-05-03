//
// Created by YANHAI on 2019/5/3.
//

/*
 * C++中可以在函数声明时为参数提供一个默认值，
 * 当函数调用时没有指定这个参数的值，编译器会自动用默认值代替
 */

#include <iostream>

using namespace std;

void myPrint(int x = 3)
{
    cout << "in myPrint: x: " << x << endl;
}

// 2. 默认参数规则，如果默认参数出现，那么右边的都必须有默认参数
void myPrint2(int x, int y = 3, int z = 4)
//void myPrint2(int x, int y = 3, int z = 4, int m)
{
    cout << "in myPrint2: x: " << x << ", y: " << y << ", z: " << z << endl;
}

// 只在函数声明时写参数默认值即可
void myPrint3(int x, int y = 3);

int main()
{
    // 1. 若，写填写参数，使用你填写的，不写参数则使用默认参数
    myPrint(10);
    myPrint();

    myPrint2(1);

    myPrint3(10, 5);
    myPrint3(10);
    return 0;
}

void myPrint3(int x, int y)
{
    cout << "in myPrint3: x: " << x << ", y: " << y << endl;
}
