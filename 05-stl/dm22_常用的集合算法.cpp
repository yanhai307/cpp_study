//
// Created by yanhai on 2020/2/15.
//

/**
 * 常用的集合算法
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

template<typename T>
void print(T &t, const string &delimiter = " ")
{
    for (auto &item: t) {
        cout << item << delimiter;
    }
    cout << endl;
}

/**
 * set_union()
 *   构造一个有序序列，包含两个有序序列的并集。  A ∪ B
 * set_intersection()
 *   构造一个有序序列，包含两个有序序列的交集。  A ∩ B
 * set_difference()
 *   构造一个有序序列，该序列保留第一个有序序列中存在，而第二个有序序列中不存在的元素。 A - B
 */
void test1()
{
    vector<int> v1, v2, v3;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(6);

    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(6);
    print(v1);
    print(v2);

    v3.resize(v1.size()+v2.size());

    // v1 ∪ v2
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    print(v3);
    fill(v3.begin(), v3.end(), 0);  // reset

    // v1 ∩ v2
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    print(v3);
    fill(v3.begin(), v3.end(), 0);  // reset

    // v1 - v2
    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    print(v3);
    fill(v3.begin(), v3.end(), 0);  // reset

    // v2 - v1
    set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), v3.begin());
    print(v3);
}

int main()
{
    test1();
    return 0;
}
