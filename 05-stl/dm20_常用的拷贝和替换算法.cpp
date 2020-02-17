//
// Created by yanhai on 2020/2/15.
//

/**
 * 常用的拷贝和替换算法
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
 * copy()
 *   把一个容器的指定范围内的所有元素拷贝到另外一个容器的指定位置。
 */
void test1()
{
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(6);
    print(v1);

    v2.resize(v1.size());
    copy(v1.begin(), v1.end(), v2.begin());
    print(v2);
}

/**
 * replace()
 *   将指定范围内的所有等于oldValue的元素替换成newValue
 * replace_if()
 *   将指定范围内所有操作结果为true的元素用新值替换。
 */
void test2()
{
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(3);
    v1.push_back(6);
    print(v1);

    replace(v1.begin(), v1.end(), 3, 10);
    print(v1);

    replace_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 5), 12);
    print(v1);
}

/**
 * swap()
 *   交换两个容器的元素
 */
void test3()
{

    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(6);

    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);

    print(v1);
    print(v2);
    swap(v1, v2);
    print(v1);
    print(v2);
}

int main()
{
    test1();    // copy
    test2();    // replace replace_if
    test3();    // swap
    return 0;
}
