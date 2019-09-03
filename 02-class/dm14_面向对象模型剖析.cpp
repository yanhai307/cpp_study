//
// Created by YANHAI on 2019/5/26.
//

/*
 * 1. C++类对象中的成员变量和成员函数时分开存储的
 *  成员变量：
 *    普通成员变量：存储于对象中，与struct变量有相同的内存布局和字节对其方式
 *    静态成员变量：存储于全局数据区中
 *  成员函数：
 *    存储于代码段中
 *  问题：
 *    很多对象共用一块代码？代码是如何区分具体对象的？
 *    换句话说：
 *    int getK() cosnt {return k;} 代码是如何区分，具体是obj1 obj2 obj3对象的k值呢？
 */

#include <iostream>

using namespace std;


/*
 * 2. C++编译器对普通成员函数的内部处理
 */

#if 0
class Test {
private:
    int mI;
public:
    Test(int i)
    {
        mI = i;
    }
    int getI()
    {
        return mI;
    }

    static void Print()
    {
        printf("This is class Test.\n");
    }
};

int main()
{
    Test a(10);
    a.getI();
    Test::Print();
    return 0;
}

#else

struct Test {
    int mI;
};

void Test_initialize(Test *pThis, int i)
{
    pThis->mI = i;
}

int Test_getI(Test *pThis)
{
    return pThis->mI;
}

void Test_Print()
{
    printf("This is class Test.\n");
}

int main()
{
    Test a;
    Test_initialize(&a, 10);
    Test_getI(&a);
    Test_Print();
    return 0;
}

#endif

/*
 * 总结：
 *  1、C++类对象中的成员变量和成员函数时分开存储的。
 *     C语言中的内存四区模型仍然有效！
 *  2. C++中类的普通成员函数都隐式包含一个指向当前对象的this指针
 *  3. 静态成员函数，成员变量属于类
 *     静态成员函数与普通成员函数的区别
 *      静态成员函数不包含指向具体对象的指针
 *      普通成员函数包含一个指向具体对象的指针
 */
