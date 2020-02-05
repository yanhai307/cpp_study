//
// Created by yanhai on 2020/1/20.
//

/**
 * optional 使用 “容器” 语义，包装了“可能产生无效值”的对象，实现了未初始化的概念，为这种“无效值”的情形提供了一个更好的解决方案，
 * 它已经被收入c++17标准。
 *
 * optional位于名字空间boost, 需要包含头文件 <boost/optional.hpp>
 */

#include <iostream>
#include <string>
#include <vector>
#include <boost/optional.hpp>
#include <cmath>

using namespace std;
using namespace boost;

// optional 基本用法
void func1()
{
    optional<int> op0;      // 一个未初始化的optional对象
    optional<int> op1(none);// 同上，使用none赋予未初始化值

    assert(!op0);           // bool测试
    assert(op0 == op1);     // 比较两个optional对象

    assert(op1.value_or(253) == 253);   // 获取默认值
    cout << op1.value_or_eval([]() { return 874; }) << endl;    // 使用函数对象

    optional<string> ops("test");   // 初始化为字符串test
    cout << *ops << endl;           // 用解引用操作符获取值

    ops.emplace("monado", 3);   // 就地创建一个字符串，没有拷贝代价
    assert(*ops == "mon");          // 只使用了前3个字符

    vector<int> v(10);
    optional<vector<int> &> opv(v);  // 容纳一个容器的引用
    assert(opv);    // bool转型

    opv->push_back(5);      // 使用箭头操作符操纵容器
    assert(opv->size() == 11);

    opv = none; // 置为未初始化状态
    assert(!opv);   // 此时为无效值
}

// 使用optional作为函数返回值
optional<double> calc(int x)    // 计算倒数
{
    return optional<double>(x != 0, 1.0 / x);    // 条件构造函数
}

optional<double> sqrt_op(double x)
{
    return optional<double>(x >= 0, sqrt(x));
}

void func2()
{
    optional<double> d = calc(10);
    if (d) {
        cout << *d << endl;
    }

    d = sqrt_op(-10);
    if (!d) {
        cout << "no result" << endl;
    }
}

/**
 * optional 提供了一个类似 make_pair()  make_shared() 的工厂函数 make_optional() 可以根据参数类型自动推导optional的类型，
 * 用来辅助创建optional对象。
 * 但是make_optional() 无法推导出引用类型的optional对象，如果需要一个optional<T &> 的对象就不能使用make_optional()函数。
 * make_optional()也不支持emplace的用法，可能存在值的拷贝代价。
 */
void func3()
{
    auto x = make_optional(5); // 使用auto关键字自动推导类型
    assert(*x == 5);

    auto y = make_optional<double>((*x > 10), 1.0); // 模板参数明确类型
    assert(!y);
}

int main()
{
    func1();
    func2();
    return 0;
}
