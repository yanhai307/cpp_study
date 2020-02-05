//
// Created by yanhai on 2020/1/20.
//

/**
 * boost.tribool类似C++内建的bool类型，但基于三态的布尔逻辑：true（真） false（假） indeterminate（未知，不确定）
 * tribool位于名字空间 boost::logic, 但是为了方便使用被using语句引入了boost名字空间， 头文件<boost/logic/tribool.hpp>
 *
 * 不确定状态indeterminate是一个特殊的tribool值，它与bool值true、false的运算遵循三态布尔逻辑：
 * 1. 任何与indeterminate的比较操作结果都是indeterminate；
 * 2. 与indeterminate的逻辑或运算符(||)只有与true结果为true，其他结果都为indeterminate；
 * 3. 与indeterminate的逻辑与操作符(&&)只有与false运算结果为false,其他均为indeterminate；
 * 4. indeterminate的逻辑非操作(!)结果为indeterminate。
 *
 * 自由函数indeterminate()可以判断一个tribool是否处于不确定状态。
 */

#include <iostream>
#include <cassert>
#include <boost/logic/tribool.hpp>
#include <boost/logic/tribool_io.hpp>

using namespace std;
using namespace boost;

void func1()
{
    tribool tb(true);   // 值为true的tribool
    tribool tb2(!tb);                   // 值为false

    if (tb) {   // tb == true
        cout << "true" << endl;
    }

    tb2 = indeterminate;    // t2为不确定状态
    assert(indeterminate(tb2)); // 用indeterminate检测状态

    if (tb2 == indeterminate) {   // 与indeterminate值比较无意义
        cout << "indeterminate" << endl;    // 这句不会被执行
    }

    if (indeterminate(tb2)) {   // 用indeterminate函数检测状态
        cout << "indeterminate" << endl;    // 输出 indeterminate
    }

    cout << (tb2 || true) << endl;  // 逻辑或运算，输出true
    cout << (tb2 && false) << endl; // 逻辑与运算，输出false

    // 当tribool为不确定状态时，它既不是true也不是false，使用它进行条件判断永远都不会成立，
    // 判断不确定状态必须要使用indeterminate()函数
    if (tb2) {  // 永远不成立
        cout << "never reach here" << endl;
    }
    if (!tb2) { // 永远不成立
        cout << "never reach here" << endl;
    }
}

/**
 * 可以在全局内使用宏BOOST_TRIBOOL_THIRD_STATE就可以为第三态更名
 */

BOOST_TRIBOOL_THIRD_STATE(unknown)

void func2()
{
    tribool tb(unknown);    // 可以作为不确定值
    assert(unknown(tb));    // 可以作为检测函数
    assert(unknown(tb) || false);
}

/**
 * 如果把BOOST_TRIBOOL_THIRD_STATE用在一个名字空间里，那么新的第三态名字将成为名字空间的一个成员，
 * 使用时需要加上名字空间限定，例如
 */

namespace tmp_ns {
BOOST_TRIBOOL_THIRD_STATE(unknown)
}

void func3()
{
    tribool tb(tmp_ns::unknown);
    assert(tmp_ns::unknown(tb));
}

/**
 * 输入/输出
 * tribool可以像bool一样进行流操作，需要包含头文件 <boost/logic/tribool_io.hpp>
 * 就可以通过 << >> 操作符向 cout cin等流对象输入/输出
 * true  false  indeterminate 分别对应整数 0 1 2
 */
void func4()
{
    tribool tb1(true), tb2(false), tb3(indeterminate);
    cout << tb1 << ","
         << tb2 << ","
         << tb3 << endl;
}

#include <boost/optional.hpp>

void func5()
{
    /**
     * optional<bool> 在功能上有点类似tribool, 一个未初始化的optional<bool>同样可以表示不确定的bool值
     */
    optional<bool> b;
    if (!b) {   // b未初始化，既不是true也不是false
        cout << "indeterminate" << endl;
    }
    b = false;
    if (b) {    // b有值 false
        cout << "b=" << *b << endl;
    }

    /**
     * optional<bool>的语义是未初始化的bool，是无意义的值，而tribool的indeterminate是已经初始化的有意义值，它表示bool值不确定。
     * 此外，两者的使用方法也存在差别。optional<bool>需要使用类似指针的方式访问容器内的bool值，而tribool可以如普通的bool类型一样直接使用，
     * 并且支持各种逻辑运算。
     * 由于optional<bool>支持bool转换，用于检测optional是否已经初始化，所以在bool语境下如果不注意optional这个特性很容易导致意外的错误。
     * 例如，下面的代码本意是想使用optional内的bool值作为if语句的判断条件，但实际上条件判断的是optional未初始化。
     */
    optional<bool> b2(false);
    if (!b) {
        cout << "false" << endl;
    }
    // 正确的写法是
    if (b && !*b) {    // b已经初始化，并且值为false
        cout << "false" << endl;
    }
    /**
     * 选择optional<bool>还是tribool需要由具体的业务逻辑决定，如果返回值可能是无效的（不存在有效返回值），那么就是optional<bool>;
     * 如果返回值总是确定的，但可能无法确定其意义，那么就用tribool.
     */
}

int main()
{
    func1();
    func2();
    func3();
    func4();
    return 0;
}
