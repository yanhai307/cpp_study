//
// Created by yanhai on 2020/2/7.
//

/**
 * list是一个双向链表容器，可高效地进行插入删除元素
 * list不可以随机存取元素，所以不支持at.(pos)函数和[]操作符
 * #include<list>
 */

#include <iostream>
#include <cassert>
#include <list>

using namespace std;

void test1()
{
    list<int> l;

    // 初始状态下 list容器为空，大小为0
    assert(l.size() == 0);
    assert(l.empty());

    for (int i=0; i < 10; i++) {
        l.push_back(i); // 尾部插入元素   尾插法
    }
    assert(l.size() == 10);

    // list<int>::iterator it;
    auto it = l.begin();
    while (it != l.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    it = l.begin();
    ++it;
    ++it;
    l.insert(it, 100);  // 在给定的迭代器位置之前插入元素
    for (auto &item: l) {
        cout << item << " ";
    }
    cout << endl;

    // 结论1 链表的节点index是从0号位置开始的
    // 结论2 在3号位置插入元素，是将新数据放在3号位置，让原来的3号位置变为4号位置，原来的4号位置变为5号位置
}

/**
 * list的删除
 *  - list.clear();  移除容器的所有数据
 *  - list.erase(beg, end); 删除[beg, end)区间的数据，返回下一个数据的位置
 *  - list.erase(pos);  删除pos位置的数据，返回下一个数据的位置
 *  - list.remove(elem);    删除容器中所有与elem值匹配的元素
 */
void test2()
{
    list<int> l;
    for (int i=0; i < 10; i++) {
        l.push_back(i);
    }
    assert(l.size() == 10);

    // 1. erase
    auto it = l.begin();    //it指向0
    ++it;   // it指向1
    ++it;   // it指向2
    ++it;   // it指向3
    l.erase(l.begin(), it); // 删除 0 1 2
    assert(l.size() == 7 && l.front() == 3);

    // 2. remove
    l.insert(l.begin(), 100);
    l.push_back(100);
    l.insert(it, 100);
    // 100 100 3 4 5 6 7 8 9 100
    l.remove(100);  // 删除容器中所有的100
    assert(l.size() == 7 && l.front() == 3);
}

int main()
{
    test1();
    test2();
    return 0;
}
