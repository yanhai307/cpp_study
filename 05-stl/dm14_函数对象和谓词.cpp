//
// Created by YANHAI on 2020/2/14.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 函数对象 类重载了()
template<typename T>
class ShowElement {
public:
    ShowElement()
    {
        n = 0;
    }

    void operator()(T &t)
    {
        ++n;
        cout << t << " ";
    }

    void printN()
    {
        cout << "n: " << n << endl;
    }

private:
    int n;
};

template<typename T>
void FuncShowElement(T &t)
{
    cout << t << endl;
}

void FuncShowElement2(int &t)
{
    cout << t << endl;
}

/**
 * 函数对象 定义： 函数对象和普通函数的相同之处
 */
void test1()
{
    int a = 10;
    ShowElement<int> showElement;
    showElement(a);     // 函数对象的()的执行， 很像一个函数，仿函数

    FuncShowElement<int>(a);
    FuncShowElement(a);
    FuncShowElement2(a);
}

/**
 * 函数对象是属于类对象，能突破函数的概念，能保持调用状态信息
 * 函数对象的好处：
 *   for_each算法中，函数对象做函数参数
 *   for_each算法中，函数对象做返回值
 */
void test2()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    for_each(v1.begin(), v1.end(), ShowElement<int>()); // 匿名函数对象， 匿名仿函数
    for_each(v1.begin(), v1.end(), FuncShowElement2);   // 通过回调函数

    ShowElement<int> show1;
    for_each(v1.begin(), v1.end(), show1);
    show1.printN(); // 为什么打印为0， 原因是for_each算法的 函数对象 是值传递，不是引用传递

    // 通过for_each算法的返回值看调用的次数
    show1 = for_each(v1.begin(), v1.end(), show1);
    show1.printN();

    // 要点： 分清楚 stl算法返回的值是迭代器还是谓词（函数对象）是stl算法入门的重点
}

/**
 * 谓词：
 *  一元函数对象：函数参数1个，比如上面的 ShowElement 就是一个一元函数对象
 *  二元函数对象：函数参数2个
 *
 *  一元谓词： 函数参数1个，函数返回值是bool类型，可以作为一个判断式，谓词可以是一个仿函数，也可以是一个回调函数
 *  二元谓词：函数参数2个，函数返回值是bool类型。
 */

template<typename T>
class IsDiv {
public:
    IsDiv(const T &divisor)
    {
        this->divisor = divisor;
    }

    bool operator()(T &t)
    {
        return (t % divisor == 0);
    }

private:
    T divisor;
};

void test3()
{
    vector<int> v2;
    for (int i = 10; i < 33; ++i) {
        v2.push_back(i);
    }
    auto it = find_if(v2.begin(), v2.end(), IsDiv<int>(4)); // find_if返回的是一个迭代器
    if (it == v2.end()) {
        cout << "容器中没有被4整除的元素" << endl;
    } else {
        cout << "第1个被4整数的元素: " << *it << endl;
    }
}

template<typename T>
class SumAdd {
public:
    T operator()(T &t1, T &t2)
    {
        return t1 + t2;
    }
};

/**
 * 二元谓词
 */
void test4()
{
    vector<int> v1, v2, v3;

    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);

    v3.resize(3);

    // v3必须有空间存储这些元素
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumAdd<int>());
    for (auto &item: v3) {
        cout << item << endl;
    }
}

bool MyCompare(const int &a, const int &b)
{
    return a < b;
}

void test5()
{
    vector<int> v1(10);
    for (int i = 0; i < 10; ++i) {
        v1[i] = rand() % 100;
    }
    // 遍历1
    cout << "for loop: ";
    for (auto &item: v1) {
        cout << item << " ";
    }
    cout << endl << "for_each: ";
    for_each(v1.begin(), v1.end(), ShowElement<int>());
    cout << endl << "for_each: ";
    sort(v1.begin(), v1.end(), MyCompare);
    for_each(v1.begin(), v1.end(), ShowElement<int>());
    cout << endl;
}

struct CompareNoCase {
    bool operator()(const string &s1, const string &s2)
    {
        string s1_, s2_;
        s1_.resize(s1.size());
        s2_.resize(s2.size());
        transform(s1.begin(), s1.end(), s1_.begin(), ::tolower);  // tolower 预定义函数对象
        transform(s2.begin(), s2.end(), s2_.begin(), ::tolower);
        // 为什么上面的tolower前面要加::， 由于文件开头使用命令空间std, 如果直接写tolower，就相当于std::tolower,
        // 但是我们用的不是这个模板函数，我们要用的是<ctype.h>中的 `extern int tolower (int __c) __THROW;` 函数，
        // 要想使用这个函数，1.可以去掉开头的using namespace std;声明，然后这里写tolower,2.也可以在这里写::tolower
        // ::a 表示 调用全局变量a或者全局函数a
        return s1_ < s2_; //  不区分大小写，从小到大排序
    }
};

/**
 * 二元谓词在set集合中的应用
 */
void test6()
{
    set<string> s1;
    s1.insert("bbb");
    s1.insert("ccc");
    s1.insert("aaa");
    auto it = s1.find("aAa");   // find函数默认是区分大小写的
    if (it == s1.end()) {
        cout << "s1没有找到aAa" << endl;
    } else {
        cout << "s1找到aAa" << endl;
    }

    set<string, CompareNoCase> s2;
    s2.insert("bbb");
    s2.insert("ccc");
    s2.insert("aaa");
    auto it2 = s2.find("aAa");   // find函数默认是区分大小写的
    if (it2 == s2.end()) {
        cout << "s2没有找到aAa" << endl;
    } else {
        cout << "s2找到aAa" << endl;
    }
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}
