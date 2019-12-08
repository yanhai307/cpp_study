//
// Created by yanhai on 2019/12/8.
//

/**
 *  shared_ptr是可以共享所有权的指针。如果有多个shared_ptr共同管理同一个对象时，
 *  只有shared_ptr全部与对象分离之后，被管理的对象才会被释放
 *  头文件 <boost/shared_ptr.hpp>
 *
 *  注：c++11标准中std::shared_ptr 与 boost::shared_ptr功能相似
 *
 *  shared_ptr使用引用计数，每一个shared_ptr的拷贝都指向相同的内存，
 *  每关联一次，内部的引用计数加1。
 */

#include <iostream>
#include <boost/shared_ptr.hpp>

using namespace std;

class A {
public:
    A(int _a) : a(_a)
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
    boost::shared_ptr<A> p1(new A(100)); //初始引用计数为1
    p1->a = 200;
    // 此时唯一管理A的内存
    cout << p1.unique() << ", " << p1.use_count() << endl;

    boost::shared_ptr<A> p2(p1); // 引用计数+1
    cout << p2.unique() << ", " << p2.use_count() << endl;

    boost::shared_ptr<A> p3;
    p3 = p2;    // 引用计数+1
    cout << p3.unique() << ", " << p3.use_count() << endl;
    cout << p1.unique() << ", " << p1.use_count() << endl;

    // 指向同一个内存地址
    cout << p1.get() << ", " << p2.get() << ", " << p3.get() << endl;

    p1.reset();
    p2.reset();
    p3.reset(); // 全部释放管理权, A的内存将会释放

    cout << "结束!" << endl;
    return 0;
}
