//
// Created by YANHAI on 2019/5/25.
//

// 拷贝构造函数的第3种应用场景

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

void func(Test t)
{
    t.print();
    printf("in func t: %p\n", &t);
}

int main()
{
    Test t1(1, 2);
    printf("in main t1: %p\n", &t1);

    Test t2 = t1;   // 调用拷贝构造函数
    printf("in main t2: %p\n", &t2);
    t2.print();

    // 第3种调用方式
    func(t1);   // 用实参t1来初始化形参t，会调用拷贝构造函数
    return 0;
}