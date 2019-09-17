//
// Created by YANHAI on 2019/8/18.
//

/**
 * 派生类继承了基类的全部成员变量和成员方法（除了构造和析构之外的成员方法），
 * 但是这些成员的访问属性，在派生过程中是可以调整的。
 *
 * 判断一个成员或函数，能否被访问
 *     1. 看调用语句，这句话写在子类内部还是外部
 *     2. 看子类如何从父类继承（public protected private）
 *     3. 看父类中的访问级别（public protected private）
 *
 * 派生类类成员访问级别设置的原则
 *     1. 需要被外界访问的成员直接设置为public
 *     2. 只能在当前类访问的成员设置为private
 *     3. 只能在当前类和子类中访问的成员变量设置为protected，
 *
 * protected 关键字 修饰的成员变量和成员函数，是为了在家族中使用，是为了继承
 * 项目开发中，一般使用public继承
 */

#include <iostream>

using namespace std;


/**
 * public 修饰的成员变量方法 在类的内部和外部都能使用
 * protected 修饰的成员变量方法 在类的内部使用，在继承的子类中可用
 * private 修饰的成员变量方法只能在类的内部使用，不能在类的外部使用
 */
class Parent {
public:
    void printT()
    {
        cout << "printT" << endl;
    }

public:
    int a;
protected:
    int b;
private:
    int c;
};

// ======= 公有继承 ==========
class Child1 : public Parent {
public:
    void useVar()
    {
        a = 0;  // ok
        b = 1;  // ok
//        c = 2;// err
    }
};

void test_public()
{
    Child1 c;
    c.a = 1;    // ok
//    c.b = 2;  // err
//    c.c = 3;  // err
}

// ========== 保护继承 ==============
class Child2 : protected Parent {
public:
    void useVar()
    {
        a = 0;  // ok
        b = 1;  // ok
//        c = 2;// err
    }
};

void test_protected()
{
    Child2 c;
//    c.a = 1;  // err
//    c.b = 2;  // err
//    c.c = 3;  // err
}

// ========= 私有继承 =============
class Child3 : private Parent {
public:
    void useVar()
    {
        a = 0;  // ok
        b = 1;  // ok
//        c = 2;// err
    }
};

void test_private()
{
    Child3 c;
//    c.a = 1;  // err
//    c.b = 2;  // err
//    c.c = 3;  // err
}

int main()
{
    Parent t1;
    t1.a = 10;  // ok
//    t1.b = 20;    // err
//    t1.c = 30;    // err

    test_public();
    test_protected();
    test_private();
    return 0;
}
