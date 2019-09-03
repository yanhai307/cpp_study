//
// Created by yanhai on 2019/8/17.
//

/**
 * 用友元函数 重载 << >>操作符
 *
 * 其他：
 *    1. 在第一个参数需要隐式转换的情形下，使用友元函数重载运算符是正确的选择
 *    2、友元函数没有this指针，所需操作数都必须在参数表显式声明，很容易实现类型的隐式转换
 *    3.C++中不能用友元函数重载的运算符有： =   ()   []    ->
 */

#include <iostream>

using namespace std;

class Complex {
    friend ostream &operator<<(ostream &out, Complex &c1);

private:
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

    // 2. 成员函数法 实现-运算符重载
    Complex operator-(Complex &c2)
    {
        Complex tmp(a - c2.a, b - c2.b);
        return tmp;
    }

    // 实现+运算符重载
    Complex operator+(Complex &c2)
    {
        Complex tmp(a + c2.a, b + c2.b);
        return tmp;
    }

    // 实现前置++运算符重载
    Complex &operator++()
    {
        a++;
        b++;
        return *this;
    }

// 全局函数法，实现后置++运算符重载
    Complex operator++(int)
    {
        Complex tmp(*this);
        a++;
        b++;
        return tmp;
    }


    // 成员函数法，实现前置--运算符重载
    Complex &operator--()
    {
        a--;
        b--;
        return *this;
    }

    Complex operator--(int)
    {
        Complex tmp(*this);
        a--;
        b--;
        return tmp;
    }
};


/**
 * 定义运算符重载函数名的步骤
 * 1.要承认操作符重载是一个函数，写出函数名称
 * 2、根据操作数，写出函数参数
 * 3.  根据业务，完善函数返回值（看函数是返回引用还是指针还是元素），及实现函数业务
 */
ostream &operator<<(ostream &out, Complex &c1)
{
    out << c1.a << " + " << c1.b << "i";
    return out;
}

int main()
{
    int a = 10;
    Complex c1(1, 2);

    cout << a << endl;

    //  operator<<(ostream &out, Complex &c1);
    // cout.operator<<(Complex &c1);
    cout << c1 << endl;

    return 0;
}
