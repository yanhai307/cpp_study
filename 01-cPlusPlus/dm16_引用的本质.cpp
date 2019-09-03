//
// Created by YANHAI on 2019/4/24.
//

#include <iostream>

using namespace std;

// 1. 引用很像一个常量
int main01()
{
    const int c1 = 10;

    int a = 10;
    int &b = a;

    // a和b就是同一块内存空间的门牌号
    cout << "a: " << &a << endl;
    cout << "b: " << &b << endl;
    return 0;
}

/*
 * 普通引用有自己的空间吗？
 *  有，并且和指针所占的空间大小是一样的
 */

// 2.引用很像一个指针
struct Teacher {
    char name[64];  // 64
    int age;        // 4/8

    // 很像指针 所占的空间大小
    int &a;         // 4/8
    char &b;        // 4/8
};

int main02()
{
    // 32位系统，打印72
    // 64位系统，打印88
    cout << "struct Teacher size: " << sizeof(Teacher) << endl;
    return 0;
}

// 3

void modify01(int &x)
{
    x = 100;
}

void modify02(int *const x)
{
    *x = 200;
}

int main03()
{
    int a = 10;

    modify01(a);
    cout << "a: " << a << endl;

    modify02(&a);   // 如果是指针，需要我们手工的取实参的地址
    cout << "a: " << a << endl;

    return 0;
}

// 4 间接赋值
void modify(int *p)
{
    *p = 200;   // 3. *p形参去间接修改实参的值
}

int main04()
{
    int a = 10;
    int *p = NULL; //间接赋值成立的三个条件 1.定义两个变量

    p = &a;    // 2.建立关联
    *p = 100;  // 3. *p间接修改a的值

    modify(&a);    // 2.建立关联

    return 0;
}
// 123写在一个函数中
// 12在一个函数 3在一个函数
// 1在一个函数  23在一个函数 （场景：C++引用，）

int main()
{
    main01();
    main02();
    main03();
    return 0;
}

/* 引用的本质
 *  1. 引用在C++中的内部实现是一个常量指针
 *      Type &name <--> Type * const name
 *  2. C++编译器在编译过程中使用指针作为引用的内部实现，因此引用所占用的空间大小与指针相同
 *  3. 从使用的角度，引用会让人误会其只是一个别名，没有自己的存储空间，这是C++为了实用性而做出的细节隐藏。
 *      void func(int &a)
 *      {
 *          a = 5;
 *      }
 *      void func(int *const a)
 *      {
 *          *a = 5;
 *      }
 *  4. 请仔细对比间接赋值成立的三个条件
 *    1) 定义两个变量（一个实参，一个形参）
 *    2) 建立关联，实参取地址传给形参
 *    3) *p形参去间接修改实参的值
 */

/*
 * 引用结论：
 *  1.引用在实现上，只不过是把：间接赋值成立的三个条件的后两步合二为一
 *    当实参传给形参引用的时候，只不过是C++编译器帮我们手工取了一个实参地址，
 *    传给了形参引用（常量指针）
 *  2.当我们使用引用语法的时候，我们不去关心编译器引用是怎么做的
 *      比如
 *          int a = 10;
 *          int b = &a;
 *          b = 20;
 *    当我们分析奇怪的语法现象的时候，我们才去思考C++编译器是怎么做的
 *      比如：求Teacher的占内存大小
 *          struct Teacher
 *          {
 *              char name[64];  // 64
 *              int age;        // 4/8
 *
 *              // 很像指针 所占的空间大小
 *              int &a;         // 4/8
 *              char &b;        // 4/8
 *          };
 */
