//
// Created by yanhai on 2019/9/25.
//

#include <iostream>
#include "complex.h"

using std::cout;
using std::endl;
using std::ostream;

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
