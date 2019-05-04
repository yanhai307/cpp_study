//
// Created by YANHAI on 2019/5/4.
//
/**
 * 类的基本概念
 *  1. 类、对象、成员变量、成员函数
 *  2. 面向对象三大概念
 *     封装、继承、多态
 *  3. 编程实践
 *    类的定义和对象的定义。对象的使用
 *    求圆的面积
 *    定义Teacher类，打印Teacher的信息（把类的声明和类的实现分开）
 */

/*
 * 类的封装
 *  1. 封装是面向对象程序设计最基本的特性，把数据（属性）和函数（操作）合成一个整体，
 *     这在计算机世界里是类与对象实现的。
 *     封装，也就是把客观事物封装成抽象的类，并且类可以把自己的数据和方法只让可信的类或者
 *     对象操作，对不可信的进行信息隐藏。
 *     备注： 有2层含义（把属性和方法进行封装，对属性和方法进行访问控制）
 *  2. 类成员的访问控制
 *    C++中类的封装
 *      成员变量，C++中用于表示类属性的变量
 *      成员函数，C++中用于表示类行为的函数
 *    在C++中可以给成员变量和成员函数定义访问级别
 *      public  修饰成员变量和成员函数 可以在类的内部和类的外部被访问
 *      private 修饰成员变量和成员函数 只能在类的内部被访问
 *      protected 修饰成员变量和成员函数 只能在类的内部被访问，用在继承里面
 */

#include <iostream>

using namespace std;

class MyCircle {
public:
    double m_r; // 属性 成员变量
    double m_s;

public:
    double getR() {
        return m_r;
    }

    void setR(double r) {
        m_r = r;
    }

    double getS() {
        m_s = 3.14 * m_r * m_r;
        return m_s;
    }
};

// 类封装的成员变量和成员函数
// 可以调用类的成员函数
void printCircle01(MyCircle *pC) {
    cout << "r: " << pC->getR() << endl;
    cout << "s: " << pC->getS() << endl;
}

void printCircle02(MyCircle &pC) {
    cout << "r: " << pC.getR() << endl;
    cout << "s: " << pC.getS() << endl;
}

void printCircle03(MyCircle pC) {
    cout << "r: " << pC.getR() << endl;
    cout << "s: " << pC.getS() << endl;
}


int main1() {
    MyCircle c1, c2;
    c1.setR(10);
    cout << "c1 s: " << c1.getS() << endl;

    c1.setR(11);
    printCircle01(&c1);

    c2.setR(20);
    printCircle01(&c2);

    // 引用
    printCircle02(c1);

    return 0;
}

// 访问控制
class MyAdvCircle {
    double m_r2;    // 没有权限修饰的成员变量/函数，默认是私有属性
private:
    double m_r; // 属性 成员变量
    double m_s;

public:
    double getR() {
        return m_r;
    }

    void setR(double r) {
        m_r = r;
    }

    double getS() {
        m_s = 3.14 * m_r * m_r;
        return m_s;
    }
};

int main2()
{
    MyAdvCircle c1,c2;
//    c1.m_r = 10;  // 私有成员，无法在类外部访问
    c1.setR(10);
    return 0;
}

struct AA{
    int a;  // 用struct关键字定义的类，默认属性是public
};

int main()
{
    main1();
    main2();
    return 0;
}

