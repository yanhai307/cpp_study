//
// Created by yanhai on 2019/8/17.
//

#ifndef CPP_STUDY_MYSTRING_H
#define CPP_STUDY_MYSTRING_H

#include <iostream>

class MyString {
    friend std::ostream &operator<<(std::ostream &out, const MyString &s);

    friend std::istream &operator>>(std::istream &in, const MyString &s);

public:
    MyString(int size = 0);

    MyString(const char *s);

    MyString(const MyString &s);

    ~MyString();

    MyString &operator=(const char *s);

    MyString &operator=(const MyString &s);

    // no const []
    char &operator[](int index);

    // const []
    const char &operator[](int index) const;

    bool operator==(const MyString &s) const;

    bool operator!=(const MyString &s) const;

    bool operator>(const MyString &s) const;

    bool operator<(const MyString &s) const;

    MyString &operator<<(const char *p);

    char *c_str()
    {
        return m_p;
    }

    const char *c_str() const
    {
        return m_p;
    }


private:
    int m_len;
    char *m_p;
    int m_size;
};


#endif //CPP_STUDY_MYSTRING_H
