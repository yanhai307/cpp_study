
/*
  虚继承
    如果一个派生类从多个基类派生，而这些基类又有一个共同的基类，
    则在对该基类中声明的名字进行访问时，可能产生二义性。
*/

#include <iostream>

using std::cout;
using std::endl;

class B {
public:
    int b;
};


class B1 : public B {
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

void test1()
{                                               // 32bit  64bit
    cout << "sizeof(B)" << sizeof(B) << endl;   // 4       4
    cout << "sizeof(B1)" << sizeof(B1) << endl; // 8       8
    cout << "sizeof(B2)" << sizeof(B2) << endl; // 12     16     加了virtual关键字， 编译器加了其他属性？
    cout << "sizeof(C)" << sizeof(C) << endl;   // 24     32
}

void test2_B1()
{
    printf("-----------------B1--------------\n");
    B1 b1;
    printf("sizeof(b1): %ld\n", sizeof(b1));
    printf("b1   : %p\n", &b1);
    printf("b1.b : %p, offset: %ld\n", &b1.b, (long)&b1.b - (long)&b1);
    printf("b1.b1: %p, offset: %ld\n", &b1.b1, (long)&b1.b1 - (long)&b1);

    B &b = b1;
    printf("sizeof(b): %ld\n", sizeof(b));
    printf("b    : %p, offset: %ld\n", &b, (long)&b - (long)&b1);
    printf("b.b  : %p, offset: %ld\n", &b.b, (long)&b.b - (long)&b);
}

void test2_B2()
{
    printf("-----------------B2--------------\n");
    B2 b2;
    printf("sizeof(b2): %ld\n", sizeof(b2));
    printf("b2   : %p\n", &b2);
    printf("b2.b : %p, offset: %ld\n", &b2.b, (long)&b2.b - (long)&b2);
    printf("b2.b2: %p, offset: %ld\n", &b2.b2, (long)&b2.b2 - (long)&b2);

    B &b = b2;
    printf("sizeof(b): %ld\n", sizeof(b));
    printf("b    : %p, offset: %ld\n", &b, (long)&b - (long)&b2);
    printf("b.b  : %p, offset: %ld\n", &b.b, (long)&b.b - (long)&b);
}

void test2_C()
{
    printf("-----------------C--------------\n");
    C c;
    printf("sizeof(c): %ld\n", sizeof(c));
    printf("c       : %p\n", &c);
    printf("c.B1::b : %p, offset: %ld\n", &c.B1::b, (long)&c.B1::b - (long)&c);
    printf("c.B2::b : %p, offset: %ld\n", &c.B2::b, (long)&c.B2::b - (long)&c);
    printf("c.b1    : %p, offset: %ld\n", &c.b1, (long)&c.b1 - (long)&c);
    printf("c.b2    : %p, offset: %ld\n", &c.b2, (long)&c.b2 - (long)&c);
    printf("c.c     : %p, offset: %ld\n", &c.c, (long)&c.c - (long)&c);

    B1 &b1 = c;
    printf("sizeof(b1): %ld\n", sizeof(b1));
    printf("b1   : %p, offset: %ld\n", &b1, (long)&b1 - (long)&c);
    printf("b1.b : %p, offset: %ld\n", &b1.b, (long)&b1.b - (long)&b1);
    printf("b1.b1: %p, offset: %ld\n", &b1.b1, (long)&b1.b1 - (long)&b1);

    B2 &b2 = c;
    printf("sizeof(b2): %ld\n", sizeof(b2));
    printf("b2   : %p, offset: %ld\n", &b2, (long)&b2 - (long)&c);
    printf("b2.b : %p, offset: %ld\n", &b2.b, (long)&b2.b - (long)&b2);
    printf("b2.b2: %p, offset: %ld\n", &b2.b2, (long)&b2.b2 - (long)&b2);

    // 报错，c中有2个B，这样写不知道是使用从B1继承来的B还是从B2继承来的B
    /*
    B &b = c;
    printf("sizeof(b): %ld\n", sizeof(b));
    printf("b    : %p, offset: %ld\n", &b, (long)&b - (long)&b2);
    printf("b.b  : %p, offset: %ld\n", &b.b, (long)&b.b - (long)&b);
     */
}

int main()
{
    test1();
    test2_B1();
    test2_B2();
    test2_C();
    return 0;
}