//
// Created by YANHAI on 2019/5/25.
//

// 默认构造函数和默认拷贝构造函数
// 类没有提供构造函数，C++编译器会自动给你提供一个默认的构造函数
// 类没有提供拷贝构造函数，C++编译器会自动给我们提供一个默认的拷贝构造函数(浅拷贝)

#include <iostream>
#include <string.h>

using namespace std;

class Test {
public:
    void init(int a, int b)
    {
        m_a = a;
        m_b = b;
    }

    void print()
    {
        cout << "a: " << m_a << ", b: " << m_b << endl;
    }

private:
    int m_a;
    int m_b;
};

int main()
{
    // 构造函数的必要性
    Test t1;
    int a = 10;
    int b = 20;
    t1.init(a, b);

    // 显得很别扭，很臃肿
    Test t2[3];
    t2[0].init(a, b);
    t2[1].init(a, b);
    t2[2].init(a, b);

}