//
// Created by yanhai on 2020/2/15.
//

/**
 * STL的容器算法迭代器的设计理念
 *  1. STL的容器通过 类模板 技术，实现数据类型和容器模型的分离。
 *  2. STL的迭代器技术实现了遍历容器的统一方法；也为STL的算法提供了统一性奠定了基础。
 *  3. STL的算法，通过函数对象实现了自定义数据类型的算法运算。所以说 STL的算法也提供了统一性。
 *  核心思想：其实函数对象本质就是回调函数；回调函数的思想：就是任务的编写者和任务的调用者有效解耦，函数指针做函数参数。
 *
 */

#include <iostream>

int main()
{
    return 0;
}
