//
// Created by yanhai on 2020/1/12.
//

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void printDeque(deque<int> &d)
{
    for (deque<int>::iterator it  = d.begin(); it != d.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void test1()
{
    deque<int> d1;
    d1.push_back(1);
    d1.push_back(3);
    d1.push_back(5);

    d1.push_front(-11);
    d1.push_front(-33);
    d1.push_front(-55);

    cout << "头部元素: " << d1.front() << endl;
    cout << "尾部元素: " << d1.back() << endl;
    printDeque(d1);

    d1.pop_back();
    d1.pop_front();
    printDeque(d1);

    // 查找 -11 在数组下标的值
    deque<int >::iterator it = find(d1.begin(), d1.end(), -11);
    if (it != d1.end())
    {
        cout << "-11在数组下标是: " << distance(d1.begin(), it) << endl;
    }else {
        cout << "没有找到值为-11的元素" << endl;
    }

}

int main()
{
    test1();
    return 0;
}
