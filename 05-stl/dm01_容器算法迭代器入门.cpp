//
// Created by YANHAI on 2019/12/15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 容器存储 基础数据类型
void test1()
{
    vector<int> v1;     // 容器

    v1.push_back(1);    // 把元素拷贝到容器
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(3);

    // 迭代器, 相当于一个指针
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 算法，查找=3的个数
    cout << "=3的个数: " << count(v1.begin(), v1.end(), 3) << endl;
}

class Teacher {
public:
    Teacher(int age) : m_age(age) { ; }

    void print_info()
    {
        cout << "age: " << m_age << endl;
    }

private:
    int m_age;
};

// 容器存储 元素
void test2()
{
    Teacher t1(23), t2(19), t3(29);

    vector<Teacher> v1;     // 容器

    v1.push_back(t1);
    v1.push_back(t2);
    v1.push_back(t3);

    // 迭代器
    for (vector<Teacher>::iterator it = v1.begin(); it != v1.end(); ++it) {
        it->print_info();
    }
    cout << endl;

    // 算法，如何查找age等于23的个数
//    cout << "=3的个数: " << count(v1.begin(), v1.end(), 3) << endl;
}

// 容器存储 元素指针
void test3()
{
    Teacher t1(23), t2(19), t3(29);

    vector<Teacher *> v1;     // 容器

    v1.push_back(&t1);
    v1.push_back(&t2);
    v1.push_back(&t3);

    // 迭代器
    for (vector<Teacher *>::iterator it = v1.begin(); it != v1.end(); ++it) {
        (*it)->print_info();
    }
    cout << endl;
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}
