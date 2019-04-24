//
// Created by YANHAI on 2019/4/24.
//

#include <iostream>
using namespace std;

/*
 * 引用的概念
 * 属于C++编译器对C的扩展，不能用C语言的语法去思考它
 */

int main()
{
    int a = 10;

    // 引用的语法：Type &name = var;
    int &b = a;

//    int &c; //普通引用 必须要初始化

    b = 20; // 相当于把a修改成20了

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    a = 200;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    return 0;
}
