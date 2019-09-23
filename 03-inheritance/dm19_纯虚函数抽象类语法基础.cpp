//
// Created by YANHAI on 2019/9/2.
//

#include <iostream>

using std::cout;
using std::endl;

/**
 *  1. 拥有纯虚函数的类为抽象类，
 *  2. 抽象类不能实例化
 *  3. 子类继承抽象类，并实现纯虚函数
 *  4. 子类若不实现纯虚函数，则子类也是一个抽象类，也不能进行实例化
 */

// 面向抽象类编程（面向一套预先定义好的接口编程）
// 解耦合... 模块的划分


class Figure    // 抽象类
{
public:
    // 约定一个统一的界面（接口），让子类使用，让子类必须取实现
    virtual void getArea() = 0; // 纯虚函数
};

// 圆
class Circle : public Figure {
public:
    Circle(int r)
    {
        this->r = r;
    }

    virtual void getArea()
    {
        cout << "圆的面积为: " << 3.14 * r * r << endl;
    }

private:
    int r;
};

// 三角形
class Tri : public Figure {
public:
    Tri(int a, int h)
    {
        this->a = a;
        this->h = h;
    }

    virtual void getArea()
    {
        cout << "三角形的面积为: " << a * h / 2 << endl;
    }

private:
    int a;
    int h;
};


// 矩形
class Square : public Figure {
public:
    Square(int a, int h)
    {
        this->a = a;
        this->h = h;
    }

    virtual void getArea()
    {
        cout << "矩形的面积为: " << a * h << endl;
    }

private:
    int a;
    int h;
};

void objplay(Figure *base)
{
    base->getArea();    // 会发生多态
}

int main()
{
    //Figure f;   // 抽象类不能被实例化
    Figure *base = nullptr;

    Circle c1(10);
    Tri t1(20, 30);
    Square s1(10, 20);

    objplay(&c1);
    objplay(&t1);
    objplay(&s1);

    return 0;
}
