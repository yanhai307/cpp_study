//
// Created by YANHAI on 2019/5/12.
//

// 构造函数的分类

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
    // 1. 调用无参数构造函数 ， C++自动调用
    Test t1;

    // 2. 调用有参数构造函数，有3种方法
    // 2.1 括号方式， C++自动调用
    Test t2();  // 这里括号里面没有写参数，故t2创建失败，只写这一行编译是不会报错的
//    t2.print(); // 这里就会报错了，因为t2根本就没有被成功创建

    // 2.2 等号法， C++自动调用
    // 下面这个一定要注意
    Test t3 = (3, 4);   // 调用的是含有一个参数的构造函数，因为 (3, 4)是一个逗号表达式，
                        // 表达式的值为4（最后一个值），因此这一行等价于 Test t3 = 4;
    t3.print();

    // 这里的等号，不能简单的理解为赋值操作
    // c++对等号 功能进行增强
    Test t4 = 5;
    t4.print();

    // 2.3 直接调用构造函数。 手动调用
    //  这里不能理解为 首先Test(1, 2)创建了一个对象，
    //  然后 又将这个对象拷贝给了 t5， 这里并没有执行拷贝构造函数
    //  应该理解为 Test(1, 2)创建的是一个匿名对象，关于这个匿名对象的生命周期，要看将它赋值给了谁
    // 这里只会执行一次构造函数。
    Test t5 = Test(1, 2);
    t5.print();

    // 调用拷贝构造函数初始化t6
    Test t6 = t5;

    t1 = t5;    // 这里不会调用拷贝构造函数，要注意，
                // 因为这里并不是在创建一个新的对象，
                // 无论什么构造函数都只有在产生一个新的对象时才有可能被调用
    t1.print();

    return 0;
}
