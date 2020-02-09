//
// Created by yanhai on 2019/10/22.
//

/**
 * 设计一个数组类（MyVector），完成对int、char、Teacher类型元素的管理。
 *
 * 设计：
 *      类模板： 构造函数、拷贝构造函数、<< [] = 运算符重载
 */

/**
 * 结论1：
 *  如果把Teacher放入到MyVector数组中，并且Teacher类的属性含有指针，
 *  就会出现深拷贝和浅拷贝的问题；
 * 结论2：
 *  需要Teacher封装的函数有
 *    1.重写拷贝构造函数
 *    2.重载等号操作符
 *    3.重载左移操作符
 */

/**
 * 理论提高：
 *  所有容器提供的都是值语义，而非引用语义。容器执行插入元素的操作时，
 *  内部实施拷贝动作。所以STL容器内部存储的元素必须能够被拷贝（必须提供拷贝构造函数）
 */

#include <iostream>
#include "myvector.hpp"

using namespace std;

void test1()
{
    MyVector<int> myv1(10);

    for (int i = 0; i < myv1.len(); ++i) {
        myv1[i] = i + 1;
        cout << myv1[i] << " ";
    }
    cout << endl;

    auto myv2 = myv1;
    cout << myv2 << endl;
}

void test2()
{
    MyVector<char> myv1(5);
    for (auto &c: myv1)
    {

    }
}

int main()
{
    test1();
    test2();

    return 0;
}
