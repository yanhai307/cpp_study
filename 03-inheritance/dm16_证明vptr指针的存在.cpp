//
// Created by YANHAI on 2019/9/1.
//

#include <iostream>

using std::cout;
using std::endl;

class A {
public:
    void print()
    {
        cout << "A " << endl;
    }

private:
    int a;

};

class B {
public:
    virtual void print()
    {
        cout << "B " << endl;
    }

private:
    int b;

};

int main()
{
    cout << "sizeof(A)" << sizeof(A) << endl;   // 4
    cout << "sizeof(B)" << sizeof(B) << endl;   // 32位系统 8  多了一个vptr指针
    // 64位系统 16 int占用4字节，vptr占用8字节，考虑内存对齐，类的大小是最大成员变量的整数倍，所以为16
    return 0;
}