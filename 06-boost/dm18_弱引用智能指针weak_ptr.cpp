//
// Created by yanhai on 2019/12/8.
//

/**
 * weak_ptr设计的目的是为了 来协助 shared_ptr工作，它只可以从一个shared_ptr或另一个weak_ptr
 * 对象构造，它的构造和析构 不会引起引用计数的增肌或减少。
 * 只能监控有几个shared_ptr，不能操作内部对象。
 * 头文件 <boost/weak_ptr.hpp>
 *
 * 注：C++11标准中std::weak_ptr与boost::weak_ptr功能相似
 */

/**
 *  weak_ptr和shared_ptr区别
 *                    weak_ptr                    shared_ptr
 *   构造        weak_ptr、shared_ptr构造       new、shared_ptr构造
 *  指针功能     不支持*、->操作符重载              支持*、->操作符重载
 * 引用计数改变  不影响对应的shared_ptr内部计数        改变引用计数
 * 成员函数     - use_count  返回引用计数         - use_count  返回引用计数
 *             - expired 检测所管理的对象是否释放  - unique返回是否是独占所有权
 *             - reset 将weak_ptr置空           - reset 放弃所有权并使计数-1
 *             - swap 交换两个shared_ptr对象     - swap 交换两个shared_ptr对象
 *             - lock 创建新的shared_ptr对象并   - get 返回内部对象(指针)
 *                    使计数+1
 */

#include <iostream>
#include <boost/weak_ptr.hpp>

using namespace std;

class A {
public:
    A()
    {
        cout << "A构造函数! " << endl;
    }

    ~A()
    {
        cout << "A析构函数! " << endl;
    }

    int m_a;
};


int main()
{
    boost::shared_ptr<A> p1(new A); // 引用计数+1
    cout << "p1: " << p1.unique() << ", " << p1.use_count() << endl;

    boost::weak_ptr<A> p2(p1);  // 引用计数不变，仅仅是旁观者
    cout << "p2: " << p2.expired() << ", " << p2.use_count() << endl;

    boost::shared_ptr<A> p3(p1); // 引用计数+1
    cout << "p3: " << p3.unique() << ", " << p3.use_count() << endl;

    boost::weak_ptr<A> p4(p2);
    cout << "p4: " << p4.expired() << ", " << p4.use_count() << endl;

    // expired表示内存是否已经释放
    p1.reset(); // 引用计数-1
    cout << "p2: " << p2.expired() << ", " << p2.use_count() << endl;
    p3.reset();
    cout << "p4: " << p4.expired() << ", " << p4.use_count() << endl;
    return 0;
}
