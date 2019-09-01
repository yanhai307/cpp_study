
/*
  重写 pk 重载，  （面试题2： 谈谈你对重写、重载理解）
  函数重载：
    1. 必须在同一个类中进行
    2. 子类无法重载父类的函数，父类同名函数将被名称覆盖
    3. 重载是在编译期间根据参数类型和个数决定函数调用（静态联编）
  函数重写：
    1. 必须发生于父类与子类之间
    2. 并且父类与子类中的函数必须有完全相同的原型（返回类型 函数名称 参数）
    3. 使用virtual声明之后能够产生多态（如果不使用virtual，那叫重定义）
    多态是在运行期间根据具体对象的类型决定函数调用（动态联编）


  1. 父类中的3个func函数是重载关系；子类中的2个func函数是重载关系
  2. 父类中的func(int i, int j)与子类中的func(int i, int j)是虚函数重写 发生多态
  3. 父类中的print()与子类中的print()是非虚函数重写 （重定义）
*/

#include <iostream>

using std::cout;
using std::endl;

class Parent {
public:
    void print()
    {
        cout << "Parent print()" << endl;
    }

    // 这3个函数是重载关系
    virtual void func()
    {
        cout << "Parent: func()" << endl;
    }

    virtual void func(int i)
    {
        printf("Parent: func(%d)\n", i);
    }

    virtual void func(int i, int j)
    {
        printf("Parent: func(%d, %d)\n", i, j);
    }
};

class Child : public Parent {
public:
    void print()
    {
        cout << "Child print()" << endl;
    }

    virtual void func(int i, int j)
    {
        printf("Child: func(%d, %d)\n", i, j);
    }

    virtual void func(int i, int j, int k)
    {
        printf("Child: func(%d, %d, %d)\n", i, j, k);
    }
};

void test1()
{
    Child c;

    // 不是从父类继承了吗，为什么编译失败
    //c.func();   

    // 子类无法重载父类的函数，父类同名函数将被名称覆盖
    // func函数的名字，在子类中发生了名称覆盖；子类的函数的名字，占用了父类的函数的名字的位置
    // 因为子类中已经有了func名字的重载形式，编译器开始在子类中找func函数，但是没有0个参数的func函数


    c.Parent::func();   // 要想使用必须加上域作用符
}

int main()
{
    test1();
    return 0;
}
