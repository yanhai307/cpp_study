//
// Created by YANHAI on 2019/12/15.
//

/**
 * C风格的强制类型转换
 *  TYPE b = (TYPE)a;
 *
 * C++风格的类型转换提供了4种：
 *  static_cast  静态类型转换 如int转换成char
 *  reinterpret_cast 重新解释类型
 *  dynamic_cast 命名上理解是动态类型转换，如子类和父类之间的多态类型转换
 *  const_cast  字面上理解就是去const属性
 *
 *  转换的格式
 *   TYPE b = static_cast<TYPE>(a);
 *
 * 1.static_cast 静态类型转换，编译时C++编译器会做类型检测；基本类型能转换，但是不能转换指针类型
 * 2.若不同类型之间，进行强制类型转换，用reinterpret_cast进行重新解释
 * 3.一般结论：
 *   C语言中 能隐式类型转换的，在C++中可用static_cast进行类型转换，C++编译器在编译检查时一般都能通过
 *   C语言中 不能隐式类型转换的，在C++中可以用 reinterpret_cast进行强制类型解释。 reinterpret_cast很难保证移植性。
 * 4.dynamic_cast 动态类型转换，安全的基类和子类之间的转换，运行时类型检测
 * 5.const_cast 去除变量的只读属性
 */

#include <iostream>

using namespace std;

class Animal {
public:
    virtual void cry() = 0;
};

class Dog : public Animal {
public:
    void cry() override
    {
        cout << "汪汪" << endl;
    }

    void doHome()
    {
        cout << "看家" << endl;
    }
};

class Cat : public Animal {
public:
    void cry() override
    {
        cout << "喵喵" << endl;
    }

    void doThing()
    {
        cout << "抓老鼠" << endl;
    }
};

void dynamic_cast_test(Animal *base)
{
    base->cry();
    // 动态类型识别，RIIT,  如果转换失败，则为nullptr
    // 父类对象 ==> 子类对象 向下转型
    Dog *dog = dynamic_cast<Dog *>(base); //
    if (dog) {
        dog->doHome();
    }

    Cat *cat = dynamic_cast<Cat *>(base);
    if (cat) {
        cat->doThing();
    }
}

void printBuf(const char *p)
{
//    p[0] = 'z';

    // const char *  ==>  char *
    // 要确保p指向的内存空间确实可以修改，如果不能会带来灾难性后果
    char *p1 = const_cast<char *>(p);
    p1[0] = 'Z';
    cout << p << endl;
}

int main()
{
    // static_cast
    {
        double dpi = 3.1415926;
        int num1 = (int) dpi;    // c style
        int num2 = static_cast<int>(dpi);   // c++  静态类型转换，让C++编译器在编译的时候做类型检查
        int num3 = dpi; // 隐式转换
    }

    // reinterpret_cast
    {
        const char *p = "hello c++";
//       const int *pInt1 = p;   // 不能隐式类型转换
        const int *pInt2 = (int *) p;
        const int *pInt3 = reinterpret_cast<const int *>(p);

        cout << p << endl;
        cout << pInt2 << endl;
        cout << pInt3 << endl;
    }

    // dynamic_cast
    {
        Dog d;
        Cat c;
        dynamic_cast_test(&d);
        dynamic_cast_test(&c);
    }

    {
        class Tree {};
        Animal *base;
        Dog d;
        Tree *t;
        base = &d;
        base = static_cast<Animal *>(&d);
        base = reinterpret_cast<Animal *>(&d);
//        t = static_cast<Tree *>(&d);    // 会做类型检查，转换失败
        t = reinterpret_cast<Tree *>(&d);   // 重新解释为Tree类型，是可以的
    }

    // const_cast
    {
        char buf[] = "hello world";
        printBuf(buf);
    }
    return 0;
}
