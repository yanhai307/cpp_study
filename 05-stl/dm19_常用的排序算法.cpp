//
// Created by yanhai on 2020/2/15.
//

/**
 * 常用的排序算法
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

template<typename T>
void print(T &t, const string &delimiter = " ")
{
    for (auto &item: t) {
        cout << item << delimiter;
    }
    cout << endl;
}

/**
 * merge()
 *   合并两个有序序列，存放在另一个序列
 */
void test1()
{
    vector<int> v1, v2, v3;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(6);

    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(6);

    print(v1);
    print(v2);

    v3.resize(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    print(v3);
}

class Student {
    friend bool CompareStudent(Student &s1, Student &s2);

    friend ostream &operator<<(ostream &os, const Student &s);

public:
    Student(const string &name, int id)
    {
        m_name = name;
        m_id = id;
    }

private:
    string m_name;
    int m_id;
};

bool CompareStudent(Student &s1, Student &s2)
{
    return s1.m_id < s2.m_id;
}

ostream &operator<<(ostream &os, const Student &s)
{
    os << "id: " << s.m_id << ", name: " << s.m_name;
    return os;
}

/**
 * sort()
 *   以默认升序的方式重新排列指定范围内的元素。若要改排序规则，可以输入比较函数。
 */
void test2()
{
    Student s1("老大", 1);
    Student s2("老二", 2);
    Student s3("老三", 3);
    Student s4("老四", 4);
    Student s5("老五", 5);

    vector<Student> v1;
    v1.push_back(s4);
    v1.push_back(s2);
    v1.push_back(s5);
    v1.push_back(s1);
    v1.push_back(s3);
    print(v1, "\n");

    /**
     * 根据自定义函数对象，进行自定义数据类型的排序
     * 替换 算法的统一性（实现的算法和数据类型的分离）
     * 通过函数对象
     */
    sort(v1.begin(), v1.end(), CompareStudent);
    print(v1, "\n");
}

/**
 * random_shuffle()
 *   对指定范围内的元素随机调整次序
 *  // srand(time(nullptr)); // 设置随机种子
 */
void test3()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(8);
    v1.push_back(9);
    print(v1);

    random_shuffle(v1.begin(), v1.end());
    print(v1);  // 每次的值都一样 ？

    string s1 = "abcdefg";
    cout << s1 << endl;
    random_shuffle(s1.begin(), s1.end());
    cout << s1 << endl;
}

/**
 * reverse()
 *   倒序
 */
void test4()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(8);
    v1.push_back(9);
    print(v1);

    reverse(v1.begin(), v1.end());
    print(v1);
}

int main()
{
    test1();    // merge
    test2();    // sort
    test3();    // random_shuffle
    test4();    // reverse
    return 0;
}
