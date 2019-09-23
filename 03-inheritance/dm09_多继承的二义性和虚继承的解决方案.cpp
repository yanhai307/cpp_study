//
// Created by YANHAI on 2019/9/1.
//

/**
  多继承的二义性

  virtual解决多继承的二义性也不是万能的
    1. C从B1和B2继承，而B1和B2又有共同的父类B，B1和B2在继承B时使用虚继承就可以解决创建对象C时只调用1次B类
    2. C从B1和B2继承，如果B1里面有成员k，B2里面有成员k, 再使用c.k时会报错，并且无法使用virtual来解决，
        只能明确指定使用的是谁的k, c.B1::k  c.B2::k
*/

#include <iostream>

using std::cout;
using std::endl;

class B {
public:
    int b;
};

// 虚继承
class B1 : virtual public B {
public:
    int b1;
};

// 虚继承
class B2 : virtual public B {
public:
    int b2;
};


class C : public B1, public B2 {
public:
    int c;
};

void test()
{
    C c;
    c.b1 = 100;
    c.b2 = 200;
    c.c = 300;
    c.b = 400;  // 不是虚继承时，这里报错

}

int main()
{
    test();
    return 0;
}