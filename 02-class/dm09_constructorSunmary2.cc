//
// Created by YANHAI on 2019/5/26.
//

#include <iostream>

using namespace std;

class MyTest {
public:
    MyTest(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    MyTest(int a, int b)
    {
        this->a = a;
        this->b = b;
        MyTest(a, b, 100);
    }

    ~MyTest()
    {
        printf("~MyTest: %d,%d,%d\n", a, b, c);
    }

private:
    int a;
    int b;
    int c;
public:
    int getC() const
    {
        return c;
    }

    void setC(int val)
    {
        c = val;
    }
};


int main()
{
    MyTest t1(1, 2);
    printf("c:%d\n", t1.getC());  // c的值是多少(c的值是随机数，是乱码)
    return 0;
}