//
// Created by yanhai on 2020/1/12.
//

#include <iostream>
#include <queue>

using namespace std;

void test1()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "队头元素: " << q.front() << endl;
    cout << "队列的大小: " << q.size() << endl;

    while (!q.empty()) {
        cout << "队头元素: " << q.front() << endl;
        q.pop();
    }
}

int main()
{
    test1();
    return 0;
}
