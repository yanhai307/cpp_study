//
// Created by yanhai on 2019/8/17.
//

#ifndef CPP_STUDY_MYSTRING_H
#define CPP_STUDY_MYSTRING_H


class MyString {
    friend std::ostream &operator<<(std::ostream &out, const MyString &s);

public:
    MyString();

    MyString(const char *s);

    MyString(const MyString &s);

    ~MyString();

    MyString &operator=(const char *s);

    MyString &operator=(const MyString &s);

    char &operator[](int index);


private:
    int m_len;
    char *m_p;
};


#endif //CPP_STUDY_MYSTRING_H
