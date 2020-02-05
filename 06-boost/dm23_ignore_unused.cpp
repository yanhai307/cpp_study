//
// Created by yanhai on 2020/1/20.
//

/**
 * 编码中有时候会出现暂时用不到但又必须保留的变量，gcc等编译器会对此发出警告，
 * 使用 '-Wunused' 可以消除这些告警，不过这有可能会导致潜在的隐患，古老的办法是 使用 "(void)var"的形式来 “使用”一下变量，但这种方法含义不明确，
 * 不利于维护；
 * boost库中的ignore_unused组件就可以解决这个问题，
 * ignore_unused位于名字空间 boost,需要包含头文件 <boost/core/ignore_unused.hpp>
 */

#include <boost/core/ignore_unused.hpp>

using namespace boost;

// gcc编译代码时，可能会爆出警告, unused variable 'i', unused parameter 'x'
int func1(int x, int y)
{
    int i;
    return y;
}

// 使用boost::ignore_unused消除告警
int func2(int x, int y)
{
    int i;
    ignore_unused(i, x);
    return y;
}

// ignore_unused 不仅可以适用于未使用的变量，也可以用于未使用的局部类型定义
void func3()
{
    typedef int result_type;
    ignore_unused<result_type>();
}

int main()
{
    func1(1, 2);
    func2(10, 20);
    func3();
    return 0;
}
