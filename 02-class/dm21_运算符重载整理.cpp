//
// Created by YANHAI on 2019/8/17.
//

#include <iostream>

using namespace std;

class Complex {
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
int main()
{
    Complex c1(1, 2);
    c1.info();

    // 全局函数法，实现前置++运算符重载
    // Complex &operator++(Complex &c1);
    ++c1;
    c1.info();

    // 成员函数法，实现前置--运算符重载
    //Complex &operator--();
    --c1;
    c1.info();

    // 全局函数法，实现后置++运算符重载
    //Complex operator++(Complex &c1);
    c1++;
    c1.info();

    // 成员函数法，实现后置--运算符重载
    //Complex operator--();
    c1--;
    c1.info();

    return 0;
}
