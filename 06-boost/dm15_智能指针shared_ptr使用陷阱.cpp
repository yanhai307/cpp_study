//
// Created by yanhai on 2019/12/8.
//

#include <iostream>
#include <boost/shared_ptr.hpp>

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

class C;

class B {
public:
    B()
    {
        cout << "B构造函数! " << endl;
    }

    ~B()
    {
        cout << "B析构函数! " << endl;
    }

    boost::shared_ptr<C> m_pc;
};

class C {
public:
    C()
    {
        cout << "C构造函数! " << endl;
    }

    ~C()
    {
        cout << "C析构函数! " << endl;
    }

    boost::shared_ptr<B> m_pb;
};

/**
 * 陷阱1：不要把栈内存地址赋给scoped_ptr scoped_array shared_ptr
 */
void test1()
{
    cout << "=======test1============" << endl;
    int a = 100;
    boost::shared_ptr<int> p(&a);
    cout << p.use_count() << endl;
}

/**
 * 陷阱2：shared_ptr不能多次引用同一原始指针，否则同一内存会被delete多次
 */
void test2()
{
    cout << "=======test2============" << endl;
    A *pA = new A;
    boost::shared_ptr<A> p1(pA);
    cout << p1.use_count() << endl;

    boost::shared_ptr<A> p2(pA);
    cout << p2.use_count() << endl;
}

/**
 * 陷阱3：shared_ptr循环引用导致内存泄漏
 */
void test3()
{
    cout << "=======test3============" << endl;
    boost::shared_ptr<B> pB(new B);
    boost::shared_ptr<C> pC(new C);
    cout << pB.use_count() << " , " << pC.use_count() << endl;

    pB->m_pc = pC; // 此刻，pC指向的内存引用计数为2
    pC->m_pb = pB; // 此刻，pB指向的内存应用计数为2
    cout << pB.use_count() << " , " << pC.use_count() << endl;
    // 此刻，pB pC都析构时，都只会引用计数-1,各自剩余引用计数为1，
    // 则不会释放，从而导致内存泄漏
}

/**
 * 陷阱4：shared_ptr管理的内存必须是new出来的
 */
void test4()
{
    cout << "=======test4============" << endl;
    A *pA = (A *) malloc(sizeof(A));
    boost::shared_ptr<A> p(pA);
}

int main()
{
//    test1();
//    test2();
    test3();
    test4();
    return 0;
}
