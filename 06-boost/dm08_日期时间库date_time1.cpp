//
// Created by YANHAI on 2019/9/15.
//

/*
    date_time库
        头文件 <boost/date_time/gregorian/gregorian.hpp>
    名字空间
        using namespace boost::gregorian;
    静态库
        #pragma comment(lib, "libboost_date_time-vc142-mt-gd-x32-1_71.lib")
*/

#include <iostream>

using namespace std;

#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;

#ifdef _WIN32
#pragma comment(lib, "libboost_date_time-vc142-mt-gd-x32-1_71.lib")
#endif

/*
    date类是date_time库处理日期的核心类，以天为单位表示时间点概念。
    date支持比较操作和输入输出，我们可以完全把它当成一个像int、string那样的基本类型来使用。
*/
void test1()
{
    // date类
    cout << "---date类----" << endl;

    date d1(2019, 1, 1);
    date d2 = from_string("2019-02-02");
    date d3 = from_string("2019/03/03");
    date d4 = from_undelimited_string("20190404");  // 无界定的字符串
    date d5(min_date_time); // 特殊时间值 1400-01-01
    date d6(max_date_time); // 特殊时间值 9999-12-31

    // 输出日期
    cout << d1.year() << "年" << d1.month() << "月" << d1.day() << endl;      // 2019年Jan月1
    cout << d1.year() << "年" << (int) d1.month() << "月" << d1.day() << endl; // 2019年1月1
    cout << "to_simple_string: " << to_simple_string(d2) << endl;               // 2019-Feb-02
    cout << "to_iso_string: " << to_iso_string(d3) << endl;                     // 20190303
    cout << "to_iso_extended_string: " << to_iso_extended_string(d4) << endl;   // 2019-04-04
    cout << "min_date_time: " << to_iso_extended_string(d5) << endl;            // 1400-01-01
    cout << "max_date_time: " << to_iso_extended_string(d6) << endl;            // 9999-12-31

    // 获取今天的日期
    date today = day_clock::local_day();
    cout << today.year() << "年" << today.month() << "月" << today.day() << " 星期" << today.day_of_week()
         << " 一年中的第几天" << today.day_of_year()
         << " 一年中的第几周" << today.week_number()
         << " 这个月的结束日期" << today.end_of_month() << endl;
}

/*
    date_duration表示日期长度，是以天为单位的时长，值可以是任意的整数，可正可负。date_time库为data_duration定义了
    一个常用的typedef:days，此外还提供了months years weeks等另外三个时长类，分别用来表示月，年和星期。
*/
void test2()
{
    // date_duration类, 时间长度（最小单位是 天）
    cout << "---date_duration类----" << endl;

    days d1(10);
    days d2(-5);
    date_duration du1 = d1 + d2;
    cout << "10天-5天 = " << du1.days() << endl;  // 5

    weeks w1(1);
    cout << "1周的天数 = " << w1.days() << endl;  // 7
    date_duration du2 = w1 + d1;
    cout << "1周+10天 = " << du2.days() << endl;  // 17

    months m1(1);   // 一个月无法知道是多少天，无法和天数计算
    cout << "1个月 " << m1.number_of_months() << endl;

    years y1(1);    // 一年无法知道是多少天，并且无法和天数计算
    cout << "1年: " << y1.number_of_years() << endl;

    months m2 = y1 + months(0);
    cout << "1年有多少月 " << m2.number_of_months() << endl;

    // 日期 + 日期长度= 新日期
    date d3(2015, 2, 28);
    cout << "往前推10天是几月几日 " << to_iso_extended_string(d3 + days(-10)) << endl; // 2018-02-18
    cout << "往后推2周是几月几日 " << to_iso_extended_string(d3 + weeks(2)) << endl;   // 2018-03-14
    cout << "往后推1月是几月几日 " << to_iso_extended_string(d3 + months(1)) << endl;  // 2018-03-31
    cout << "往后推1年是几月几日 " << to_iso_extended_string(d3 + years(1)) << endl;   // 2019-02-29
}

int main()
{
    test1();
    test2();
    return 0;
}
