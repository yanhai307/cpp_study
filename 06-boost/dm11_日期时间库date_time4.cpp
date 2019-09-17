//
// Created by YANHAI on 2019/9/15.
//

#include <iostream>

using namespace std;

// 日期
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;

// 时间
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::posix_time;

#ifdef _WIN32
#pragma comment(lib, "libboost_date_time-vc142-mt-gd-x32-1_71.lib")
#endif

/*
    time_period类
        类似日期区间类date_period， time_period表示时间轴上一个左闭右开区间
        端点是两个ptime对象
*/
void test1()
{
    // 开始时间
    ptime p1 = time_from_string("2000-01-01 00:00:01");
    // 结束时间
    ptime p2(date(2000, 1, 2));
    // 产生一个时间范围
    time_period tp(p1, p2); // p2 > p1才可以
    cout << tp << endl;     // [2000-Jan-01 00:00:01/2000-Jan-01 23:59:59.999999]

    // 时间范围的长度
    time_duration td = tp.length();
    cout << td << endl;     // 23:59:59

    // 时间范围向后平移
    tp.shift(seconds(9));   // 向后平移9秒
    cout << tp << endl;     // [2000-Jan-01 00:00:10/2000-Jan-02 00:00:08.999999]

    // 时间范围向两边扩大1小时
    tp.expand(hours(1));
    cout << tp << endl;     // [1999-Dec-31 23:00:10/2000-Jan-02 01:00:08.999999]

    // 某个时间点是否在这个范围内
    ptime p3 = time_from_string("2000-01-01 00:00:01");
    cout << tp.contains(p3) << endl;
}

/*
    时间迭代器
        类似日期迭代器， 时间也有迭代器，但是只有一个time_iterator
        可以用++ --操作符连续访问时间。
*/
void test2()
{
    ptime p1 = time_from_string("2000-01-01 00:00:01");
    time_iterator it(p1, seconds(10));  // 以10秒为步长
    for (int i = 0; i < 3; ++i) ++it;   // 向后移动30s， 迭代器的移动不会影响p1的值
    cout << *it << endl;    // 2000-Jan-01 00:00:31

    time_iterator it2(p1, hours(24));  // 以24小时为步长
    ++it2;   // 向后移动24小时
    cout << *it2 << endl;    // 2000-Jan-02 00:00:01
}

/*
    日期时间的格式化
        date_time库默认的日期时间格式简单标准且是英文，
        例如2000-Jan-02 00:00:01，看起来不符合日常习惯，
        date_time库提供专门的格式化对象date_facet，time_facet等
        来搭配IO流，定制日期时间的显示。
*/
void test3()
{
    // 日期时间格式化
    date d1 = day_clock::local_day();
    date_facet *pdf = new date_facet("%Y年 %m月 %d日");
    cout.imbue(locale(cout.getloc(), pdf));     // 指定输出流的语言环境
    cout << d1 << endl;     // 2019年 09月 15日

    ptime p1 = microsec_clock::local_time();
    time_facet *ptf = new time_facet("%Y年 %m月 %d日 %H:%M:%S %F");
    cout.imbue(locale(cout.getloc(), ptf));     // 指定输出流的语言环境
    cout << p1 << endl;     // 2019年 09月 15日 13:39:26 .632838
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}
