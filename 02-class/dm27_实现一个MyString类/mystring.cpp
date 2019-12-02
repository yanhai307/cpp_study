//
// Created by yanhai on 2019/8/17.
//

#include <iostream>
#include <cstring>
#include "mystring.h"

using namespace std;

ostream &operator<<(ostream &out, const MyString &s)
{
    out << s.m_p;
    return out;
}

std::istream &operator>>(std::istream &in, const MyString &s)
{
    in >> s.m_p;
    return in;
}

MyString::MyString(int size)
{
    m_len = 0;
    m_size = size;
    m_p = new char[m_size + 1];
//    m_p[m_len] = 0;
    memset(m_p, 0, m_size + 1);
}

MyString::MyString(const char *s)
{
    if (s == nullptr)
        s = "";

    m_len = strlen(s);
    m_size = m_len;
    m_p = new char[m_size + 1];
    strcpy(m_p, s);
    m_p[m_size] = 0;
}

MyString::MyString(const MyString &s)
{
    m_len = s.m_len;
    m_size = m_len;
    m_p = new char[m_size + 1];
    strcpy(m_p, s.m_p);
    m_p[m_size] = 0;
}

MyString::~MyString()
{
    delete[] m_p;
    m_len = 0;
    m_size = 0;
}

MyString &MyString::operator=(const char *s)
{
    delete[]m_p;

    if (s == nullptr)
        s = "";

    m_len = strlen(s);
    m_size = m_len;
    m_p = new char[m_size + 1];
    strcpy(m_p, s);
    m_p[m_size] = 0;
    return *this;
}

MyString &MyString::operator=(const MyString &s)
{
    delete[]m_p;
    m_len = s.m_len;
    m_size = m_len;
    m_p = new char[m_size + 1];
    strcpy(m_p, s.m_p);
    m_p[m_size] = 0;
    return *this;
}

char &MyString::operator[](int index)
{
    if (index < 0)
        index = 0;
    if (index > m_size)
        index = m_size;
    return m_p[index];
}

const char &MyString::operator[](int index) const
{
    if (index < 0)
        index = 0;
    if (index > m_size)
        index = m_size;
    return m_p[index];
}

bool MyString::operator==(const MyString &s) const
{
    if (m_len != s.m_len)
        return false;

    return !strcmp(m_p, s.m_p);
}

bool MyString::operator!=(const MyString &s) const
{
    return !(*this == s);
}

bool MyString::operator>(const MyString &s) const
{
    return strcmp(m_p, s.m_p) > 0;
}

bool MyString::operator<(const MyString &s) const
{
    return strcmp(m_p, s.m_p) < 0;
}

MyString::operator bool() const
{
    return !!*this;
}

bool MyString::operator!() const
{
    return m_len == 0;
}

MyString &MyString::operator<<(const char *p)
{
    if (p != nullptr) {
        int len = strlen(p);
        if (len > 0) {
            if (len > m_size - m_len)
                len = m_size - m_len;
            if (len > 0) {
                strncpy(m_p + m_len, p, len);
                m_len += len;
                m_p[m_len] = 0;
            }
        }
    }

    return *this;
}
