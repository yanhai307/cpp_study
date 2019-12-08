//
// Created by yanhai on 2019/12/8.
//

/**
 * 如果禁止一个类的对象拷贝和赋值？
 *  A a1;
 *  A a2(a1); // 禁止
 *
 *  A a3;
 *  a3 = a1; // 禁止
 */

#include <iostream>
#include <boost/noncopyable.hpp>

using namespace std;

/**
 *  1.可以将拷贝构造函数和=重载函数设置为private就可以了
 */
void test1()
{
    class A {
    public:
        A()
        {
            cout << "A构造函数" << endl;
        }

        ~A()
        {
            cout << "A析构函数" << endl;
        }

    private:
        A(const A &a)
        {
            cout << "A拷贝构造函数" << endl;
        }

        A &operator=(const A &a)
        {
            cout << "A operator=" << endl;
            return *this;
        }
    };
    A a1;
//    A a2(a1);
//    A a3 = a1;
//    A a4;
//    a4 = a1;
}

/**
 * noncopyable
 *  当我们定义某个类时，我们可能不希望我们定义的类进行拷贝操作。
 *  因此，我们可以采用将拷贝构造和拷贝赋值声明为private，这样的话
 *  就能禁止类进行拷贝操作。
 *  但每次都这样做的话，显得很麻烦，所以boost中就提供noncopyable，
 *  我们通过继承noncopyable类就可以实现禁止拷贝了。
 *  头文件 <boost/noncopyable.hpp>
 *
 *  noncopyable的实现里，将构造函数和析构函数设置为protected，
 *  原因是设置public没有意义，因为我们不会单独去定义一个noncopyable对象，应为它没有任何意义。
 *  设置为private时，子类就没有办法构造了。
 */
void test2()
{
    class A : public boost::noncopyable {
    public:
        A()
        {
            cout << "A构造函数! " << endl;
        }

        ~A()
        {
            cout << "A析构函数! " << endl;
        }
    };

    A a1;
//    A a2(a1);
//    A a3 = a1;
//    A a4;
//    a4 = a1;
}

int main()
{
    test1();
    test2();
    return 0;
}
