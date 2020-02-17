//
// Created by yanhai on 2020/2/15.
//

/**
 * 常用的查找算法
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

template<typename T>
void print(T &t)
{
    for (auto &item: t) {
        cout << item << " ";
    }
    cout << endl;
}

/**
 * adjacent_find()
 *  在iterator对 标识元素范围内，查找一对相邻重复元素，找到则返回指向这对元素的第一个元素的迭代器，否则返回 past-eth-end.
 */
void test1()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(5);
    v1.push_back(7);

    vector<int>::iterator it = adjacent_find(v1.begin(), v1.end());
    if (it == v1.end()) {
        cout << "没有找到重复的元素" << endl;
    } else {
        cout << "第一个重复的元素是：" << *it << "，迭代器的位置: " << distance(v1.begin(), it) << endl;
    }
}

/**
 * binary_search()
 *  在有序序列中查找 value, 找到则返回true。
 *  注意：在无序序列中，不可使用。
 */
void test2()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(5);
    v1.push_back(7);

    bool b = binary_search(v1.begin(), v1.end(), 5);
    if (b) {
        cout << "找到了" << endl;
    } else {
        cout << "没找到" << endl;
    }
}

bool GreatTree(int iNum)
{
    return iNum > 3;
}

/**
 * count()
 *  利用等于操作符，把标志范围内的元素与输入值比较，返回相等的个数。
 * count_if()
 *   利用谓词 统计符合条件的元素个数，count是count_if的一个特例
 */
void test3()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(5);
    v1.push_back(7);

    int num = count(v1.begin(), v1.end(), 5);
    cout << "5的个数是: " << num << endl;

    int num2 = count_if(v1.begin(), v1.end(), GreatTree);
    cout << "大于3的个数是: " << num2 << endl;
}

/**
 * find()
 *   - find: 利用底层元素的等于操作符，对指定范围内的元素与输入值进行比较，当匹配时，结束搜索，返回该元素的迭代器。
 *   - equal_range: 返回一对 iterator, 第一个表示 lower_bound, 第二个表示upper_bound.
 * find_if()
 *   使用输入的函数代替等于操作符执行find。返回被找到的元素的迭代器
 */
void test4()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(5);
    v1.push_back(7);

    vector<int>::iterator it = find(v1.begin(), v1.end(), 5);
    cout << "等于5 *it = " << *it << endl;

    vector<int>::iterator it2 = find_if(v1.begin(), v1.end(), GreatTree);
    cout << "大与3 *it2 = " << *it2 << endl;
}

int main()
{
    test1();    // adjacent_find
    test2();    // binary_search
    test3();    // count count_if
    test4();    // find find_if
    return 0;
}
