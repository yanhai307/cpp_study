//
// Created by yanhai on 2020/2/7.
//

/**
 * map/multimap
 *  - map是标准的关联式容器，一个map是一个键值对序列，即 key-value对。它提供基于key的快速检索能力、
 *  - map中key值是唯一的。集合中的元素按一定的顺序排序。元素插入过程是按顺序规则插入，所以不能指定插入位置。
 *  - map的具体实现采用红黑树变体的平衡二叉树的数据结构。在插入操作和删除操作上比vector快。
 *  - map可以直接存取key所对应的value，支持[]操作符，如 map[key]=value.
 *  - multimap与map的区别：map支持唯一键值，每个键智能出现一次，而multimap中相同键可以出现多次。multimap不支持[]操作符。
 *  - #include <map>
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
 * map元素的添加/遍历/删除基本操作
 */
void test1()
{
    map<int, string> map1;

    // 方法1
    map1.insert(pair<int, string>(1, "teacher01"));

    // 方法2
    map1.insert(make_pair(2, "teacher02"));

    // 方法3
    map1.insert(map<int, string>::value_type(3, "teacher03"));

    // 方法4
    map1[4] = "teacher04";

    // 容器的遍历
    for (map<int, string>::iterator it = map1.begin(); it != map1.end(); ++it) {
        cout << it->first << "\t" << it->second << endl;
    }

    // 删除
    while (!map1.empty()) {
        map<int, string>::iterator it = map1.begin();
        cout << it->first << "\t" << it->second << endl;
        map1.erase(it);
    }
}

/**
 * 插入的四种方法 比较
 * 前三种方法返回的都是pair, 若key已经存在，则报错，返回false
 * 方法四                  如key已经存在，则覆盖之前的值
 */
void test2()
{
    map<int, string> map1;

    // 方法1
    pair<map<int, string>::iterator, bool> mypair1 = map1.insert(pair<int, string>(1, "teacher01"));

    // 方法2
    pair<map<int, string>::iterator, bool> mypair2 = map1.insert(make_pair(2, "teacher02"));

    // 方法3
    pair<map<int, string>::iterator, bool> mypair3 = map1.insert(map<int, string>::value_type(3, "teacher03"));
    if (!mypair3.second) {
        cout << "key 3 插入失败" << endl;
    } else {
        cout << mypair3.first->first << "\t" << mypair3.first->second << endl;
    }

    pair<map<int, string>::iterator, bool> mypair4 = map1.insert(map<int, string>::value_type(3, "teacher03"));
    if (!mypair4.second) {
        cout << "key 3 插入失败" << endl;
    } else {
        cout << mypair4.first->first << "\t" << mypair4.first->second << endl;
    }

    // 方法4
    map1[4] = "teacher04";
    map1[4] = "teacher44";

    // 容器的遍历
    for (map<int, string>::iterator it = map1.begin(); it != map1.end(); ++it) {
        cout << it->first << "\t" << it->second << endl;
    }
}

/**
 * map查找
 *  - map.find(key);  查找键key是否存在，若存在，返回该键的元素的迭代器；若不存在，返回map.end();
 *  - map.count(key);    返回容器中key为 keyElem的对组个数，对map来说，要么是0，要么是1.对multimap来说，值可能大于1.
 */
void test3()
{
    map<int, string> map1;

    // 方法1
    map1.insert(pair<int, string>(1, "teacher01"));

    // 方法2
    map1.insert(make_pair(2, "teacher02"));

    // 方法3
    map1.insert(map<int, string>::value_type(3, "teacher03"));

    // 方法4
    map1[4] = "teacher04";

    // 容器的遍历
    for (map<int, string>::iterator it = map1.begin(); it != map1.end(); ++it) {
        cout << it->first << "\t" << it->second << endl;
    }

    // map的查找
    map<int, string>::iterator it2 = map1.find(100);
    if (it2 == map1.end()) {
        cout << "key 100 不存在" << endl;
    } else {
        cout << it2->first << "\t" << it2->second << endl;
    }

    // equal_range
    pair<map<int, string>::iterator, map<int, string>::iterator> mypair = map1.equal_range(4);
    // 第1个迭代器是 >= 4的位置
    // 第2个迭代器是 > 4的位置
    if (mypair.first == map1.end())
    {
        cout << "第一个迭代器 >=4 的位置不存在" << endl;
    } else {
        cout << mypair.first->first << "\t" << mypair.first->second << endl;
    }
    if (mypair.second == map1.end())
    {
        cout << "第二个迭代器 >4 的位置不存在" << endl;
    } else {
        cout << mypair.second->first << "\t" << mypair.second->second << endl;
    }
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}
