//
// Created by YANHAI on 2019/9/13.
//


/*
   数值转换
        -- boost/lexical_cast.hpp
*/

#include <iostream>
#include <cstdlib>
#include <boost/lexical_cast.hpp>

using namespace std;

void test1()
{
    //传统代码
    int a = atoi("123");
    cout << a << endl;

#ifdef _WIN32
    char b[64] = {0};
    itoa(16, b, 2);     // 第三个参数表示二进制
    cout << b << endl;
#endif

    double c = atof("1.23456");
    cout << c << endl;

    char d[64] = {0};
    gcvt(12.23456, 3, d);   // 第2个参数是保留多少位（包含整数位）
    cout << d << endl;
}

// lexical_case使用统一接口形式实现任意类型之间的转换，增强了易用性
void test2()
{
    using boost::lexical_cast;

    // 字符串转整型
    int a = lexical_cast<int>("123");
    cout << a << endl;

    // 字符串转浮点型
    float b = lexical_cast<float>("1.23456");
    cout << b << endl;

    // 浮点数转字符串
    string c = lexical_cast<string>(1.23);
    cout << c << endl;

    // 整型转字符串
    string d = lexical_cast<string>(123);
    cout << d << endl;

    // 转换失败，抛出异常
    try {
        int e = lexical_cast<int>("123e");
        cout << e << endl;
    }
    catch (const boost::bad_lexical_cast &e) {
        cout << e.what() << endl;
    }

    // 只转换前3位，
    int f = lexical_cast<int>("123e", 3);
    cout << f << endl;
}

int main()
{
    test1();
    test2();
    return 0;
}
