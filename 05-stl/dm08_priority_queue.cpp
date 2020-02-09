//
// Created by yanhai on 2020/2/7.
//

/**
 * 优先级队列 priority_queue
 *  - 最大值优先级队列，最小值优先级队列
 *  - 优先级队列适配器 STL priority_queue
 */

#include <iostream>
#include <queue>

using namespace std;

// 初始化
void test1()
{
    priority_queue<int> pq1;    // 默认是最大值优先级
    priority_queue<int, vector<int>, less<int>> pq2;    // 效果等上， less是提前定义好的预定义函数 谓词
    priority_queue<int, vector<int>, greater<int>> pq3; // 最小值优先队列

    // 空容器
    assert(pq1.empty());
    assert(pq1.size() == 0);

    // 添加元素
    pq1.push(33);
    pq1.push(11);
    pq1.push(55);
    pq1.push(22);

    // pq1: 55 33 22 11
    assert(pq1.top() == 55);    // 头部元素是最大值 55
    assert(pq1.size() == 4);    // 队列大小为4

    pq1.pop();  // 弹出头部元素
    assert(pq1.top() == 33);
    assert(pq1.size() == 3);

    // 最小值优先级队列 测试
    pq3.push(33);
    pq3.push(11);
    pq3.push(55);
    pq3.push(22);

    // pq3: 11 22 33 55
    assert(pq3.top() == 11);
    pq3.pop();
    assert(pq3.top() == 22);
}

int main()
{
    test1();
    return 0;
}
