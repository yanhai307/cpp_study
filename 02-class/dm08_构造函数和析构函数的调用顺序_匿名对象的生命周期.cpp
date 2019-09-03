//
// Created by YANHAI on 2019/5/26.
//

#include <iostream>

using namespace std;

class ABCD {
public:
    ABCD(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        printf("ABCD() constructor: %p, a:%d,b:%d,c:%d\n", this, this->a, this->b, this->c);
    }

    ~ABCD()
    {
        printf("~ABCD() constructor: %p, a:%d,b:%d,c:%d\n", this, this->a, this->b, this->c);
    }

    int getA()
    {
        return a;
    }

private:
    int a;
    int b;
    int c;
};

class MyE {
public:
    MyE() : abcd1(1, 2, 3), abcd2(4, 5, 6), m(100)
    {
        printf("MyE(), abcd1: %p, abcd2: %p\n", &abcd1, &abcd2);
    }

    // 不写拷贝构造函数时，为什么只执行了2次ABCD类的构造函数，却析构了4次
    MyE(const MyE &obj) : abcd1(7, 8, 9), abcd2(10, 11, 12), m(200)
    {
        printf("MyE(const MyE &obj), abcd1: %p, abcd2: %p\n", &abcd1, &abcd2);
    }

    ~MyE()
    {
        printf("~MyE(), abcd1: %p, abcd2: %p\n", &abcd1, &abcd2);
    }

public:
    ABCD abcd1;
    ABCD abcd2;
    const int m;
};

void func(MyE myE)
{
    cout << "func myE.abcd1.getA(): " << myE.abcd1.getA() << endl;
}

// 1. 分析构造函数和析构函数的调用顺序
int run1()
{
    MyE myE;
    func(myE);
    return 0;
}

// 2. 匿名对象的生命周期
int run2()
{
    cout << "run2 start..." << endl;
//    ABCD(100, 200, 300);    // 调用了构造函数后，立即调用了析构函数，匿名对象的生命周期只是这一行

    ABCD abcd = ABCD(400, 500, 600);    // 函数执行完毕后，才调用析构函数

    cout << "run2 end.." << endl;
    return 0;
}

int main()
{
//    run1();
    run2();
    return 0;
}
