//
// Created by yanhai on 2019/10/22.
//
#pragma once

#include <iostream>

using std::ostream;

template<typename T>
class MyVector {
public:
    template<typename T1>
    friend ostream &operator<<(ostream &out, const MyVector<T1> &obj);

public:
    MyVector(int size = 0);

    MyVector(const MyVector &obj);

    ~MyVector();

public:
    MyVector &operator=(const MyVector &obj);

    T &operator[](int index) const;

    int len() const
    {
        return m_len;
    }

private:
    T *m_space;
    int m_len;
};

template<typename T>
ostream &operator<<(ostream &out, const MyVector<T> &obj)
{
    for (int i = 0; i < obj.len(); ++i) {
        out << obj[i] << " ";
    }
    return out;
}

template<typename T>
MyVector<T>::MyVector(int size)
{
    m_space = new T[size];
    m_len = size;
}

template<typename T>
MyVector<T>::MyVector(const MyVector &obj)
{
    m_len = obj.m_len;
    m_space = new T[m_len];
    for (int i = 0; i < m_len; ++i) {
        m_space[i] = obj[i];
    }
}

template<typename T>
MyVector<T>::~MyVector()
{
    delete[] m_space;
    m_space = nullptr;
    m_len = 0;
}

template<typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector &obj)
{
    delete[] m_space;

    m_len = obj.m_len;
    m_space = new T[m_len];
    for (int i = 0; i < m_len; ++i) {
        m_space[i] = obj[i];
    }
    return *this;
}

template<typename T>
T &MyVector<T>::operator[](int index) const
{
    return m_space[index];
}
