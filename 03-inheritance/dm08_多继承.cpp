
/*
  多继承
  概念：
    一个类有多个直接基类的继承关系成为多继承
  语法
   class 派生类名: 访问控制 基类名1, 访问控制 基类名2
  多继承的派生类构造和访问
    1. 多个基类的派生类构造函数可以用初始式调用基类构造函数初始化数据成员
    2. 执行顺序与单继承构造函数类似。多个直接基类构造函数执行顺序取决于定义派生类时指定的各个继承基类的顺序
    3. 一个派生类对象拥有多个直接或间接基类的成员。不同名成员访问不会出现二义性，
      如果不同的基类有同名成员，派生类对象访问时应该加以识别。
   

*/

#include <iostream>

using std::cout;
using std::endl;

class Base1 {
public:
    Base1(int b1)
    {
        a = 1;
        this->b1 = b1;
        cout << "Base1" << endl;
    }

    void printB1()
    {
        cout << "b1: " << b1 << endl;
    }


public:
    int a;
    int b1;
};

class Base2 {
public:
    Base2(int b2)
    {
        a = 2;
        this->b2 = b2;
        cout << "Base2" << endl;
    }

    void printB2()
    {
        cout << "b2: " << b2 << endl;
    }

public:
    int a;
    int b2;
};

class B : public Base1, public Base2 {
public:
    B(int b1, int b2, int b) : Base1(b1), Base2(b2)
    {
        this->a = 3;
        this->b = b;
        cout << "B" << endl;
    }

    void printB()
    {
        cout << "b: " << b << endl;
    }

public:
    int a;
    int b;
};

void test()
{
    B b(1, 2, 3);
    b.printB();
    b.printB1();
    b.printB2();

    cout << "b.a: " << b.a << endl;     // 默认是自己的成员变量
    cout << "b.Base1::a: " << b.Base1::a << endl;
    cout << "b.Base2::a: " << b.Base2::a << endl;

}

int main()
{
    test();
    return 0;
}