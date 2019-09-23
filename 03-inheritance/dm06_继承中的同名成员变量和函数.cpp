//
// Created by YANHAI on 2019/9/1.
//

/* 
  继承中的同名成员变量处理方法

  1. 当子类成员变量与父类成员变量同名时，子类依然从父类继承同名成员
  2. 在子类中通过作用域符::进行同名成员区分（在子类中使用父类的同名成员，显式的使用类名限定符）
  3. 同名成员存储在内存中的不同位置

 
*/

#include <iostream>

using std::cout;
using std::endl;

class A {
public:
    int a;
    int b;

    void printA()
    {
        cout << "A: a: " << a << ", b:" << b << endl;
    }

    void print()
    {
        cout << "A: a: " << a << ", b:" << b << endl;
    }

};

class B : public A {
public:
    int b;
    int c;

    void printB()
    {
        cout << "B: b: " << b << ", c:" << c << endl;
    }

    void print()
    {
        cout << "B: b: " << b << ", c:" << c << endl;
    }


};

void test1()
{
    B b1;
    b1.b = 1;   // 默认是自己的成员
    b1.printA();
    b1.printB();
    b1.A::b = 2; // 使用父类的成员，使用域作用符
    b1.printA();
    b1.printB();
}

void test2()
{
    B b1;
    b1.print();
    b1.A::print();
}

int main()
{
    test1();
    test2();

    return 0;
}