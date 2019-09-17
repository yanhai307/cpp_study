//
// Created by YANHAI on 2019/6/2.
//

/**
 * 友元函数
 *
 */

#include <iostream>

using namespace std;


class A {
    // 说明语句位置与访问描述无关，即和public private没有关系
    // 函数FriendFun 是类Test的好朋友
    friend void FriendFun(A *, int);

public:
    A(int a, int b)
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

int main()
{
    A t1(10, 20);
    t1.print();
    FriendFun(&t1, 30);
    t1.print();

    return 0;
}
