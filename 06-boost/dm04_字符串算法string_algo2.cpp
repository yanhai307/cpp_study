//
// Created by YANHAI on 2019/9/13.
//

/*
    string_algo:
     - 修剪
     - 查找和替换
*/

#include <iostream>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

/*
    修剪
      string_algo提供3个修剪算法
        - trim       去掉左右两边的空格
        - trim_right 去掉右边的空格
        - trim_left  去掉左边的空格
      每个又有3中其他形式
        trim_copy
        trim_if
        trim_copy_if
*/
void test1()
{
    cout << "修剪" << endl;
    string str1 = "   Hello   ";
    cout << str1 << endl;
    trim(str1); // 修改原字符串，去掉左右两边的空格
    cout << str1 << endl;

    string str2 = "   Hello   ";
    cout << trim_copy(str2) << endl;    // 不修改原字符串
    cout << str2 << endl;

    struct is_xing {
        bool operator()(const char &c)
        {
            return c == '*';
        }
    };

    string str3 = "***Hello***";
    trim_if(str3, is_xing());   // 去掉左右的星号
    cout << str3 << endl;

    // 默认为is_space()
    // trim(x) === trim_if(x, is_space())
}

/*
    查找
       string_algo的查找算法提供与std::search()类似的功能，
       但接口不太一样，它不是返回一个迭代器（查找到的位置），
       而是 使用了boost.range库中的iterator_range返回查找到的区间。

       注：iterator_range 它包装了两个迭代器，可以用begine()和end()访问，
           相当于定义了一个容器的子区间，并可以像原容器一样使用。

       - find_first 查找子串第一次在被查找串中出现的位置
       - find_last  查找子串最后一次在被查找串中出现的位置
       - find_nth   查找子串第n次在被查找串中出现的位置
       - find_head  返回字符串头部n个字符串的位置
       - find_tail  返回字符串尾部n个字符串的位置

       带i前缀表示忽略大小写
*/
void test2()
{
    cout << "查找" << endl;
    string str1 = "Hello, hello,hello,Boost!!!";
    iterator_range<string::iterator> rge;
    rge = find_first(str1, "hello");    // 查找第1个hello
    cout << rge << endl;
    cout << rge.begin() - str1.begin() << "," << rge.end() - str1.begin() << endl;

    rge = ifind_first(str1, "hello");   // 不区分大小写
    cout << rge << endl;
    cout << rge.begin() - str1.begin() << "," << rge.end() - str1.begin() << endl;

    rge = find_last(str1, "hello"); // 查找最后一个hello
    cout << rge << endl;
    cout << rge.begin() - str1.begin() << "," << rge.end() - str1.begin() << endl;

    rge = find_nth(str1, "o", 4); // 查找第5个o，从0开始
    cout << rge << endl;
    cout << rge.begin() - str1.begin() << "," << rge.end() - str1.begin() << endl;

    rge = find_head(str1, 4); // 查找前4个字符
    cout << rge << endl;
    cout << rge.begin() - str1.begin() << "," << rge.end() - str1.begin() << endl;
}

/*
    删除/替换
        replace/erase_first 替换/删除第一次出现在被查找串中的子串
        replace/erase_last  替换/删除最后一次出现在被查找串中的子串
        replace/erase_nth   替换/删除第n次出现在被查找串中的子串
        replace/erase_all   替换/删除所有的子串
        
        replace/erase_head  替换/删除头部几个字符
        replace/erase_tail  替换/删除尾部几个字符

        前4组每个都有前缀i(忽略大小写)，后缀_copy(不修改原字符串)，4中版本
        后2组只有后缀_copy的两个版本
*/
void test3()
{
    cout << "替换、删除" << endl;
    string str1 = "Hello, hello,hello,Boost!!!";
    ireplace_first(str1, "Hello", "XXX");   //替换第1个， 不区分大小写，
    cout << str1 << endl;

    replace_all(str1, "hello", "YYY");  // 替换全部
    cout << str1 << endl;

    erase_last(str1, "YYY");
    cout << str1 << endl;

    erase_tail(str1, 3);
    cout << str1 << endl;
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}
