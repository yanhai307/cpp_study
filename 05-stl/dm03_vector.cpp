//
// Created by yanhai on 2020/1/12.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * 初始化，插入元素, 遍历
 */
void test1()
{
    vector<int> v1;
    cout << "length: " << v1.size() << endl;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    cout << "length: " << v1.size() << endl;

    cout << "头部元素: " << v1.front() << endl;  // 获取头部元素

    // 函数返回值当左值，应该返回一个引用
    v1.front() = 11;
    v1.back() = 55;

    while (v1.size() > 0) {
        cout << "尾部元素: " << v1.back() << endl;  // 获取尾部元素
        v1.pop_back();  // 删除尾部元素，没有返回值

    }
}

/**
 * vector对象的带参数的初始化
 */
void test2()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    vector<int> v2 = v1;

    vector<int> v3(v1.begin(), v1.begin() + 2);

    vector<int> v4(3, 9);   // 初始化3个元素，初始值都是9
}

static void printVector(vector<int> &v)
{
    for (auto &item:v) {
        cout << item << " ";
    }
    cout << endl;
}

void test3()
{
    vector<int> v1(10);
    for (int i = 0; i < 10; i++) {
        v1[i] = i + 1;    // 使用[]时，必须确保这个位置已经分配了内存
    }
    printVector(v1);
}

void test4()
{
    vector<int> v1(10);    // 前10个都被初始化为0
    v1.push_back(100);  // 插入到第11个位置
    v1.push_back(200);
    printVector(v1);
    cout << "length: " << v1.size() << endl;    // 大小为12
}

/**
 * 使用迭代器遍历
 */
void test5()
{
    vector<int> v1(10);
    for (int i = 0; i < 10; i++) {
        v1[i] = i + 1;
    }

    // begin指向第1个元素，end指向最后一个元素的下一位
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
        cout << *it << " ";
    }
    // 逆向迭代器
    for (vector<int>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); ++rit) {
        cout << *rit << " ";
    }
    /**
     * iterator  const_iterator  reverse_iterator  const_reverse_iterator
     */
}

/**
 * 删除元素
 */
void test6()
{
    vector<int> v1(10);
    for (int i = 0; i < 10; i++) {
        v1[i] = i + 1;
    }

    // 区间删除
    v1.erase(v1.begin(), v1.begin() + 3);
    printVector(v1);

    // 指定位置删除
    v1.erase(v1.begin()); // 在头部删除一个元素

    // 根据元素的值
    v1[2] = 2;
    v1[5] = 2;
    printVector(v1);
    for (vector<int>::iterator it = v1.begin(); it != v1.end();) {
        if (*it == 2) {
            it = v1.erase(it);   // 当 删除迭代器所指向的元素的时候，erase返回删除元素的下一个位置
        } else {
            ++it;
        }
    }
    printVector(v1);

    // 插入数据
    v1.insert(v1.begin(), 100);
    v1.insert(v1.end(), 200);
    printVector(v1);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}
