//
// Created by yanhai on 2019/9/25.
//

/**
 * 将所有的模板类的成员函数都写在类的内部
 */

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

template<typename T>
class Complex {
public:
    friend Complex mySub(const Complex &c1, const Complex &c2)
    {
        Complex tmp(c1.a - c2.a, c1.b - c2.b);
        return tmp;
    }

    friend ostream &operator<<(ostream &out, const Complex &c)
    {
        out << c.a << " + " << c.b << " i";
        return out;
    }

    Complex(T a, T b)
    {
        this->a = a;
        this->b = b;
    }

    void printCom()
    {
        cout << a << " + " << b << " i" << endl;
    }

    Complex operator+(Complex &c2)
    {
        Complex tmp(a + c2.a, b + c2.b);
        return tmp;
    }

private:
    T a;
    T b;
};

int main()
{
    Complex<int> c1(1, 2);
    Complex<int> c2(3, 4);

    {
        Complex<int> c3 = c1 + c2;
        cout << c3 << endl;
    }

    {
        Complex<int> c4 = mySub(c1, c2);
        cout << c4 << endl;
    }

    return 0;
}
