//
// Created by YANHAI on 2019/9/13.
//

/*
    string_algo:
     - 修剪
     - 查找和替换
*/

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <boost/algorithm/string.hpp>
#include <boost/typeof/typeof.hpp>

using namespace std;
using namespace boost;

/*
    分割：
      string_algo提供了两个字符串分割算法，find_all和split把字符串分割，
      并将分割后的字符串复制到指定的容器中。
      
      注：要求是必须持有查找结果的复制或引用，因此容器元素类型是
          string或者iterator_range，容器是vector,list,deque等标准容器。
*/
void test1()
{
    // 分割字符串
    cout << "分割字符串" << endl;

    //vector<string> v;   // 标准容器存放结果
    //list<string> v;   // 标准容器存放结果
    deque<string> v;   // 标准容器存放结果
    string str = "aaBBccAAxxaa";
    ifind_all(v, str, "aa");
    //for (vector<string>::iterator it = v.begin(); it != v.end(); ++it)
    for (BOOST_AUTO(it, v.begin()); it != v.end(); ++it) {
        cout << *it << endl;
    }

    // 将查找结果的范围放在容器中
    vector<iterator_range<string::iterator> > v2;
    ifind_all(v2, str, "aa");
    for (BOOST_AUTO(it, v2.begin()); it != v2.end(); ++it) {
        cout << it->begin() - str.begin() << "," << it->end() - str.begin() << endl;
    }

    // 使用split分割
    string str2 = "AA**BB*CC-DD";
    list<string> l;
    split(l, str2, is_any_of("*-"));
    for (auto &e : l) {
        cout << e << endl;
    }
}

/*
    合并：
        合并算法join是分割算法split的逆运算，把存储在容器中的字符
        连接成一个新的字符串，并且可以指定连接的分隔符。join可以带一个if后缀
*/
void test2()
{
    cout << "合并字符串" << endl;

    deque<string> d;
    d.push_back("stu1");
    d.push_back("stu2");
    d.push_back("tea1");
    d.push_back("tea2");

    string str = join(d, "***");
    cout << str << endl;

    struct is_stu {
        bool operator()(const string &str)
        {
            return starts_with(str, "stu");
        }
    };

    string str2 = join_if(d, "***", is_stu());
    cout << str2 << endl;
}

int main()
{
    test1();
    test2();
    return 0;
}
