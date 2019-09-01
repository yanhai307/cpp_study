
/* 多态的思想
    封装：突破c函数的概念。。。用类做函数参数的时候，
          可以使用对象的属性和对象的方法
    继承：A B代码复用
    多态：可以使用未来

  C语言 间接赋值 是指针存在大最大意义
    是C语言的特有的现象（1 定义两个变量 2 建立关联 3 *p在被调用函数中去间接的修改实参的值）
  
  多态的三个条件
    1. 要有继承
    2. 要有虚函数重写
    3. 用父类指针（引用）指向子类对象

  多态是设计模式的基础，多态是框架的基础

  多态理论基础
    1. 静态联编和动态联编
*/

#include <iostream>

using std::cout;
using std::endl;

class HeroFigher {
public:
    virtual int power()
    {
        return 10;
    }
};

class EnemFighter {
public:
    int attack()
    {
        return 15;
    }

};

class AdvHeroFighter : public HeroFigher {
public:
    virtual int power()
    {
        return 20;
    }
};

// 不使用多态
void test1()
{
    HeroFigher hf;
    AdvHeroFighter advhf;
    EnemFighter ef;

    if (hf.power() > ef.attack()) {
        cout << "主角win" << endl;
    } else {
        cout << "主角挂了" << endl;
    }

    if (advhf.power() > ef.attack()) {
        cout << "adv主角win" << endl;
    } else {
        cout << "adv主角挂了" << endl;
    }

}

void play(HeroFigher *hf, EnemFighter *ef)
{
    // 1. hf->power() 函数调用会有多态发生
    // 2. power()不写virtual关键字，将是静态联编，在编译阶段就确定了 执行HeroFigher的power()函数
    // 3. 如果是动态联编（迟绑定），在程序运行时才能确定调用哪个power函数
    if (hf->power() > ef->attack()) {
        cout << "主角win" << endl;
    } else {
        cout << "主角挂了" << endl;
    }
}

// 使用多态
void test2()
{
    HeroFigher hf;
    AdvHeroFighter advhf;
    EnemFighter ef;

    play(&hf, &ef);
    play(&advhf, &ef);
}

int main()
{
    test1();
    test2();
    return 0;
}
