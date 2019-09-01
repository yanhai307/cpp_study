
/*
 继承中的static关键字
 1. static关键字 遵守 派生类的访问控制规则
*/

#include <iostream>

using std::cout;
using std::endl;

class A {

public: // 只有单例情况下（UML），才可以把构造函数定义为private
    A()
    {
        cout << "A的构造函数" << endl;
    }

public:
    static int a;
    int b;

};


int A::a = 100; // 2. 不是简单的变量赋值，更重要的是告诉编译器分配内存


class B : private A {
public:
    B()
    {
        cout << "B的构造函数 " << endl;
    }

    // 在类内部可以使用a
    void print()
    {
        cout << "a:" << a << endl;
    }
};

void test1()
{
    B b;
    //b.a = 200;  // 私有继承，不可在类的外部使用

}


int main()
{
    test1();


    return 0;
}