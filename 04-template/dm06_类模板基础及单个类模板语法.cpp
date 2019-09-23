//
// Created by yanhai on 2019/9/23.
//

/**
 * 类模板
 *   类模板与函数模板的定义和使用类似，有时，有两个或多个类，其功能是相同的，
 *   仅仅是数据类型不同，就可以使用类模板。
 *
 *  1.类模板用于实现类所需数据的类型参数化
 *  2.类模板在表示如数组、表、图等数据结构显得特别重要，
 *    这些数据结构的表示和算法不受所包含的元素类型的影响
 *
 *  类模板分为 单个类模板语法 和 继承中的类模板语法
 *
 *  本节介绍单个类模板语法
 */

#include <iostream>

using std::cout;
using std::endl;

// 模板类
template<typename T>
class A {
public:
    A(T a = 0)
    {
        this->a = a;
    }

    void print()
    {
        cout << "a: " << a << endl;
    }

private:
    T a;
};

/**
 * 模板的定义及初始化
 *  模板类中如果使用了构造函数，则遵循以前类的构造函数的调用规则
 */
void test1()
{
    // A a; // 错误，模板类是抽象的，需要进行类型具体

    A<int> a1;
    a1.print();

    A<char> a2('b');
    a2.print();

    A<int> a3, a4(20);
    a3.print();
    a4.print();
}

void useA(A<int> &a)
{
    a.print();
}

/**
 * 类模板做函数参数
 */
void test2()
{
    A<int> a1, a2(200);

    useA(a1);
    useA(a2);
}

int main()
{
    test1();
    test2();
    return 0;
}
