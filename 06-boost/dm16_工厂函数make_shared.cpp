//
// Created by yanhai on 2019/12/8.
//

/**
 * 如何消除new
 * shared_ptr消除了显式的delete调用,很大程度上避免了程序员忘记delete而导致的内存泄漏。
 * 但是shared_ptr的构造依然需要使用new，这导致了代码中的某种不对称性，
 * 它应该使用工厂模式来解决。
 */

/**
 * 工厂函数
 *   boost库提供了一个自由工厂函数make_shared<T>() 来消除显示的new调用
 *
 *   template<class T, class... Args>
 *   shared_ptr<T> make_shared(Args && ... args);
 *
 *   make_shared()函数模板使用变长参数模板，最多可以接受10个参数,
 *   然后把它们传递给T的构造函数，创建一个shared_ptr<T> 的对象并返回。
 *   make_shared()函数要比直接创建shared_ptr对象的方式更高效，
 *   因为它内部仅分配一次内存，
 *
 *   头文件 <boost/make_shared.hpp>
 */
#include <iostream>
#include <boost/make_shared.hpp>

using namespace std;

class A {
public:
    A(int a, float b, char c, string d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        cout << "A构造函数" << endl;
    }

    ~A()
    {
        cout << "A析构函数" << endl;
    }

    int a;
    float b;
    char c;
    string d;
};

int main()
{
    // 原始的方式构造 shared_ptr， 需要new 产生一种不对称性
    boost::shared_ptr<A> p1(new A(100, 1.23f, 'c', "hello"));
    cout << p1->a << ", " << p1->b << ", " << p1->c << ", " << p1->d << endl;

    // 推荐使用工厂函数, 屏蔽new
    boost::shared_ptr<A> p2 = boost::make_shared<A>(200, 2.34f, 'd', "c++");
    cout << p2->a << ", " << p2->b << ", " << p2->c << ", " << p2->d << endl;
    return 0;
}
