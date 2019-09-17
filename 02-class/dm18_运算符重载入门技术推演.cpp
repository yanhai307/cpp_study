//
// Created by YANHAI on 2019/8/17.
//

/**
 * 定义运算符重载函数名的步骤
 * 1.要承认操作符重载是一个函数，写出函数名称
 * 2、根据操作数，写出函数参数
 * 3.  根据业务，完善函数返回值（看函数是返回引用还是指针还是元素），及实现函数业务
 */


#include <iostream>

using namespace std;

class Complex {
public:
    int a;
    int b;
public:
    Complex(int a = 0, int b = 0)
    {
        this->a = a;
        this->b = b;
    }

    void info()
    {
        cout << a << " + " << b << "i" << endl;
    }
};

Complex myAdd(Complex &c1, Complex &c2)
{
    Complex tmp(c1.a + c2.a, c1.b + c2.b);
    return tmp;
}

Complex operator+(Complex &c1, Complex &c2)
{
    Complex tmp(c1.a + c2.a, c1.b + c2.b);
    return tmp;
}

int main()
{
    int a = 0, b = 0;
    int c;
    c = a + b;  //基础数据类型，编译器已经知道了如何运算

    // a + bi 复数运算规则
    Complex c1(1, 2), c2(3, 4);
    Complex c3; //类也是一种数据类型，用户自定义数据类型，C++编译器 是不知道如何进行运算的
//    c3 = c1 + c2;

    // c++编译器应该给我们程序员提供一种机制....
    // 让自定义数据类型 有机会进行 运算符操作 ====》运算符重载机制

    // 步骤1
//    Complex c4 = myAdd(c1, c2);
//    c4.info();

    // 步骤2
//    Complex c4 = operator+(c1, c2);
//    c4.info();

    // 步骤3
    Complex c4 = c1 + c2;
    c4.info();

    // 总结：运算符重载的本质 是 函数调用

    return 0;
}
