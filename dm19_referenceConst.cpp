//
// Created by YANHAI on 2019/4/27.
//

// 常引用

#include <iostream>
using namespace std;


struct Teacher
{
    char name[64];
    int age;
};

// 常引用 让实参变量 拥有只读属性
// void printTeacher(const Teacher * const t)
void printTeacher(const Teacher &t)
{
//    t.age = 20;
    cout << "age: " << t.age << endl;
}

int main()
{
    // 普通引用
    int a = 10;
    int &b = a;
    cout << "b: " << b << endl;

    // 常引用
    int x = 20;
    const int &y = x;// 常引用时让变量 拥有只读属性 不能通过y去修改x了
//    y = 21;
    // 常引用 初始化 分为2种情况
    // 1.用变量 初始化 常引用
    {
        int x1 = 30;
        const int &y1 = x1;  // 用x1变量去初始化 常引用
    }
    // 2. 用字面量 初始化 常量引用
    {
        const int x2 = 10;   //C++编译器把x2放在符号表中了
//        int &m = 41;    // 普通引用 引用一个字面量 请问字面量有没有内存地址 ？ 没有
        // 引用 就是给内存去多个别名，字面量没有内存地址，所以报错
        const int &m = 43;  // c++编译器会为m分配内存空间
    }

    //
    Teacher t1;
    t1.age = 10;
    printTeacher(t1);

    return 0;
}

/*
 * const引用结论
 *  1. const Type & e 相当于 const Type * const e
 *  2. 普通引用 相当于 Type * const e
 *  3. 当使用常量（字面量） 对const引用进行初始化时，C++编译器会为常量值分配空间，
 *     并将引用名作为这段空间的别名
 *  4. 使用字面量对const引用初始化后，将生成一个只读变量
 */