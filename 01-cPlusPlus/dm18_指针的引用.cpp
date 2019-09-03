//
// Created by YANHAI on 2019/4/27.
//

#include <iostream>

using namespace std;

struct Teacher {
    char name[64];
    int age;
};

// 在被调用函数 获取资源
int getTeacher(Teacher **p)
{
    Teacher *tmp = NULL;
    if (p == NULL) {
        return -1;
    }
    tmp = (Teacher *) malloc(sizeof(Teacher));
    if (tmp == NULL) {
        return -2;
    }
    tmp->age = 10;
    // p是实参的地址，*实参的地址 去间接的修改实参的值
    *p = tmp;
    return 0;
}

int getTeacher2(Teacher *&myp)
{
    myp = (Teacher *) malloc(sizeof(Teacher));
    if (myp == NULL)
        return -1;
    myp->age = 20;
    return 0;
}

void freeTeacher(Teacher *p)
{
    if (p != NULL)
        free(p);
}

int main()
{
    Teacher *pT1 = NULL;

    // 1. C语言中的二级指针
    getTeacher(&pT1);
    cout << "age: " << pT1->age << endl;
    freeTeacher(pT1);

    // 2.C++中的引用（指针的引用）
    getTeacher2(pT1);
    cout << "age: " << pT1->age << endl;
    freeTeacher(pT1);

    return 0;
}