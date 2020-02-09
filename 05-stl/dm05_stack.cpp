//
// Created by yanhai on 2020/1/12.
//

/**
 * 栈模型
 */

#include <iostream>
#include <stack>

using namespace std;

void test1()
{
    stack<int> s;
    for (int i = 0; i < 10; i++) {
        s.push(i + 1);    // 入栈
    }

    cout << "栈的大小: " << s.size() << endl;

    while (!s.empty()) {
        int tmp = s.top(); // 获取栈顶元素
        cout << tmp << " ";
        s.pop();    // 删除栈顶元素
    }
    cout << endl;
}

int main()
{
    test1();
    return 0;
}
