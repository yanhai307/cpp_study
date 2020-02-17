//
// Created by yanhai on 2020/2/7.
//

/**
 * set/multiset
 * - set是一个集合容器，其中所包含的元素是唯一的，集合中的元素按一定的顺序排序，元素插入过程是按排序规则插入，所以不能指定插入位置。
 * - set采用红黑树变体的数据结构实现，红黑树属于平衡二叉树，在插入操作和删除操作上比vector快。
 * - set不可以直接存取元素。（不可以使用at.(pos)和[]操作符）
 * - multiset和set的区别：set支持唯一键值，每个元素值只能出现一次；而multiset中同一值可以出现多次。
 * - 不可以直接修改set或者multiset容器中的元素值，因为该类容器是自动排序的。如果希望修改一个元素值，必须先删除原有的元素，再插入新的元素。
 * #include <set>
 */

#include <iostream>
#include <cassert>
#include <set>

using namespace std;

void test1()
{
    set<int> s1;    // 默认排序为从小到大

    s1.insert(111111);
    s1.insert(8382842);
    s1.insert(20);
    s1.insert(100);
    s1.insert(4);
    s1.insert(100);

    assert(s1.size() == 5);

    for (auto it = s1.begin(); it != s1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 删除元素
    while (!s1.empty()) {
        s1.erase(s1.begin());
    }
    assert(s1.empty());
}

// set从大到小排序
void test2()
{
    set<int> s1;    //
    set<int, less<int>> s2; // s2 与 s1等价
    set<int, greater<int>> s3;  // 从大到小排序

    s3.insert(111111);
    s3.insert(8382842);
    s3.insert(20);
    s3.insert(100);
    s3.insert(4);
    s3.insert(100);

    assert(s3.size() == 5);
    for (set<int, greater<int>>::iterator it = s3.begin(); it != s3.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

/**
 * 复杂数据类型如何排序？
 *   ==> 仿函数  函数对象
 */

class Teacher {
public:
    Teacher(const char *name, int age)
    {
        this->name = name;
        this->age = age;
    }

public:
    string name;
    int age;
};

// 仿函数
struct FuncTeacher {
    bool operator()(const Teacher &t1, const Teacher &t2)
    {
        return t1.age < t2.age; // 从小到大
    }
};

void test3()
{
    set<Teacher, FuncTeacher> s1;
    s1.insert(Teacher("c", 30));
    s1.insert(Teacher("b", 60));
    s1.insert(Teacher("b", 25));

    for (auto &item: s1) {
        cout << item.name << "  " << item.age << endl;
    }

    // 使用pair
    pair<set<Teacher, FuncTeacher>::iterator, bool> pair1 = s1.insert(Teacher("d", 45));
    assert(pair1.second);   // 插入成功
    pair<set<Teacher, FuncTeacher>::iterator, bool> pair2 = s1.insert(Teacher("e", 45));    // 会插入成功吗
    assert(!pair2.second);  // 插入失败
    cout << s1.size() << endl;
}

/**
 * set的查找
 *  - set.find(elem);   查找elem元素，返回指向elem元素的迭代器
 *  - set.count(elem);  返回容器中值为elem的元素个数，对set来说，要么是0要么是1，对于multiset来说，值可能大于1
 *  - set.lower_bound(elem); 返回第1个 >=elem 元素的迭代器
 *  - set.upper_bound(elem); 返回第1个 >elem 元素的迭代器
 *  - set.equal_bound(elem); 返回容器中与elem相等的上下限的两个迭代器，上限是闭区间，下限是开区间，如 [beg, end)
 *
 *    以上函数返回两个迭代器，而这两个迭代器被封装在pair中。
 */
void test4()
{
    set<int> s1;
    for (int i = 0; i < 10; i++) {
        s1.insert(i);
    }

    set<int>::iterator it1 = s1.find(5);
    cout << "it1: " << *it1 << endl;    // 5

    int num = s1.count(5);
    cout << "num: " << num << endl; // 1

    set<int>::iterator it2 = s1.lower_bound(5); // 大于等于5的元素 的迭代器位置
    cout << "it2: " << *it2 << endl;    // 5

    set<int>::iterator it3 = s1.upper_bound(5); // 大于5的元素的迭代器的位置
    cout << "it3: " << *it3 << endl;    // 6

    //
    pair<set<int>::iterator, set<int>::iterator> pair1 = s1.equal_range(5);
    for (set<int>::iterator it = pair1.first; it != pair1.second; ++it) {
        cout << *it << " "; // 5
    }
    cout << endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}
