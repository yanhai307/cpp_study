//
// Created by YANHAI on 2019/8/24.
//

/**
 * 继承中的类型兼容性原则
 *  1. 可以使用父类指针（引用）指向子类对象
 *  2. 可以使用子类对象初始化父类对象
 */

#include <iostream>

using namespace std;

class Parent {
public:
    Parent() { ; }

    Parent(const Parent &p)
    {
        cout << "Parent copy function" << endl;
        a = p.a;
        b = p.b;
    }

    void printP()
    {
        cout << "I am Parent" << endl;
    }

private:
    int a;
    int b;
};

// class Child : protected Parent { 保护继承
// class Child : private Parent {   私有继承
class Child : public Parent {       // 公有继承
public:
//    Child(const Child &_c)
//    {
//        cout << "Child copy function" << endl;
//        c = _c.c;
//    }
    void printC()
    {
        cout << "I am Child" << endl;
    }

private:
    int c;
};

void howToPrint(Parent *p)
{
    p->printP();
}

void howToPrint2(Parent &p)
{
    p.printP();
}

/**
 * 赋值兼容性原则，
 *
 */
void test1()
{
    // 1 父类指针指向子类对象
    Parent p1;
    Child c;
    Parent *p = &c;

    p->printP();

    // 2 指针做函数参数
    howToPrint(&p1);
    howToPrint(&c);

    // 3 引用做函数参数
    howToPrint2(p1);
    howToPrint2(c);
}

void test2()
{
    // 1. 可以让子类对象初始化父类对象
    // 子类就是一种特殊的父类
    Child c1;
    Parent p1 = c1;
}

int main()
{
    test1();
    test2();
    return 0;
}
