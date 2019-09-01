
/*
 继承与组合混搭情况下，构造与析构调用原则
  原则：
    先构造父类，再构造成员变量、最后构造自己
    先析构自己。再析构成员变量、最后析构父类
    ///先构造的对象，后释放
*/

#include <iostream>

using std::cout;
using std::endl;

class Object {
public:
    Object(int a, int b)
    {
        this->a = a;
        this->b = b;
        cout << "object构造函数调用：" << "a: " << a << ",b: " << b << endl;
    }

    ~Object()
    {
        cout << "object析构函数" << "a: " << a << ",b: " << b << endl;
    }

protected:
    int a;
    int b;
};

class Parent : public Object {
public:
    Parent(const char *p) : Object(1, 2)
    {
        this->p = p;
        cout << "父类的构造函数: " << p << endl;
    }

    ~Parent()
    {
        cout << "父类的析构函数: " << p << endl;
    }

protected:
    const char *p;
};

class Child : public Parent {
public:
    Child(const char *p) : Parent(p), obj1(3, 4), obj2(5, 6)
    {
        this->myp = p;
        cout << "子类的构造函数" << endl;
    }

    ~Child()
    {
        cout << "子类的析构函数" << endl;
    }

protected:
    const char *myp;
    Object obj1;
    Object obj2;
};

void objPlay()
{
    Child c("c1");

}

int main()
{
    objPlay();

    return 0;
}
