//
// Created by yanhai on 2019/8/17.
//

// 未完待续...
// 看到了第5张第7节

#include <iostream>
#include <cstring>
#include "mystring.h"

using namespace std;


void test1()
{
    MyString s1;
    MyString s2("s2");
    MyString s2_2 = nullptr;
    MyString s3 = s2;
    MyString s4 = "s44444444";

    cout << s3 << endl;

    s3 = s1 = s4;
    cout << s3 << endl;

    s2 = s3 = "s2s3";
    cout << s2 << endl;

    s2[1] = '4';
    cout << s2[1] << endl;
}


void test2()
{
    MyString s1;
    MyString s2("s2");
    const char *p = "pppp";

    // 这里p是const char *类型，如果不实现 operator==(const char *)函数，则会调用operator==(const MyString &)函数，
    // p将先产生（隐式转换）一个MyString类型的匿名对象，参与==比较后，匿名对象将会销毁。
    if (s2 == p)
        cout << "s2 == p" << endl;
    else
        cout << "s2 != p" << endl;

    if (s1 == s2)
        cout << "s1 == s2" << endl;
    else
        cout << "s1 != s2" << endl;

    if (s1 != s2)
        cout << "s1 != s2" << endl;
    else
        cout << "s1 == s2" << endl;
}

void test3()
{
    MyString s1 = "aaa";
    MyString s2("bbb");
    const char *p = "ppp";

    if (s2 > p)
        cout << "s2 > p" << endl;
    else
        cout << "s2 <= p" << endl;

    if (s1 < s2)
        cout << "s1 < s2" << endl;
    else
        cout << "s1 >= s2" << endl;
}

void test4()
{
    MyString s1(100);
    strcpy(s1.c_str(), "hello world!");
    cout << s1 << endl;

    MyString s2(20);
    s2 << "hello world!" << " hello c++!" << "hello.";
    cout << s2 << endl; // 只能打印出  hello world! hello c   因为s2仅20个字节大小

    MyString s3(100);
    cout << "输入字符串（回车结束）" << endl;
    cin >> s3;
    cout << s3 << endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}
