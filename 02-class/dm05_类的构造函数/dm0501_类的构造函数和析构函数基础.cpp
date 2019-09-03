//
// Created by YANHAI on 2019/5/12.
//

// 类的构造函数与析构函数基础

#include <iostream>
#include <string.h>

using namespace std;

class Test {
public:
    // 构造函数，初始化工作，成员变量初始化等
    Test(const char *name) : _name(name)
    {
        p = (char *) malloc(20);
        strcpy(p, "hello...");
        cout << _name << ": 我是构造函数。。被调用了。。" << endl;
    }

    void print()
    {
        cout << _name << ": " << p << endl;
    }

    // 析构函数，清理工作，释放内存等。
    ~Test()
    {
        if (p)
            free(p);
        p = nullptr;
        cout << _name << ": 我是析构函数。。被调用了。。" << endl;
    }

private:
    const char *_name;
    char *p;
};

int main()
{
    // 先创建的对象，后释放
    Test t1("t1"), t2("t2");
    t1.print();
    t2.print();
    return 0;
}
