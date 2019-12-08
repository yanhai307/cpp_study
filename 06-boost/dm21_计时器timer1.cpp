//
// Created by yanhai on 2019/12/8.
//

/**
 *  timer是一个很小的库，提供简单的时间度量和进度显示功能，也可以用于性能测试
 *  等计时任务。timer库包含三个组件：计时器类timer、progress_timer和
 *  进度指示类progress_display。
 */

#include <iostream>
#include <thread>
#include <boost/timer.hpp>
#include <boost/progress.hpp>
#include <chrono>

using namespace std;
using namespace boost;

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
 *  timer类可以测量时间的流逝，是一个小型的计时器，提供毫秒级别的计时精度和操作函数，
 *  他最大可表示的时间间隔约为596小时，它位于boost命名空间下。
 *  头文件 <boost/timer.hpp>
 */
void timer_test()
{
    timer t;    // 单位s
    cout << "最大精度：" << t.elapsed_max() << endl;
    cout << "最小精度：" << t.elapsed_min() << endl; // 1ms
    use_time(30);
    // 从对象定义，到此刻的时间
    cout << "流逝的时间：" << t.elapsed() << " s" << endl;

    t.restart();
//    sleep(2);
    use_time(1000);
    double elapsed = t.elapsed();
    cout << "流逝的时间：" << elapsed << " s" << endl;
}

/**
 * progress_timer类
 *  progress_timer继承自timer, 用法和timer类似，但它在析构时自动输出
 *  流逝的时间，如果要在程序中测量一段代码运行时间，可以将这段代码用
 *  { } 包含起来。
 *  头文件 <boost/progress.hpp>
 *
 *  打印的精度是2位，我们可以通过修改boost源码来修改精度。
 */
void progress_timer_test()
{
    {
        progress_timer pt;
//        std::this_thread::sleep_for(chrono::seconds(3));  // 使用sleep 打印显示消耗了0s，应该是被编译器优化了
        use_time(1234);
    }   // 析构时自动打印消耗的时间
}

int main()
{
    timer_test();
    progress_timer_test();
    return 0;
}
