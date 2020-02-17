//
// Created by YANHAI on 2020/2/13.
//

/**
 * 容器共性机制研究：
 *
 *   1.容器中缓存了 用户的节点
 *   2.节点的类，要保证节点能够插入到容器中，一般节点类，需要提供
 *      无参构造函数
 *      拷贝构造函数
 *      重载=操作符
 *
 *  理论提高：所有容器提供的都是值(value)语意， 而非引用（reference）语意。容器执行插入元素的操作时，内部实施拷贝动作。
 *           所以STL容器存储的元素必须能够被拷贝（必须提供拷贝构造函数以及重载=操作符）
 *      - 除了queue与stack外，每个容器都提供可返回迭代器的函数，运用返回的迭代器就可以访问元素。
 *      - 通常STL不会丢出异常。要求使用者确保传入正确的参数。
 *      - 每个容器都提供一个默认构造函数跟一个默认拷贝构造函数。
 *      - 如已有容器 vecIntA; vector<int> vecIntB(vecIntA);  // 调用拷贝构造函数，复制vecIntA到vecIntB中。
 *      - 与大小相关的操作（c代表容器）
 *          c.size()   //返回容器中元素的个数
 *          c.empty()   // 判断容器是否为空
 *      - 比较操作（c1 c2代表容器）
 *          c1 == c2    // 判断c1是否等于c2
 *          c1 != c2    // 判断c1是否不等于c2
 *          c1 = c2     // 把c2的所有元素指派给c1
 */

/**
 * 各个容器的使用时机
 *                 vector     deque       list     set      multiset     map          multimap
 *  典型内存结构   单端数组   双端数组   双向链表    二叉树     二叉树     二叉树         二叉树
 *  可随机存取       是         是         否        否        否       对key而言是       否
 *  元素搜索速度     慢         慢        非常慢     快        快       对key而言快    对key而言快
 *  快速安插移除     尾端     头尾两端   任何位置     -         -           -               -
 *
 *  - deque的使用场景：比如排队购票系统，对排队者的存储可以采用deque，支持头端的快速移除，尾端的快速添加。如果采用vector，则头端移除时，会移动大量的数据，速度慢。
 *  - vector与deque的比较：
 *  	 1.vector.at()比deque.at()效率高，比如vector.at(0)是固定的，deque的开始位置却是不固定的。
 *    2.如果有大量释放操作的话，vector花的时间更少，这跟二者的内部实现有关。
 *    3.deque支持头部的快速插入与快速移除，这是deque的优点。
 *  - list的使用场景：比如公交车乘客的存储，随时可能有乘客下车，支持频繁的不确实位置元素的移除插入。
 *  - set的使用场景：比如对手机游戏的个人得分记录的存储，存储要求从高分到低分的顺序排列。
 *  - map的使用场景：比如按ID号存储十万个用户，想要快速要通过ID查找对应的用户。二叉树的查找效率，这时就体现出来了。如果是vector容器，最坏的情况下可能要遍历完整个容器才能找到该用户。
 */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// ================== 容器 值语意  ↓↓↓ =====================

class Teacher {
public:
    Teacher(const char *name, int age)
    {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
        m_age = age;
    }

    ~Teacher()
    {
        printf("delete [] %p\n", m_name);
        delete[] m_name;
    }

    Teacher(const Teacher &obj)
    {
        m_name = new char[strlen(obj.m_name) + 1];
        strcpy(m_name, obj.m_name);
        m_age = obj.m_age;
    }

    Teacher &operator=(const Teacher &obj)
    {
        delete[] m_name;
        m_name = new char[strlen(obj.m_name) + 1];
        strcpy(m_name, obj.m_name);
        m_age = obj.m_age;
        return *this;
    }

    void print()
    {
        cout << m_name << "\t" << m_age << endl;
    }

private:
    char *m_name;
    int m_age;
};


void test1()
{
    Teacher t1("t1", 31);
    t1.print();
    vector<Teacher> v1;
    v1.push_back(t1);   // 把t1拷贝了一份 存入到容器中了
}

int main()
{
    test1();
    return 0;
}
