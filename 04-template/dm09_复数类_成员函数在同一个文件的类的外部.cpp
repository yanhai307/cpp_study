//
// Created by yanhai on 2019/9/25.
//

/**
 * 将所有的模板类的成员函数都写在类的外部，但在同一个文件中。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

template<typename T>
class Complex {
public:
    /**
     * 编译报错：
     * Undefined symbols for architecture x86_64:
     *  "operator<<(std::__1::basic_ostream<char, std::__1::char_traits<char> >&, Complex<int> const&)", referenced from:
     *     _main in dm09_复数类_成员函数在同一个文件的类的外部.cpp.o
     * ld: symbol(s) not found for architecture x86_64
     *
     *  问题解析：
     *      本质是 模板是两次编译生成的，第一次生成的函数头和第二次生成的函数头 不一样
     */
    // 下面一行这样写，operator<<并不是一个模板函数
//    friend ostream &operator<<(ostream &out, const Complex &c);

    template <typename T1>
    friend ostream &operator<<(ostream &out, const Complex<T1> &c);

    template <typename T1>
    friend Complex<T1> mySub(const Complex<T1> &c1, const Complex<T1> &c2);

    Complex(T a, T b);

    void printCom();

    Complex operator+(Complex &c2);

private:
    T a;
    T b;
};

/**
 * 构造函数
 * @tparam T
 * @param a
 * @param b
 */
template<typename T>
Complex<T>::Complex(T a, T b)
{
    this->a = a;
    this->b = b;
}

/**
 * 普通成员函数
 * @tparam T
 */
template<typename T>
void Complex<T>::printCom()
{
    cout << a << " + " << b << " i" << endl;
}

/**
 * 成员函数 实现+号运算符重载
 *
 * 因为这个是成员函数，所以 参数和函数体内可以不写<T>，如果是全局函数，则必须要写
 * 返回值类型中一定要写<T>
 * @tparam T
 * @param c2
 * @return
 */
template<typename T>
Complex<T> Complex<T>::operator+(Complex &c2)   // 参数也可以写为Complex<T> &c2
{
    // 可以写为Complex<T> tmp...
    Complex tmp(a + c2.a, b + c2.b);
    return tmp;
}

/**
 * 友元函数，实现重载
 * @tparam T
 * @param out
 * @param c
 * @return
*/
template<typename T>
ostream &operator<<(ostream &out, const Complex<T> &c)
{
    out << c.a << " + " << c.b << " i";
    return out;
}

/**
 * 友元函数，不是实现重载
 * @tparam T
 * @param c1
 * @param c2
 * @return
 */
template <typename T>
Complex<T> mySub(const Complex<T> &c1, const Complex<T> &c2)
{
    Complex<T> tmp(c1.a - c2.a, c1.b - c2.b);
    return tmp;
}

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
