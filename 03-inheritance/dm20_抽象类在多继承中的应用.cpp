
/*
    接口类
      所有的函数均为纯虚函数

*/

#include <iostream>

using std::cout;
using std::endl;

class Interface1 {
public:
    virtual int add(int a, int b) = 0;

    virtual void print() = 0;
};

class Interface2 {
public:
    virtual int mult(int a, int b) = 0;

    virtual void print() = 0;
};

class Parent {
public:
    Parent()
    {
        this->a = 0;
    }

    int getA()
    {
        return a;
    }

private:
    int a;
};

class Child : public Parent, public Interface1, public Interface2 {
public:
    virtual int add(int a, int b)
    {
        cout << "Child: add()" << endl;
        return a + b;
    }

    virtual void print()
    {
        cout << "Child: print()已经执行\n";
    }

    virtual int mult(int a, int b)
    {
        cout << "Child: mult()已经执行\n";
        return a * b;
    }
};

int main()
{
    Child c1;
    c1.print();

    Interface1 *it1 = &c1;
    it1->add(1, 2);

    Interface2 *it2 = &c1;
    it2->mult(3, 6);

    return 0;
}
