//
// Created by yanhai on 2019/12/8.
//

/**
 * 原始版本的timer已经废弃了，新版本建议使用cpu_timer。
 * cpu_timer计量程序经过的时间，用户执行时间，和系统执行时间。
 *
 * 头文件 <boost/timer/timer.hpp>
 * 命名空间 using namespace boost::timer;
 */

#include <iostream>
#include <boost/timer/timer.hpp>

using namespace std;
using namespace boost::timer;

static inline int use_time(int c)
{
    int count = 0;
    srand(time(NULL));
    for (int i = 0; i < 100000; ++i)
        for (int j = 0; j < c; ++j)
            count += rand();
    return count;
}

/**
 * cpu_timer类
 *  cpu_timer类和auto_cpu_timer类用于精确计时，在elapsed方法中，
 *  返回的不再是一个数字，而是一个struct cpu_timers结构体.
 *
 *  struct cpu_timers
 *  {
 *      nanosecond_type wall;   // 程序运行的真实时间
 *      nanosecond_type user;   // 用户cpu时间
 *      nanosecond_type system; // 系统cpu时间
 *      void clear() { wall = user = system = 0LL; }
 *  }
 *
 *  format方法格式化输出结果，默认的格式定义为：
 *   "%ws wall, %us user + %ss system = %ts CPU (%p%)\n"
 *
 *  含义：
 *   %w   timers.wall
 *   %u   timers.user
 *   %s   timers.system
 *   %t   timers.user + timers.system
 *   %p   The percentage of timers.wall represented by timers.user + timers.system
 */
void test1()
{
    cpu_timer t;    // 生成对象，即开始计时

    sleep(2);
    t.stop();

    // 默认 2.000149s wall, 0.000000s user + 0.000000s system = 0.000000s CPU (n/a%)
    string s = t.format();
    cout << s << endl;

    t.resume(); // 恢复执行, 在stop状态才起作用， 之前的时间没有清空， 不是重新开始计时
    use_time(1234);
    // 自定义格式
    string s1 = t.format(3, "消耗了 %w 秒");
    cout << s1 << endl;
    cout << t.format() << endl;
}

/**
 * auto_cpu_timer类
 *  auto_cpu_timer用法和cpu_timer类似，但它在析构时自动输出流逝的时间。
 *  如果要在程序中测量一段代码运行时间，可以将这段代码用 { }包含起来。
 */
void test2()
{
    {
        cout << "-----auto_cpu_timer----" << endl;
        auto_cpu_timer t2(5, "消耗时间 %w 秒");
        use_time(527);
    }
}

int main()
{
    test1();
    test2();
    return 0;
}
