//
// Created by YANHAI on 2019/4/24.
//

#include <iostream>
using namespace std;

struct Teacher
{
    char name[20];
    int age;
};

// pT和t1是两个不同的变量
// pT是形参，t1拷贝了一份给pT，相当于 pT = t1
void printT01(Teacher pT)
{
    cout << "printT01 age: " << pT.age << endl;
    pT.age = 20;    // 只会修改pT变量，不会修改t1的变量
}

// pT是t1的地址，通过地址可以修改t1的值
void printT02(Teacher *pT)
{
    cout << "printT02 age: " << pT->age << endl;
    pT->age = 30;
}

// pT是t1的别名，修改pT就是在修改t1
void printT03(Teacher &pT)
{
    cout << "printT03 age: " << pT.age << endl;
    pT.age = 40;
}

int main()
{
    Teacher t1;

    t1.age = 10;

    printT01(t1);
    cout << "main age: " << t1.age << endl;

    printT02(&t1);
    cout << "main age: " << t1.age << endl;

    printT03(t1);
    cout << "main age: " << t1.age << endl;

    return 0;
}

