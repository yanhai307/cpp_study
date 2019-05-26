//
// Created by YANHAI on 2019/5/26.
//

#include <iostream>

using namespace std;

class A {
public:
    A(int _a)
    {
        a = _a;
        cout << "构造函数 a: " << a << endl;
    }

    ~A()
    {
        cout << "析构函数 a: " << a << endl;
    }

private:
    int a;
};


// 构造函数的初始化列表  解决：在B类中 组合了一个A类对象（A类设计了构造函数）
// 根据构造函数的调用规则  设计A的构造函数， 必须要用，没有机会初始化A
// 新的语法  Constructor::Constructor():m1(v1), m2(v2),m3(v3)
class B {
public:
#if 0
    // 这样初始化a1 a2是不对的，必须使用初始化列表进行初始化
    B()
    {
        a1 = A(1);
        a2 = A(2);
        b = _b;
    }
#else

    B() : a1(1), a2(2), b2(0)
    {
        b = 1;
        cout << "构造函数 b: " << b << endl;
    }

    // 这是最常用的
    B(int _b, int m, int n) : a2(m), a1(n), b2(0)
    {
        b = _b;
        cout << "构造函数 b: " << b << endl;
    }

    ~B()
    {
        cout << "析构函数 b: " << b << endl;
    }

#endif
private:
    int b;
    const int b2;
    A a1;
    A a2;
};

void fun1()
{
    // 1.
    // 在没有设计B的构造函数时，这里是无法定义对象的，
    // 因为类A构造函数需要一个参数，而类B中没有对成员变量 a1 a2进行初始化操作
    B b1;
}

void fun2()
{
    // 2 3 是对A类的传参
    B b2(1, 2, 3);

    // 2.
    // 在创建B类对象时，先执行谁的构造函数 ？
    // 先执行 被组合对象的构造函数（如这里的A类），
    // 如果组合对象有多个（如B类的成员变量 a1 a2），按照定义顺序，而不是按照初始化列表的顺序
    // 析构函数 和构造函数的调用顺序相反
    // 由于在B类中，先定义了a1，后定义了a2， 所以先执行a1的构造函数，再执行a2的构造函数，最后执行B类的构造函数

    // 3. 初始化列表 用于对const变量赋值（如B类中的成员变量b2必须使用初始化列表进行初始化）

    // 4. 拷贝构造函数也是构造函数，因此也可以使用初始化列表
}

int main()
{
    fun1();
    cout << "----------" << endl;
    fun2();
    return 0;
}
