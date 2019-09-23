//
// Created by YANHAI on 2019/9/1.
//

#include <iostream>

using std::cout;
using std::endl;

class Parent {
public:
    Parent(int a)
    {
        this->a = a;
        cout << "Parent a:" << a << endl;
    }

    //virtual void print()
    void print()
    {
        cout << "Parent::print" << a << endl;
    }

private:
    int a;
};

class Child : public Parent {
public:
    Child(int b) : Parent(10)
    {
        this->b = b;
        cout << "Child b:" << b << endl;
    }

    // 父类写了virtual关键字，子类可以不写，建议写上，醒目
    //virtual void print()
    void print()
    {
        cout << "Child::print" << b << endl;
    }

private:
    int b;
};

void test1()
{
    Parent *base = NULL;
    Parent p1(20);
    Child c1(30);

    base = &p1;
    base->print();  // 执行父类的打印函数

    base = &c1;
    base->print();  // 执行谁的打印函数？父类的
}

void test2()
{
    Parent p1(20);
    Child c1(30);

    Parent &base1 = p1;
    base1.print();  // 执行父类的打印函数

    Parent &base2 = c1;
    base2.print();  // 执行谁的打印函数？父类的
}


int main()
{
    test1();
    test2();
    return 0;
}

/*
    编译器的做法不是我们期望的
       根据实际的对象类型来判断重写函数的调用
       如果父类指针指向的是父类对象则调用父类中定义的函数
       如果父类指针指向的是子类对象则调用子类中定义的重写函数

    解决方案
       C++中的多态支持
       C++中通过virtual关键字对多态进行支持
       使用virtual声明的函数被重写后即可展现多态特性
*/