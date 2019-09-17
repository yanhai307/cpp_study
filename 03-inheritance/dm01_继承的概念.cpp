//
// Created by YANHAI on 2019/8/18.
//

/**
 * c++中的继承方式（public protected private）会影响子类的对外访问属性
 *
 * 继承的重要说明
 *      1. 子类拥有父类的所有成员变量和成员函数
 *      2. 子类可以拥有父类没有的方法和属性
 *      3. 子类就是一种特殊的父类
 *      4. 子类对象可以当做父类对象使用
 *
 */

#include <iostream>

using namespace std;

class Parent {
public:
    int a;
    int b;

    void print()
    {
        cout << "a: " << a << ", b: " << b << endl;
    }
};

// class Child : protected Parent { 保护继承
// class Child : private Parent {   私有继承
class Child : public Parent {       // 公有继承
public:
    int c;
};

int main()
{
    Child a;
    a.a = 1;
    a.b = 2;
    a.c = 3;

    a.print();
    return 0;
}