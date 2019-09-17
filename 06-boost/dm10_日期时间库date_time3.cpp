//
// Created by YANHAI on 2019/9/15.
//

/*
    date_time库它包含两个组件，处理日期的组件gregorian和处理时间的组件posix_time。
    date类用于创建日期，ptime类则用于定义一个时间。
*/

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
   ptime类
      ptime是date_time库处理时间的核心类，它使用64位（微妙）或96位（纳秒）的整数在内部存储时间数据。
      头文件 <boost/date_time/posix_time/posix_time.hpp>
      名字空间 using namespace boost::posix_time;
*/
void test1()
{
    cout << "----ptime类----" << endl;

    ptime t1(date(2000, 1, 1));
    cout << t1 << endl;

    ptime t2 = time_from_string("2000-01-01 10:00:02");
    cout << t2 << endl;

    ptime t3 = from_iso_string("20000101T100002");  // 用字母T分割日期和时间
    cout << t3 << endl;

    ptime t4 = second_clock::local_time();  // 秒精度
    cout << t4 << endl;

    ptime t5 = microsec_clock::local_time();  // 微秒精度
    cout << t5 << endl;

    ptime t6(min_date_time);    // 特殊值
    cout << t6 << endl;

    ptime t7(max_date_time);    // 特殊值
    cout << t7 << endl;
}

/*
    time_duration类
        类似日期长度类date_duration有days、weeks months years这些常用类。
        time_duration也有几个子类： hours minutes  seconds  millisec  microsec  nanosec
         它们都支持输入输出 比较操作 加减乘除运算。
*/
void test2()
{
    // 时间长度，类似日期长度date_duration
    cout << "----time_duration类----" << endl;

    // 1小时10分钟20秒1毫秒
    time_duration td1(1, 10, 20, 1000); // 最后一个单位是微秒
    cout << td1 << endl;    // 01:10:20.001000

    // 会自动进位
    time_duration td2(1, 60, 60, 1000 * 1000 * 6 + 1000);
    cout << td2 << endl;    // 02:01:06.001000

    // 使用字符串构造时长， 1小时10分钟20秒1微秒
    time_duration td3 = duration_from_string("1:10:20:000001");
    cout << td3 << endl;

    // hours
    hours h1(1);
    cout << h1.total_seconds() << "秒 "
         << h1.total_milliseconds() << "毫秒 "
         << h1.total_microseconds() << "微秒 "
         << h1.total_nanoseconds() << "纳秒" << endl;

    // 利用时间长度构造
    time_duration td4 = hours(1) + minutes(10) + seconds(20) + microsec(30) + microseconds(10);
    cout << td4 << endl;
}

int main()
{
    test1();
    test2();
    return 0;
}
