//
// Created by yanhai on 2019/12/8.
//

/**
 * weak_ptr并不能作为一个单独指针来使用：不能->访问 *解引用，
 * 也不能检查是否为空，它仅仅作为shard_ptr的观察者
 *  一般用于：
 *   - 检测管理的内存是否释放
 *   - 解决循环引用问题
 */

#include <iostream>
#include <boost/weak_ptr.hpp>

using namespace std;

/**
 * 检测管理的内存是否释放
 *  在使用weak_ptr时，我们一般会先用expired()判断是否过期，
 *  如果没有过期则可访问所管理的资源，但weak_ptr并不能操作资源(无* ->操作)，
 *  当我们想要访问weak_ptr所指向的资源时。应使用lock()方法取一个
 *  shared_ptr，通过shared_ptr来访问资源。
 */
void test1()
{
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

    cout << "======test1====" << endl;
    boost::shared_ptr<A> p1(new A);
    p1->m_a = 100;
    boost::shared_ptr<A> p2(p1);
    cout << "p1: " << p1.use_count() << ", p2: " << p2.use_count() << endl;

    // 不影响引用计数，观察者
    boost::weak_ptr<A> w1(p1);
    cout << "w1: " << w1.expired() << ", " << w1.use_count() << endl;

    // 此刻，让p1释放管理权
    p1.reset();
    cout << "p1: " << p1.get() << ", " << p1.use_count() << endl;
//    p2.reset();

    // 通过w1来观察
    cout << "w1: " << w1.expired() << ", " << w1.use_count() << endl;
    if (w1.expired())   //
    {
        cout << "内存释放了" << endl;
    } else {
        boost::shared_ptr<A> p3 = w1.lock();
        cout << p3->m_a << endl;
    }
}

/**
 *
 */
void test2()
{
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

        boost::shared_ptr<A> m_pa;
//        boost::weak_ptr<A> m_pa;
    };

    cout << "======test2====" << endl;
    boost::shared_ptr<A> p1(new A);
    p1->m_pa = p1;  // 造成循环引用
    // 到这里时候，p1生命周期结束，产生析构，引用计数-1
    // 但是引用计数不为0，所以 new A这块内存不会被释放，
    // 所以m_pa成员也不会释放，这样就导致了引用计数一直不为0
    // 则 new A内存泄漏
    // 解决方法就是，将m_pa成员类型改为boost::weak_ptr
}

int main()
{
    test1();
    test2();
    return 0;
}
