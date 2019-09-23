//
// Created by YANHAI on 2019/9/1.
//

/**
  继承中的构造与析构

  调用原则
   1. 子类对象在创建时会首先调用父类的构造函数
   2. 父类构造函数执行结束后，执行子类的构造函数
   3. 当父类的构造函数有参数时，需要在子类的初始化列表中显示调用
   4. 析构函数调用的先后顺序与构造函数相反
 */

#include <iostream>

using std::cout;
using std::endl;

/*
  结论：
   先调用父类的构造函数 再调用子类的构造函数
   析构函数的顺序 与构造函数相反
*/

class Parent {
public:
    Parent(int a, int b)
    {
        this->a = a;
        this->b = b;
        cout << "父类的构造函数" << endl;
    }

    ~Parent()
    {
        cout << "父类的析构函数" << endl;
    }

private:
    int a;
    int b;

};

class Child : public Parent {
public:
    Child(int a, int b, int c) : Parent(a, b)
    {
        this->c = c;
        cout << "子类的构造函数" << endl;
    }

    ~Child()
    {
        cout << "子类的析构函数" << endl;
    }

private:
    int c;
};

void objPlay()
{
    Child c(1, 2, 3);

}

int main()
{
    objPlay();

    return 0;
}
