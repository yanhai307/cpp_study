//
// Created by YANHAI on 2019/5/26.
//

#include <iostream>

using namespace std;

// 1.
//  c语言中  malloc free  函数
//  c++      new    delete  操作符

// 2.
// new 基础类型变量 分配数组变量 分配类对象

// 基础类型
int fun1()
{
    // C 语言中
    int *p = (int *) malloc(sizeof(int));
    if (p) {
        *p = 10;
        free(p);
        p = NULL;
    }

    // c++中
    int *p2 = new int;
    *p2 = 20;
    delete p2;

    // 申请内存并初始化
    int *p3 = new int(30);
    printf("*p3 = %d\n", *p3);
    delete p3;

    return 0;
}

// 数组类型
int fun2()
{
    // c语言中
    int *p1 = (int *) malloc(sizeof(int) * 10);
    if (p1) {
        p1[0] = 1;
        free(p1);
    }

    // c++中
    int *p2 = new int[10];
    p2[1] = 2;
    delete[] p2; // 数组不要把 [] 忘记

    char *p3 = new char[25]; // == char buf[25]
    delete[] p3;

    return 0;
}

class Test {
public:
    Test(int a)
    {
        this->a = a;
        cout << "Test() a: " << a << endl;
    }

    ~Test()
    {
        cout << "~Test() a: " << a << endl;
    }

private:
    int a;
};

// 分配对象
// new 能执行类的构造函数，delete能执行类的析构函数
// malloc 和 free 只能申请和释放内存
int fun3()
{
    // c
    Test *pT1 = (Test *) malloc(sizeof(Test));
    if (pT1) {
        free(pT1);
    }

    // c++
    Test *p2 = new Test(10);
    delete p2;

    return 0;
}

int main()
{
    fun1();
    fun2();
    fun3();
    return 0;
}
