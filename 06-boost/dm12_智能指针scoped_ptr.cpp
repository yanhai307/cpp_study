//
// Created by yanhai on 2019/12/7.
//

/**
 * 智能指针 采用RAII机制（资源获取就是初始化），通过对象来管理指针，构造对象时，完成资源的初始化；
 *         析构对象时，对资源进行清理释放。C++98标准引入auto_ptr，但是设计的并不完善。
 */

#include <iostream>
#include <memory>
#include <boost/scoped_ptr.hpp>

using namespace std;
using namespace boost;

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

/**
 * auto_ptr的用法
 *  auto_ptr之间不能共享拥有权，但可以通过赋值或构造转移拥有权，一旦拥有权转移，
 *   不可以再次使用此auto_ptr。程序员必须防范一个原始指针被两个auto_ptr所拥有。
 */
void auto_ptr_test()
{
    cout << __FUNCTION__ << endl;
    auto_ptr<A> p1(new A(100));
    cout << p1->a << endl;

//    auto_ptr<A> p2(p1); // 此时p1已经为null
    auto_ptr<A> p2;
    p2 = p1; // 效果和p2(p1)一样

//    cout << p1->a << endl; // p1已经失去所有权，不能再使用
    cout << p1.get() << endl;
    cout << p2->a << endl;
}

/**
 * scoped_ptr与auto_ptr很类似，但最大的区别就是它不能转让管理权，也就是说
 * scoped_ptr禁止用户进行拷贝与赋值. (如何做到的呢？ 就是将拷贝构造函数和=运算符重载定义为私有的)
 * 头文件 <boost/scoped_ptr.hpp>
 */
void scoped_ptr_test()
{
    cout << __FUNCTION__ << endl;
    scoped_ptr<A> s1(new A(200));
    s1->a = 300;
    cout << s1->a << endl;

//    scoped_ptr<A> s2(s1);   // 报错: 拷贝构造函数是private
    scoped_ptr<A> s3;
//    s3 = s1;    // 报错：=运算符重载函数是private
}

int main()
{
    auto_ptr_test();
    scoped_ptr_test();
    return 0;
}
