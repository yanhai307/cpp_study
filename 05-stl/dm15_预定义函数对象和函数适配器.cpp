//
// Created by YANHAI on 2020/2/14.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void test1()
{
    plus<int> intAdd;
    int x = 10, y = 20;
    int z = intAdd(x, y);   // x + y
    cout << "z: " << z << endl;

    plus<string> stringAdd;
    string s1 = "aaa", s2 = "bbb";
    string s3 = stringAdd(s1, s2);
    cout << "s3: " << s3 << endl;

    vector<string> v1;
    v1.push_back("bbb");
    v1.push_back("aaa");
    v1.push_back("ccc");
    v1.push_back("ccc");
    v1.push_back("zzz");
    v1.push_back("ccc");
    sort(v1.begin(), v1.end(), greater<string>());
    for (auto &item: v1) {
        cout << item << endl;
    }

    // 求ccc出现的次数，
    // 首先，equal_to需要两个参数，来判断这两个参数是否相同，
    // 但是count_if只会给函数对象传递一个参数，我们想把sc作为equal_to的第2个参数，那么要怎么传入呢
    // 这时就需要 bind2nd适配器了。
    // bind2nd：把预定义函数对象和第2个参数进行绑定
    string sc = "ccc";
    int num = count_if(v1.begin(), v1.end(), bind2nd(equal_to<string>(), sc));
    cout << "ccc出现的次数: " << num << endl;

}

template <typename T>
class IsGreat {
public:
    IsGreat(const T &i)
    {
        m_num = i;
    }

    bool operator()(const T &num)
    {
        return num > m_num;
    }

private:
    T m_num;
};

/**
 * 常用的函数适配器：
 *   - 绑定器：binder通过把二元函数对象的一个实参绑定到一个特殊的值上，将其转换成一元函数对象
 *      - bind1st: 把值绑定到二元函数对象的第一个实参上
 *      - bind2nd: 把值绑定到二元函数对象的第二个实参上
 *   - 取反器：negator是一个将函数对象的值翻转的函数适配器。
 *      - not1: 翻转一元预定义函数对象的真值
 *      - not2: 翻转二元预定义函数对象的真值
 *
 */
void test2()
{
    vector<int> v1;
    for (int i = 0; i < 9; i++) {
        v1.push_back(i + 1);
    }
    for (auto &item: v1) {
        cout << item << " ";
    }
    cout << endl;

    // 等于3的个数
    int num1 = count(v1.begin(), v1.end(), 3);
    cout << "等于3个数个 num1: " << num1 << endl;

    // 通过谓词 求大于3的个数
    int num2 = count_if(v1.begin(), v1.end(), IsGreat<int>(3));
    cout << "大于3的个数 num2: " << num2 << endl;

    // 通过预定义函数对象 求大于3的个数
    // greater<int>() 有两个参数，左参数来自容器的元素，右参数固定为2（通过bind2nd）
    int num3 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 3));
    cout << "大于3的个数 num3: " << num3 << endl;

    // 求 奇数的个数
    int num4 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
    cout << "奇数的个数 num4: " << num4 << endl;

    // 求 偶数的个数
    int num5 = count_if(v1.begin(), v1.end(), not1(bind2nd(modulus<int>(), 2)));
    cout << "偶数的个数 num5: " << num5 << endl;


}

int main()
{
    test1();
    test2();
    return 0;
}
