//
// Created by YANHAI on 2020/2/13.
//

/**
 * multimap案例
 *   1个key值可以对应多个value  ==》分组
 *   公司有销售部 sale(员工2名)，技术研发部 development 1人，财务部 Financial 2人
 *   人员信息有：姓名，年龄，电话，工资等组成
 *   通过multimap进行 信息的插入、保存、显示
 *   分部门显示员工信息
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Person {
public:
    Person(const string &name, int age, const string &telephone, double salary)
    {
        this->name = name;
        this->age = age;
        this->telephone = telephone;
        this->salary = salary;
    }

public:
    string name;
    int age;
private:
    string telephone;
    double salary;
};

void test1()
{
    Person p1("王1", 31, "13800101234", 15000);
    Person p2("王2", 32, "13800101434", 13000);
    Person p3("张3", 29, "13800101412", 16000);
    Person p4("赵4", 32, "13800101411", 16000);
    Person p5("赵5", 35, "13800101413", 20000);

    multimap<string, Person> m1;
    // sale部门
    m1.insert(make_pair("sale", p1));
    m1.insert(make_pair("sale", p2));

    // development 部门
    m1.insert(make_pair("development", p3));

    // Financial 部门
    m1.insert(make_pair("Financial", p4));
    m1.insert(make_pair("Financial", p5));

    // 遍历
    for (multimap<string, Person>::iterator it = m1.begin(); it != m1.end(); ++it) {
        cout << it->first << "\t" << it->second.name << endl;
    }

    // 按部门显示
    int num =  m1.count("Financial");
    cout << "Financial 部门人数" << num << "；分别为：" <<endl;

    int tag = 0;
    multimap<string, Person>::iterator it2 = m1.find("Financial");  // 返回第一个Financial位置的迭代器
    while (it2 != m1.end() && tag < num) {
        cout << it2->second.name << endl;
        ++it2;
        ++tag;
    }
}

// 修改， 把age等于32的，name修改为name32
void test2()
{
    Person p1("王1", 31, "13800101234", 15000);
    Person p2("王2", 32, "13800101434", 13000);
    Person p3("张3", 29, "13800101412", 16000);
    Person p4("赵4", 32, "13800101411", 16000);
    Person p5("赵5", 35, "13800101413", 20000);

    multimap<string, Person> m1;
    // sale部门
    m1.insert(make_pair("sale", p1));
    m1.insert(make_pair("sale", p2));

    // development 部门
    m1.insert(make_pair("development", p3));

    // Financial 部门
    m1.insert(make_pair("Financial", p4));
    m1.insert(make_pair("Financial", p5));

    for (multimap<string, Person>::iterator it = m1.begin(); it != m1.end(); ++it) {
        if (it->second.age == 32) {
            it->second.name = "name32";
        }
    }

    // 遍历
    for (multimap<string, Person>::iterator it = m1.begin(); it != m1.end(); ++it) {
        cout << it->first << "\t" << it->second.name << endl;
    }
}

int main()
{
    test1();
    test2();
    return 0;
}
