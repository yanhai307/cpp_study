//
// Created by yanhai on 2019/12/8.
//

/**
 * 共享所有权的数组智能指针 shared_array
 *  shared_array类似shared_ptr 它包装了new[]操作符在堆上分配的动态数组，同样使用引用计数机制为
 *  动态数组提供了一个代理，可以在程序的生命周期里长期存在，直到没有任何引用后才释放内存
 *  头文件 <boost/shared_array.hpp>
 */

#include <iostream>
#include <boost/shared_array.hpp>

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
    A *pArr = new A[5];
//    boost::shared_ptr<A> p1(pArr);    // delete不能释放数组内存指针，应该使用delete[]

    boost::shared_array<A> p1(pArr);
    cout << p1.unique() << ", " << p1.use_count() << endl;

    boost::shared_array<A> p2(p1);
    cout << p2.unique() << ", " << p2.use_count() << endl;

    // 支持[]运算符
    for (int i = 0; i < 5; ++i) {
        p1[i].m_a = i;
    }

    cout << p2[3].m_a << endl;
    return 0;
}
