
/*
   面试题6： 在构造函数中调用虚函数，会发生多态吗？
                不会
    面试题7：虚函数表指针VPTR被编译器初始化的过程，你是如何理解的？
                1. 要初始化 c1.vptr指针，初始化是分步的
                2. 当执行父类的构造函数的时候，c1.vptr指向父类的虚函数表
                   当父类的构造函数运行完毕后，会把c1.vptr指向子类的虚函数表

*/

#include <iostream>

using std::cout;
using std::endl;

class Parent {
public:
    Parent(int a = 0)
    {
        this->a = a;
    }

    virtual void print()
    {
        cout << "Parent print()" << endl;
    }

private:
    int a;
};

class Child : public Parent {
public:
    Child(int a = 1, int b = 2) : Parent(a)
    {
        this->b = b;
    }

    virtual void print()
    {
        cout << "Child print()" << endl;
    }

private:
    int b;
};

int main()
{
    // 定义一个子类对象，在这个过程中，在父类构造函数中调用虚函数print，能发生多态吗
    // 
    Child c1;
    // 1. 要初始化 c1.vptr指针，初始化是分步的
    // 2. 当执行父类的构造函数的时候，c1.vptr指向父类的虚函数表
    //     当父类的构造函数运行完毕后，会把c1.vptr指向子类的虚函数表
    // 3. 结论：子类的c1.vptr指针分步完成

    return 0;
}
