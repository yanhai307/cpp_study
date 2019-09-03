//
// Created by YANHAI on 2019/5/26.
//

// 每个变量，拥有属性。有没有一些属性，归所有对象拥有？

/**
 * 1. 定义静态成员变量
 *   > 关键字 static 可以用于说明一个类的成员，静态成员提供了一个同类对象的共享机制。
 *   > 把一个类的成员说明为static时，这个类无论有多少个对象被创建，这些对象共享这个static成员
 *   > 静态成员作用于类，他不是对象成员
 */

#include <iostream>
using namespace std;

class Test{
public:
    void printC()
    {
        cout << "c: "<< c << endl;
    }
    void addC()
    {
        c +=1;
    }

    /*
     * 在静态成员函数中，
     * 不可以调用普通（非静态）成员属性
     * 不可以调用普通（非静态）成员方法
     */
    static void getC()  // 静态成员函数
    {
        cout << "c: "<< c << endl;
//        cout << "a: "<< a << endl;    // error
    }

private:
    int a;
    int b;
    static int c;   // 静态成员变量
};

// 这里定义变量并初始化，类里面只是声明
int Test::c = 10;

int main()
{
    Test t1, t2, t3;

    t1.printC();    // 10
    t2.addC();      // 11
    t3.printC();    // 11

    // 静态成员函数的调用方法
    t1.getC();      // 用对象
    Test::getC();   // 类::
    return 0;
}
