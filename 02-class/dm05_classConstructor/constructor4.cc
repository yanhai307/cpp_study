//
// Created by yanhai on 19-8-18.
//

/**
 * 再探匿名对象：  构造函数中调用构造函数
 */

#include <iostream>

using namespace std;

class Test {
public:
    Test(int a, int b)
    {
        this->a = a;
        this->b = b;
        Test(3, 4, 5);  // 产生一个匿名对象，执行完这行，匿名对象立即被释放
        cout << "调用了2个参数的构造函数, a: " << a << " b: " << b << endl;

    }

    Test(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;

        cout << "调用了3个参数的构造函数, a: " << a << " b: " << b << " c: " << c << endl;
    }

    ~Test()
    {
        cout << "调用了析构函数, a: " << a << " b: " << b << " c: " << c << endl;
    }

    int getC()
    {
        return c;
    }

private:
    int a;
    int b;
    int c;
};

void test()
{
    // 下面这2行，在test函数中， t.getC的值固定是0，但是放在main函数中，c的值是不固定的
    Test t = Test(1, 2);
    cout << "c: " << t.getC() << endl;
}

int main()
{
    test();

//    Test t = Test(1, 2);
//    cout << "c: " << t.getC() << endl;

    return 0;
}

/**
 * 结论： 不要在构造函数调用构造函数
 */