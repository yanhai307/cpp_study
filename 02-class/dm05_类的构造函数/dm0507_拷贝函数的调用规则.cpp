//
// Created by YANHAI on 2019/5/25.
//

/**
 * 构造函数的调用规则
 *  1. 当类中没有定义任何一个构造函数时，c++编译器会提供默认无参数构造函数和默认拷贝构造函数
 *  2. 当类中定义了拷贝构造函数时，c++编译器不会提供无参数构造函数
 *  3. 当类中定义了有参数构造函数时，c++编译器不会提供无参数构造函数
 *  4. 默认拷贝构造函数成员变量简单赋值。（浅拷贝）
 *  总结：只要你写了构造函数，那么你必须使用。
 *
 *  构造析构阶段性总结：
 *  1. 构造函数是C++中用于初始化对象状态的特殊函数
 *  2. 构造函数在对象创建时自动被调用
 *  3. 构造函数和普通成员函数都遵循重载规则
 *  4. 拷贝构造函数时对象正确初始化的重要保证
 *  5. 必要的时候，必须手工编写拷贝构造函数
 */

#include <iostream>

using namespace std;

class A {
public:

    A(int _a)
    {
        a = _a;
    }

    A(const A &obj)
    {
        a = obj.a;
    }

    void print()
    {
        cout << "a: " << a << endl;
    }

private:
    int a;
};

class B {
public:

    B(int _a)
    {
        a = _a;
    }

    void print()
    {
        cout << "a: " << a << endl;
    }

private:
    int a;
};


int main()
{
//    A a1;    // 失败，因为没有默认构造函数可以使用
    A a2(1); // ok，
    A a3 = 2; // ok

//    B b1; // 失败，因为没有默认构造函数可以使用
    B b2(2);    // ok
    B b3(b2);   // ok 有默认拷贝构造函数
    b3.print();
    return 0;
}