//
// Created by YANHAI on 2019/9/14.
//

/*
    tokenizer库是一个专门用于分词(token)的字符串处理库，
    可以方便的把一个字符串 分解成若干个单词，它比string_algo
    的split更强大，需要包含头文件<boost/tokenizer.hpp>

    tokenizer类接受三个模板类型参数：
    template<
        class TokenizerFunc = char_delimiters_separator<char>,
        class Iterator = std::string::const_iterator,
        class Type = std::string
    >
    这三个模板类型都提供了默认值：
    1.TokenizerFunc 分词函数对象，默认空格或标点符号
    2.字符序列的迭代器类型
    3.分词结果的类型
*/

#include <iostream>

using namespace std;

#include <boost/typeof/typeof.hpp>
#include <boost/tokenizer.hpp>

using namespace boost;

void test1()
{
    cout << "---char_delimiters_separator分词" << endl;
    //string str = "My name is Mr Yan!";
    string str = "My!name,is?Mr.Yan!";
    tokenizer<> tok(str);

    for (BOOST_AUTO(it, tok.begin()); it != tok.end(); ++it) {
        cout << *it << endl;
    }
}

/*
    tokenizer库分词对象
    提供了预定义好的4个分词对象，分别是：
     - char_delimiters_separator  默认使用的，使用标点符号分词，但已废弃
     - char_separator 它支持一个字符集合作为分隔符，默认的行为与char_delimiters_separator类似
     - escaped_list_separator 用csv格式（逗号分隔）的分词
     - offset_separator 使用偏移量来分词，在分解平文件格式的字符串时有用。

   char_separator使用了
*/
void test2()
{
    cout << "---char_separator分词" << endl;
    string str = "My<name>>>is< Mr<Yan!";
    char_separator<char> sep(">",/*分隔符不保留*/
                             "<"/*分隔符保留*/,
                             keep_empty_tokens/*是否保留 "" 的分词结果*/);
    tokenizer<char_separator<char> > tok(str, sep);
    for (BOOST_AUTO(it, tok.begin()); it != tok.end(); ++it) {
        cout << *it << endl;
    }
}

/*
    escaped_list_separator
        escaped_list_separator是专门处理CSV格式（Comma Split Value, 逗号分隔值）的分词对象
        它的构造函数声明是：
        escaped_list_separator(char e='\\', char c=',', char q='\"');

        escaped_list_separator的构造函数参数一般使用默认值，含义如下：
        1.e指定了字符串中转移字符， 默认是\
        2.c是分割符，默认是逗号
        3.q是引号字符，默认是"
*/
void test3()
{
    cout << "---escaped_list_separator分词" << endl;
    string str = "My,name,is,Mr,\\\"Yan!\\\"";
    escaped_list_separator<char> sep;   //默认以,分词
    tokenizer<escaped_list_separator<char> > tok(str, sep);

    for (BOOST_AUTO(it, tok.begin()); it != tok.end(); ++it) {
        cout << *it << endl;
    }
}

/*
    offset_separator
        offset_separator分词函数对象不基于查找分割符，而是使用偏移量的概念，
        在处理某些不使用分隔符而使用固定字段宽度的文本时很有用，构造函数声明：

        offset_separator(Iter begin, Iter end, bool wrap_offsets = true, bool return_partial_last=true);

        1-2 begin和end，指定分词用的序列，序列的每个元素指定分词宽度
        3 wrap_offsets决定是否在偏移量用完后继续分词,默认true
        4 return_partial_last决定是否返回分词不足的部分,默认true
*/
void test4()
{
    cout << "---offset_separator分词" << endl;
    string str = "11222333344444555555";
    int arr[3] = {2, 3, 4};
    offset_separator sep(arr, arr + 3, false/* 决定是否在偏移量用完后继续分词 */);
    tokenizer<offset_separator> tok(str, sep);

    for (BOOST_AUTO(it, tok.begin()); it != tok.end(); ++it) {
        cout << *it << endl;
    }

    string str2 = "112223333";
    int arr2[3] = {2, 3, 10};
    offset_separator sep2(arr2, arr2 + 3, false, false/*是否返回分词不足的部分*/);
    tokenizer<offset_separator> tok2(str2, sep2);

    for (BOOST_AUTO(it, tok2.begin()); it != tok2.end(); ++it) {
        cout << *it << endl;
    }
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}
