//
// Created by YANHAI on 2019/9/13.
//

/*
   格式化format
        -- boost/format.hpp
*/

#include <iostream>
#include <boost/format.hpp>

using namespace std;

int main()
{
    using boost::format;

    // 使用1
    // %N% 表示显示第N个参数
    format fmt("%1% ,  %2%!!!");  // 先定义对象
    fmt % 123;
    fmt % "hello";
    cout << fmt << endl;

    // 使用2
    // 顺序不必一致， 且可以重用
    format fmt2("%2%,  %1%,  %2%");
    fmt2 % 1.23456;
    fmt2 % 12;
    cout << fmt2 << endl;

    // 使用3
    // format对象可以重复使用
    format fmt3("%2%,  %1%,  %2%");
    fmt3 % 1.23456;
    fmt3 % 12;
    cout << fmt3 << endl;

    fmt3 % "hello";
    fmt3 % 'C';
    cout << fmt3 << endl;

    // 使用4
    // 链式使用，使用匿名对象
    cout << format("===%1%---- %2%===") % "hello" % 123.456 << endl;
    cout << (format("===%1%---- %2%===") % "hello") % 123.456 << endl;

    // 使用5
    // 可以使用printf中的格式符
    cout << format("%d,  %c,  %f, %s") % 666 % 'A' % 1.23 % "boost" << endl;

    // 使用6
    // printf指示符里使用N$指定使用第几个参数
    cout << format("%2$d --- %1$s") % "hello" % 234 << endl;

    // 使用7
    // 可直接转成字符串, 替代 sprintf
    format fmt7 = format("%2%, --%1%=!!") % "World" % "Hello";
    string str = fmt7.str();
    cout << str << endl;

    return 0;
}
