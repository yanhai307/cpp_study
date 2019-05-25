//
// Created by YANHAI on 2019/5/25.
//

// 拷贝构造函数的4种调用场景
// 拷贝构造函数是用一个对象去初始化另外一个对象

#include <iostream>
#include <string.h>

using namespace std;

class Test {
public:
    // 无参构造函数
    Test()
    {
        cout << "我是无参构造函数。。被调用了。。" << endl;
    }

    Test(int a)
    {
        m_a = a;
        m_b = 0;
        cout << "我是一个有1个参数的构造函数。。被调用了。。" << endl;
    }

    // 参构造函数
    Test(int a, int b)
    {
        m_a = a;
        m_b = b;
        cout << "我是一个有2个参数的构造函数。。被调用了。。" << endl;
    }

    // 拷贝构造函数
    Test(const Test &obj)
    {
        m_a = obj.m_a;
        m_b = obj.m_b;
        cout << "我也是构造函数。。" << endl;
    }

    void print()
    {
        cout << "a: " << m_a << ", b: " << m_b << endl;
    }

private:
    int m_a;
    int m_b;
};

int main()
{
    Test t0(1, 2);
    Test t1(1, 2);

    // 赋值=操作 不会调用构造函数
    // operator=(), 可以进行=操作符重载
    t0 = t1;  // 用t1给t0赋值，等号操作和初始化是两个不同的概念

    // 第1种调用方法
    Test t2 = t1; // 用t1来初始化t2
    t2.print();

    // 第2种调用方法
    Test t3(t1);
    t3.print();

    return 0;
}
