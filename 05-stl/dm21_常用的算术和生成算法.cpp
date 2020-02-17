//
// Created by yanhai on 2020/2/15.
//

/**
 * 常用的算术和生成算法
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
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
 * accumulate()
 *   对指定范围内的元素求和，然后结果再加上一个由val指定的初始值。
 *  #include <numeric>
 */
void test1()
{
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(6);
    print(v1);

    int num = accumulate(v1.begin(), v1.end(), 100);
    cout << "num: " << num << endl;
}

/**
 * fill()
 *   将输入值赋给标志范围内的所有元素
 */
void test2()
{
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(6);
    print(v1);

    fill(v1.begin(), v1.end(), 8);
    print(v1);
}

int main()
{
    test1();    // accumulate
    test2();    // fill
    return 0;
}
