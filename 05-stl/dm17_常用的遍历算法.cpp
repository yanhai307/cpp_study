//
// Created by yanhai on 2020/2/15.
//

/**
 * 常用的遍历算法
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

template<typename T>
void print(T &t)
{
    for (auto &item: t) {
        cout << item << " ";
    }
    cout << endl;
}

template<typename T>
void showElement(T &t)
{
    cout << t << " ";
}

template<typename T>
T showElement2(T t)
{
    cout << t << " ";
    return t;
}

template<typename T>
class CMyShow {
public:
    CMyShow()
    {
        num = 0;
    }

    void operator()(T &t)
    {
        num++;
        cout << t << " ";
    }

    void printNum()
    {
        cout << "num: " << num << endl;
    }

private:
    int num;
};

/**
 * for_each()
 *  - 用指定函数依次对指定范围内所有元素进行迭代访问。该函数可以修改序列中的元素。
 *  - 注意第3个参数：函数对象做函数参数，函数对象做返回值
 */
void test1()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    print(v1);

    for_each(v1.begin(), v1.end(), showElement<int>);
    cout << endl;

    CMyShow<int> my1;
    auto my2 = for_each(v1.begin(), v1.end(), my1);    // for_each第3个参数和返回值是两个不同的对象，第3个参数是按值传递的，不是引用
    cout << endl;
    my1.printNum();
    my2.printNum();
}

template<typename T>
T increase(const T &t)
{
    return t + 100;
}

/**
 * transform()
 *  - 与for_each 类似，遍历所有元素
 *  - transform 有两种形式：
 *     - transform(b1, e1, b2, op)
 *     - transform(b1, e1, b2, b3, op)
 *  - 作用：
 *     - 可以把一个容器的元素，通过op，变换到另一个容器中（也可以是同一个容器中）
 *     - 也可以把两个容器的元素，通过op，变换到另一个容器中（也可以是源容器中的两个任意一个）
 *  - 注意：
 *     - 如果目标与源相同，transform()就和for_each()一样
 *     - 如果想以某值替换符合规则的元素，应使用replace()算法，replace是transform的一个特例，运行速度要快点
 */
void test2()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    print(v1);

    // 使用回调函数
    transform(v1.begin(), v1.end(), v1.begin(), increase<int>);
    print(v1);

    // 使用预定义函数对象
    transform(v1.begin(), v1.end(), v1.begin(), negate<int>());
    print(v1);

    // 使用函数适配器 和预定义函数对象
    list<int> l1;
    l1.resize(v1.size());
    transform(v1.begin(), v1.end(), l1.begin(), bind2nd(multiplies<int>(), 10));
    print(l1);

    // transform也可以把运算结果 直接输出到屏幕
    transform(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "), negate<int>());
    cout << endl;
}

/**
 * for_each 与 transform 的不同之处
 *  - for_each的函数对象可以用在transform上吗？
 */
void test3()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    auto v2 = v1;

    for_each(v1.begin(), v1.end(), showElement<int>);
    cout << endl;

    /**
     * 编译错误
     * error: assigning to 'int' from incompatible type 'void'
     *   *__result = __op(*__first);
     *
     * transform源代码
     *
     * template <class _InputIterator, class _OutputIterator, class _UnaryOperation>
     * inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX17
     * _OutputIterator
     * transform(_InputIterator __first, _InputIterator __last, _OutputIterator __result, _UnaryOperation __op)
     * {
     *     for (; __first != __last; ++__first, (void) ++__result)
     *         *__result = __op(*__first);      // 解释了 为什么要有返回值
     *     return __result;
     * }
     */
//    transform(v2.begin(), v2.end(), v2.begin(), showElement<int>);
    transform(v2.begin(), v2.end(), v2.begin(), showElement2<int>);
    cout << endl;

    /**
     * 结论：
     *   - for_each()   速度快，不灵活
     *   - transform()  速度慢，非常灵活
     *  一把情况下， for_each所使用的函数对象，参数是引用，没有返回值
     *             transform所使用的函数对象，参数一般不使用引用，必须有返回值（返回值也不使用引用）
     */
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}
