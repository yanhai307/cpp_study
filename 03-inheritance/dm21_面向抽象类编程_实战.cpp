//
// Created by YANHAI on 2019/9/2.
//

/**
    编写一个C++程序，计算程序员(Programmer)工资
      1. 要求能计算初级程序员（JuniorProgrammer）中级程序员（MidProgrammer）高级程序员（AdvProgrammer）的工资
      2. 要求利用抽象类同一界面，方便程序的扩展，比如：新增 计算 架构师（Architect）的工资
*/

#include <iostream>

using std::cout;
using std::endl;

class Programmer {
public:
    virtual void getSal() = 0;
};

// 初级
class JuniorProgrammer : public Programmer {
public:
    JuniorProgrammer(const char *name, const char *job, int sal)
    {
        this->name = name;
        this->job = job;
        this->sal = sal;
    }

    virtual void getSal()
    {
        cout << name << " " << job << ": " << sal << endl;
    }

private:
    const char *name;
    const char *job;
    int sal;
};

// 中级
class MidProgrammer : public Programmer {
public:
    MidProgrammer(const char *name, const char *job, int sal)
    {
        this->name = name;
        this->job = job;
        this->sal = sal;
    }

    virtual void getSal()
    {
        cout << name << " " << job << ": " << sal << endl;
    }

private:
    const char *name;
    const char *job;
    int sal;
};

// 高级
class AdvProgrammer : public Programmer {
public:
    AdvProgrammer(const char *name, const char *job, int sal)
    {
        this->name = name;
        this->job = job;
        this->sal = sal;
    }

    virtual void getSal()
    {
        cout << name << " " << job << ": " << sal << endl;
    }

private:
    const char *name;
    const char *job;
    int sal;
};

// 架构师
class Architect : public Programmer {
public:
    Architect(const char *name, const char *job, int sal)
    {
        this->name = name;
        this->job = job;
        this->sal = sal;
    }

    virtual void getSal()
    {
        cout << name << " " << job << ": " << sal << endl;
    }

private:
    const char *name;
    const char *job;
    int sal;
};

void getSal(Programmer *base)
{
    base->getSal();
}

int main()
{
    JuniorProgrammer jp("小王", "初级", 5000);
    MidProgrammer mp("小刘", "中级", 8300);
    AdvProgrammer ap("小张", "高级", 15000);

    getSal(&jp);
    getSal(&mp);
    getSal(&ap);

    // 新增
    Architect ar("小赵", "架构师", 24000);
    getSal(&ar);


    return 0;
}