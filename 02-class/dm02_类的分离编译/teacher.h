//
// Created by YANHAI on 2019/5/4.
//
#pragma once // 只包含一次，相当于下面的3行
/*
#ifndef CPP_STUDY_DM02_CLASS_H
#define CPP_STUDY_DM02_CLASS_H

...

#endif //CPP_STUDY_DM02_CLASS_H
*/

// 在类内部，当函数声明和函数定义写在一起时，C++编译器会把函数进行优化，变为内联函数
class MyTeacher {
private:
    int m_age;
    char m_name[32];
public:
    void setAge(int age);

    int getAge();
};
