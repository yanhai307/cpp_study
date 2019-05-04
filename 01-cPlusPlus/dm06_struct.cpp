//
// Created by YANHAI on 2019/4/21.
//

// struct 类型的加强
// C语言中的struct定义了一组变量的集合，C编译器并不认为这是一种新的类型
// C++中的struct是一个新类型的定义声明

// 下面这个C语言的例子
// 在定义t1时，必须写为 struct Teacher t1 而不能是Teacher t1
/*
#include <stdio.h>

struct Teacher{
    char name[32];
    int age;
};

int main()
{
    // 这里必须加struct关键字
    struct Teacher t1;
    t1.age = 10;
    printf("hello...\n");
    return 0;
}
*/


// 在C++里面

#include <iostream>

using namespace std;

// 并且，struct关键字和class关键字完成的功能是一样的
// 区别后面介绍
struct Teacher{
    char name[32];
    int age;
};

// 在struct里面，也可以增加 public protected private进行修饰
struct T{
public:
    char name[32];
protected:
    int age;
};

int main()
{
    // Teacher是一个变量类型
    Teacher t1;
    t1.age = 10;
    printf("hello...\n");
    return 0;
}
