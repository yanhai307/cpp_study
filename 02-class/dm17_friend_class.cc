//
// Created by yanhai on 19-6-2.
//

/*
 * 友元类
 *  若B类是A类的友元类，则B类的所有函数都是A类的友元函数
 *  友元类通常设计为一种对数据操作或类之间传递消息的辅助类
 */

#include <iostream>

using namespace std;


// 一般做辅助类
class A {
    // 说明语句位置与访问描述无关，即和public private没有关系
    // 函数FriendFun 是类Test的好朋友
    friend void FriendFun(A *, int);

    // 友元类
    friend class B;

public:
    A(int a=10, int b=20)
    {
        this->a = a;
        this->b = b;
    }

    void print()
    {
        cout << "a: " << a << ",b: " << b << endl;
    }

private:
    int a;
    int b;

};


void FriendFun(A *t, int x)
{
    // 友元函数通过对象参数访问私有数据成员
    t->a = x;
}

class B {
public:
    void set(int a)
    {
        Aobject.a = a;
    }
    void print()
    {
        Aobject.print();
    }
private:
    A Aobject;
};

int main()
{
    B b;
    b.print();
    b.set(300);
    b.print();

    return 0;
}

/**
 * 友元函数和友元类破坏了类的封装性
 *
 * 扩展：
 *   1.java --> 1.class（字节码） ==>反射机制分析1.class找到类对象 ，直接修改类的私有属性，反射机制 成为一种标准。
 *
 */