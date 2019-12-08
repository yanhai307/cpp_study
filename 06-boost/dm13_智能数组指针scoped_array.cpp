//
// Created by yanhai on 2019/12/7.
//

/**
 * scoped_ptr管理new出来的对象，scoped_array与scoped_ptr很类似，
 * 它包装了new []操作符(而不是new)在堆上分配的动态数组，弥补了标准库中
 * 没有指向数组的智能指针的遗憾
 * 头文件 <boost/scoped_array.hpp>
 */

/**
 * scoped_array和scoped_ptr的区别
 *
 *                  scoped_array             scoped_ptr
 *  接受的指针            new[]                   new
 *  内部指针        不支持*、->操作符重载       普通指针、支持*、->
 *  析构函数实现       使用delete[]               使用delete
 *  支持索引访问  提供operator[]重载，可以像     不支持operator[]重载
 *               普通数组一样使用下标访问元素
 *  容器操作          无begin(),end()          无begin(),end()
 */

#include <iostream>
#include <boost/scoped_ptr.hpp>
#include <boost/scoped_array.hpp>

using namespace std;
using namespace boost;

class A {
public:
    A(int _a = 100) : a(_a)
    {
        cout << "A构造函数! " << endl;
    }

    ~A()
    {
        cout << "A析构函数! " << endl;
    }

    int a;
};

int main()
{
    // 注意：scoped_ptr不能接受数组指针
//    scoped_ptr<A> p1(new A[5]); // 运行时发生崩溃

    // 数组指针
    A *p2 = new A[5];
    for (int i = 0; i < 5; ++i) {
        p2[i].a = i;
    }
    cout << p2[3].a << endl;
    (p2 + 3)->a = 100;
    cout << p2[3].a << endl;
    delete[] p2;

    // 指向数组内存地址的智能指针
    scoped_array<A> p3(new A[5]);
    for (int i = 0; i < 5; ++i) {
        p3[i].a = i;    // 把p2当做数组名使用
    }
    cout << p3[3].a << endl;
//    (p3 + 3)->a = 100;    // 不支持

    return 0;
}
