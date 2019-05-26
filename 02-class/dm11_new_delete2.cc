//
// Created by YANHAI on 2019/5/26.
//

#include <iostream>

using namespace std;

// 3. 用malloc申请的内存可以用delete释放吗
//    用new申请的内存可以用free释放吗


// 基础类型 -- 可以混用
int fun1()
{
    // malloc申请， delete释放
    int *p = (int *) malloc(sizeof(int));
    if (p) {
        *p = 10;
        delete p;
    }

    // new 申请，free释放
    int *p2 = new int;
    *p2 = 20;
    free(p2);

    // 申请内存并初始化
    int *p3 = new int(30);
    printf("*p3 = %d\n", *p3);
    free(p3);

    return 0;
}

// 数组类型
// 基础类型数组类型 --
int fun2()
{
    // malloc 申请，delete释放
    int *p1 = (int *) malloc(sizeof(int) * 10);
    if (p1) {
        p1[0] = 1;
        delete[] p1;
    }

    // new申请，free释放
    char *p3 = new char[25];
    free(p3);

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

// 分配对象 -- 程序不会崩溃
// 总结：
//    malloc 不会调用类的构造函数
//    free 不会调用类的析构函数
int fun3()
{
    // malloc 申请，delete释放
    Test *pT1 = (Test *) malloc(sizeof(Test));
    delete pT1;

    // new 申请，free释放
    Test *p2 = new Test(10);
    free(p2);

    return 0;
}

int main()
{
    fun1();
    fun2();
    fun3();
    return 0;
}
