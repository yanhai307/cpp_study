
/* 面试题1：为什么要定义虚析构函数？
            想通过父类的指针 把所有的子类对象的析构函数都执行一遍
            想通过父类指针 释放所有的子类资源
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using std::cout;
using std::endl;

class A {
public:
    A()
    {
        p = new char[20];
        strcpy(p, "hello A");
        cout << "A()" << endl;
    }

    virtual ~A()
    {
        delete[]p;
        cout << "~A()" << endl;
    }

private:
    char *p;
};

class B : public A {
public:
    B()
    {
        p = new char[20];
        strcpy(p, "hello B");
        cout << "B()" << endl;
    }

    ~B()
    {
        delete[]p;
        cout << "~B()" << endl;
    }

private:
    char *p;
};

class C : public B {
public:
    C()
    {
        p = new char[20];
        strcpy(p, "hello C");
        cout << "C()" << endl;
    }

    ~C()
    {
        delete[]p;
        cout << "~C()" << endl;
    }

private:
    char *p;
};

void test1()
{
    cout << "test1" << endl;
    C *c = new C;
    delete c;
}

//不写 virtual关键字的时候
//  只执行了 父类的析构函数
//  想通过父类的指针 把所有的子类对象的析构函数都执行一遍
//  想通过父类指针 释放所有的子类资源
void howtodelete(A *base)
{
    delete base;    // 不会表现为多态
}

void test2()
{
    cout << "test2" << endl;
    C *c = new C;
    howtodelete(c);
}

int main()
{
    test1();
    test2();
    return 0;
}
