//
// Created by yanhai on 2019/10/22.
//

/**
 * 类模板中的static关键字，
 * 定义了一个模板类AA，AA<int>和AA<char>中的m_a是同一个变量吗？
 */

#include <iostream>

using namespace std;

template <typename T>
class AA {
public:
    static T m_a;
    T m_b;
};

template <typename T>
T AA<T>::m_a = 0;

int main()
{
    AA<int> a1, a2, a3;
    a1.m_a = 10;
    a2.m_a++;
    a3.m_a++;
    cout << AA<int>::m_a << endl;

    AA<char> b1, b2, b3;
    b1.m_a = 'a';
    b2.m_a++;
    b3.m_a++;
    cout << AA<char>::m_a << endl;

    // AA<int> AA<char> 是两个不同的类，故每个类中的成员m_a不是同一个。

    return 0;
}
