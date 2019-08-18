//
// Created by YANHAI on 2019/5/25.
//


// 拷贝构造函数的第4种应用场景

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

    ~Test()
    {
        cout << "执行了析构函数" << endl;
    }

    void print()
    {
        cout << "a: " << m_a << ", b: " << m_b << endl;
    }

private:
    int m_a;
    int m_b;
};

// 返回的是匿名对象
/**
 * 返回一个对象元素
 * 结论1 函数的返回值是一个元素（复杂类型的，如对象），返回的是一个新的匿名对象
 *       （所以会调用匿名对象类的拷贝构造函数）
 *      **但是，这里测试并没有产生新的对象（没有调用拷贝构造函数），难道是新版本C++的新特性？**
 *      博客园： https://www.cnblogs.com/yanhai307/p/10935665.html
 * 结论2 有关匿名对象（函数返回的对象）的去和留
 *    如果用匿名对象 初始化 另外一个同类型的对象，匿名对象 转为有名对象
 *    如果用匿名对象 赋值给 另外一个同类型的对象，匿名对象 被析构
 *
 * @return
 */

Test func()
{
    Test t(1, 2);   // 调用了有参构造函数
    printf("in func t: %p\n", &t);

    // 教程：1. 调用拷贝构造函数，2.调用析构函数，释放对象t，3.将匿名对象返回
    // 但是，这里测试，并没有调用拷贝构造函数，而是将局部对象t返回了，
    // 看objdplay2函数中，t1的地址和t地址是相同的。而且只执行了一次析构函数
    return t;
}

void objdplay1()
{
    func();
}

void objdplay2()
{
    Test t1 = func();   // t1初始化，匿名对象转正 为t1
    printf("in main t1: %p\n", &t1);
}

void objdplay3()
{
    Test t2;
    t2 = func();    // 1.用匿名对象 赋值 给t2对象，2.析构匿名对象
    printf("in main t2: %p\n", &t2);
}


int main()
{
    objdplay1();
    cout << "-------------" << endl;
    objdplay2();
    cout << "-------------" << endl;
    objdplay3();

    return 0;
}