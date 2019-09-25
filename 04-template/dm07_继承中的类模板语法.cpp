//
// Created by yanhai on 2019/9/23.
//

/**
 * 继承中的类模板语法
 *   从模板类派生普通类
 *   从模板类派生模板类
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

protected:
    T a;
};

// 继承编译报错
//class B: public A
//{
//public:
//};

/**
 * 从模板类派生普通类：
 *   模板类派生时，需要具体化模板类，C++编译器需要知道 父类的数据类型具体是什么样子的
 *   要知道父类所占的内存大小是多少，只有数据类型固定下来，才知道如何分配内存
 */
class B : public A<int> {
public:
    // 父类实现了构造函数，必要要使用
    B(int a = 10, int b = 20) : A<int>(a)
    {
        this->b = b;
    }

    void printB()
    {
        cout << "a: " << a << ", b: " << b << endl;
    }

private:
    int b;
};

void test1()
{
    B b1(1, 2);
    b1.printB();
    b1.print();
}

/**
 * 从模板类派生模板类
 *
 */
template<typename T>
class C : public A<T> {
public:
    C(T a, T c) : A<T>(a)
    {
        this->c = c;
    }

    void printC()
    {
        // 为什么不能使用a?
//        cout << "a: " << a << ", c: " << c << endl;
        cout << "c: " << c << endl;

        // 要想用a，可以用下面2中方式
        cout << "a: " << this->a << endl;
        cout << "a: " << A<T>::a << endl;
    }

private:
    T c;
};

void test2()
{
    C<int> c1(1, 2);

    c1.print();
    c1.printC();
}

int main()
{
    test1();
    test2();
    return 0;
}
