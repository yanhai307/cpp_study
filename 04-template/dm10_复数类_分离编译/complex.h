//
// Created by yanhai on 2019/9/25.
//

#ifndef CPP_STUDY_COMPLEX_H
#define CPP_STUDY_COMPLEX_H

#include <iostream>

using std::ostream;

template<typename T>
class Complex {
public:
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

#endif //CPP_STUDY_COMPLEX_H
