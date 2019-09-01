
/*
  虚继承
    如果一个派生类从多个基类派生，而这些基类又有一个共同的基类，
    则在对该基类中声明的名字进行访问时，可能产生二义性。
*/

#include <iostream>

using std::cout;
using std::endl;

class B {
public:
    int b;
};

// 虚继承
class B1 : virtual public B {
public:
    int b1;
};

class B2 : public B {
public:
    int b2;
};


class C : public B1, public B2 {
public:
    int c;
};

void test()
{
    cout << "sizeof(B)" << sizeof(B) << endl;   // 4
    cout << "sizeof(B1)" << sizeof(B1) << endl; // 12   加了virtual关键字， 编译器加了其他属性？
    cout << "sizeof(B2)" << sizeof(B2) << endl; // 8
    cout << "sizeof(C)" << sizeof(C) << endl;   // 24
}

int main()
{
    test();
    return 0;
}