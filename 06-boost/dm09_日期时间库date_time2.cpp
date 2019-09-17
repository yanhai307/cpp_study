//
// Created by YANHAI on 2019/9/15.
//

#include <iostream>

using namespace std;

#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;

#ifdef _WIN32
#pragma comment(lib, "libboost_date_time-vc142-mt-gd-x32-1_71.lib")
#endif

/*
    date_period类用来表示日期范围的概念，
    它是时间轴上一个左闭右开区间，端点是两个date对象
*/
void test1()
{
    date d1(2000, 1, 1);
    date d2(2000, 2, 1);

    // 构造一个日期范围
    date_period dp1(d1, d2);    // 两个日期确定一个范围
    cout << dp1 << endl;    // 左闭右开，不包含2000年2月1号
    cout << dp1.length() << endl;   // 31

    // 日期范围平移
    dp1.shift(date_duration(10));   // 向后移动10天
    cout << dp1 << endl;

    // 日期向两边延伸
    dp1.expand(date_duration(1));   // 向两边移动一天
    cout << dp1 << endl;

    // 检测某个日期是否在这个日期范围里面
    cout << dp1.contains(date(2000, 1, 20)) << endl;
    cout << dp1.contains(date(2000, 2, 20)) << endl;
}

/*
    日期迭代器
        日期迭代器可以用++、--操作符连续访问日期，这些迭代器包括：
           day_iterator, week_iterator, month_iterator和year_iterator.
        注意：它们并不符合标准迭代器的定义，没有difference_type pointer  reference等
              内部类型定义，不能使用std::advance()或者+=来前进或者后退。
*/
void test2()
{
    // 日期迭代器，不会影响原日期
    date d1(2000, 1, 1);
    day_iterator it1(d1);   // 默认步长为1天
    ++it1;                  // 向后移动1天
    cout << *it1 << endl;

    day_iterator it2(d1, 10);   // 步长为10天
    ++it2;                      // 向后移动10天
    cout << *it2 << endl;

    week_iterator it3(d1, 2);   // 步长为2周
    --it3;                      // 向前移动2周
    cout << *it3 << endl;

    month_iterator it4(d1, 1);  // 步长为1月
    --it4;                      // 向前移动1月
    cout << *it4 << endl;

    year_iterator it5(d1, 2);   // 步长为2年
    ++it5;                      // 向后移动2年
    cout << *it5 << endl;
}

int main()
{
    test1();
    test2();
    return 0;
}
