//
// Created by yanhai on 2020/2/7.
//

#include <iostream>
#include <set>

using namespace std;

void test1()
{
    multiset<int> s1;

    assert(s1.empty());
    s1.insert(3);
    s1.insert(2);
    s1.insert(4);
    s1.insert(3);
    s1.insert(9);
    s1.insert(2);
    assert(s1.size() == 6);

    // 遍历
    for (multiset<int>::iterator it = s1.begin(); it != s1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    test1();
    return 0;
}