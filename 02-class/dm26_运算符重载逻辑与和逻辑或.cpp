//
// Created by YANHAI on 2019/8/17.
//

/**
 * 不要重载 && 和 || 操作符，因为重载后无法实现短路规则
 */

#include <iostream>

using namespace std;

class Test {
private:
    int i;
public:
    Test(int i)
    {
        this->i = i;
    }

    Test operator+(const Test &obj)
    {
        cout << "执行了+号重载函数" << endl;
        Test tmp(i + obj.i);
        return tmp;
    }

    bool operator&&(const Test &obj)
    {
        cout << "执行了&&重载函数" << endl;
        return i && obj.i;
    }
};

int main()
{
    int a1 = 0;
    int a2 = 1;
    cout << "注意：&&操作符的结合顺序是从左向右的" << endl;

    if (a1 && (a1 + a2))
        cout << "有一个是假，则不再执行下一个表达式的计算" << endl;

    Test t1 = 0;
    Test t2 = 1;

    // 1. && || 重载他们 不会产生短路效果
    // t1为假，理论上后面的t1+t2是不会被执行的，但是重载&&之后，改变了正常的逻辑，造成程序逻辑错误，因此不建议重载&&和||等逻辑操作符
    if (t1 && (t1 + t2)) {
        // 运行逻辑是：
        // t1 && t1.operator+(t2)
        // t1.operator&&(t1.operator+(t2))
        cout << "两个运算符重载函数都被执行了，而且是先执行了+" << endl;
    }

    // 2. && 运算符的结合性
    // 两个逻辑与运算符在一块的时候，才去谈运算符的结合性
    // 从左到右
//    if ((t1+t2) && t1 && t2)

    return 0;
}
