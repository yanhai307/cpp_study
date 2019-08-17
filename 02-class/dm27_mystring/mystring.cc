//
// Created by yanhai on 2019/8/17.
//

#include <iostream>
#include <cstring>
#include "mystring.h"

using namespace std;

MyString::MyString()
{
    m_len = 0;
    m_p = new char[m_len + 1];
    m_p[m_len] = 0;
}

MyString::MyString(const char *s)
{
    if (s == nullptr)
        s = "";

    m_len = strlen(s);
    m_p = new char[m_len + 1];
    strcpy(m_p, s);
    m_p[m_len] = 0;
}

MyString::MyString(const MyString &s)
{
    m_len = s.m_len;
    m_p = new char[m_len + 1];
    strcpy(m_p, s.m_p);
    m_p[m_len] = 0;
}

MyString::~MyString()
{
    delete[] m_p;
    m_len = 0;
}

ostream &operator<<(ostream &out, const MyString &s)
{
    out << s.m_p;
    return out;
}

MyString &MyString::operator=(const char *s)
{
    delete[]m_p;

    if (s == nullptr)
        s = "";

    m_len = strlen(s);
    m_p = new char[m_len + 1];
    strcpy(m_p, s);
    m_p[m_len] = 0;
    return *this;
}


MyString &MyString::operator=(const MyString &s)
{
    delete[]m_p;
    m_len = s.m_len;
    m_p = new char[m_len + 1];
    strcpy(m_p, s.m_p);
    m_p[m_len] = 0;
    return *this;
}

char &MyString::operator[](int index)
{
    if (index < 0)
        index = 0;
    if (index > m_len)
        index = m_len;
    return m_p[index];
}
