//
// Created by yanhai on 2019/8/17.
//

// 未完待续...
// 看到了第5张第7节

#include <iostream>
#include "mystring.h"

using namespace std;

int main()
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
    return 0;
}