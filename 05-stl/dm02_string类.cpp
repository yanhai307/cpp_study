//
// Created by YANHAI on 2020/1/4.
//

/**
 * 标准库类型 string
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// string类的初始化
void test1()
{
    string s1;  // 默认初始化，s1是一个空串
    string s2(s1);  // 直接初始化，s2是s1的副本
    string s3 = s1; // 拷贝初始化，效果与上面的等价
    string s4("value"); // 直接初始化
    string s5 = "value";    // 拷贝初始化
    string s6(10, 'c'); //直接初始化，s6的内容为cccccccccc
    /**
     *  小知识：
     *    直接初始化与拷贝初始化：
     *      1.使用等号（=）初始化一个变量，实际上执行的是拷贝初始化，编译器把右侧的初始值拷贝到新创建的对象中去。
     *      2.相反，不使用等号，则执行的是直接初始化。
     *    当初始值只有一个时，使用直接初始化和拷贝初始化都可以，如果像s6那样初始化要用到的值有多个，
     *    一般来说只能使用直接初始化的方式。但也以使用拷贝初始化，像下面s7那样。
     */
    string s7 = string(10, 'c');
    /**
     * 此处将会产生一个匿名对象，关于这个匿名对象的处理，windows平台和Linux平台处理方式不同，
     * windows平台，将匿名对象拷贝给s7，执行s7的拷贝构造函数，等价于下面 s8的写法。本质上是一致的，但和s8也不同，
     *  s7初始化完成后，匿名对象被析构，而初始化s8的tmp对象不会被立即析构。
     * linux平台，将匿名对象直接给s7, 即s7就是那个匿名对象，不会调用s7的拷贝构造函数
     */
    string tmp(10, 'c');
    string s8 = tmp;
}

// string的读写
void test2()
{
    // 1.读写string对象
    {
        string s;   // 空串
        cin >> s;   // string对象会自动忽略开头的空白(空格 换行符 制表符)并从第一个真正的字符串开始读起，直到遇到下一个空白停止
        cout << s << endl;
        // 假如输入 "   hello world!  ", 将会打印 "hello"
    }

    // 多个输入输出连写在一起
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << s1 << s2 << endl;
        // 假如输入 "   hello world!  ", 将会打印 "helloworld!"
    }

    // 读取未知数量的string对象
    {
        string word;
        // 遇到文件结束标记或者非法输入，循环结束
        while (cin >> word) {
            cout << word << endl;
        }
    }

    // 使用getline读取一整行
    {
        /**
         * getline函数：
         *  函数从给定的输入流中读取数据，遇到换行符为止（注意换行符也被读了进来），然后把所读的内容存入那个string对象中去（注意不存换行符）
         *  如果一开始就遇到了换行符，那么所得到的结果是空string
         */
        string line;
        // 遇到文件结束标记，结束循环
        while (getline(cin, line)) {
            cout << line << endl;   // line中不包含换行符
        }
    }
}

// string的empty size length
void test3()
{
    // empty: 根据string对象是否为空返回的一个bool值
    {
        // 改写之前的程序，只输出非空的行
        string line;
        // 每次读取一行，遇到空行直接跳过
        while (getline(cin, line)) {
            if (!line.empty()) {
                cout << line << endl;
            }
        }
    }

    // size函数返回string对象的长度（即string对象中字符的个数）
    // size 和length是等价的，只是属于两种不同的风格，统一程序，尽量统一写法
    {
        // 改写上面的程序，只输出长度超过80个字符的行
        string line;
        // 每次读取一行，输出其中超过80个字符的行
        while (getline(cin, line)) {
            if (line.size() > 80) {
                cout << line << endl;
            }
        }
        /**
         * size函数返回的是一个string::size_type类型的值，
         * string::size_type是一个与机器无关的类型，大多数标准库都定义了集中配套的类型，这些配套类型体现了标准库类型与机器无关的特性。
         * 使用size_type时加上域名符来表示它是在string类中定义的
         * 值得肯定的是，string::size_type一定是一个无符号类型的值
         */
        // 也可以使用auto或者decltype来推断变量的类型
        auto len = line.size();    // len 的类型是string::size_type
        // tip: 不要在表达式里面将s.size与带符号数混用
    }
}

// string对象的比较，赋值，相加
void test4()
{
    // 比较，包含的运算符有： == != < <= > >=
    {
        string str = "Hello";
        string phrase = "Hello World";
        string slang = "Hiya";
        if (str < phrase) cout << str << " < " << phrase << endl;
        if (slang > phrase) cout << slang << " > " << phrase << endl;
    }

    // 赋值，一般来说，在设计标准库类型时都力求在易用性上向内置类型看齐，因此大多数库类型都支持赋值操作。
    // 对于string类而言，允许把一个对象的值赋值给另外一个对象
    {
        string str1(10, 'n'), str2;
        str1 = str2;    // 赋值，用str2的副本替换str1的内容， 此时str1和str2都是空字符串
    }

    // 两个string对象相加
    // 两个string对象相加得到一个新的string对象，其内容是把左侧的左侧的运算对象与右侧的运算对象串接而成。
    {
        string s1 = "hello, ", s2 = "world\n";
        string s3 = s1 + s2;    // s3的内容是 hello, world\n
        s1 += s2;               // 等价于s1 = s1 + s2;
    }

    // 字面值和string对象相加
    // 当把string对象和字符字面值及字符串字面值混在一条语句中使用时，必须确保每个加法运算符（+）的两侧的运算对象至少有一个是string
    {
        string s1 = "hello", s2 = "world";
        string s3 = s1 + ", " + s2 + '\n';   // s3的内容是 hello, world\n
        string s4 = s1 + ", ";  // 正确，把一个string对象和一个字面值相加
//        string s5 = "hello" + ", "; // 错误，两个运算符对象都不是string
        string s6 = s1 + ", " + "world";    // 正确，每个加法运算符对象至少有一个是string

        // s6等价于
        string s7 = (s1 + ", ") + "world";

        // 也等价于
        string tmp = s1 + ", ";
        string s8 = tmp + "world";
    }

    // 使用append函数
    {
        string s3 = "333";
        string s4 = "444";

        s3.append(s4);  // append string类型
        cout << "s3: " << s3 << endl;

        s3.append("555");   // append char *类型
        cout << "s3: " << s3 << endl;
    }
}

// 处理string对象中的字符
void test5()
{
    // 处理每个字符串，使用基于范围的for语句
    {
        // 示例1
        string str("some string");
        for (auto c : str) {    // 使用auto关键字 让编译器来决定变量c的类型，这里是char类型
            cout << c << endl;
        }

        // 示例2, 统计标点符号的个数
        string s("Hello World!!!");
        // punct_cnt的类型和s.size的返回值类型一样， 也就是 string::size_type
        decltype(s.size()) punct_cnt = 0;
        for (auto c: s) {
            if (ispunct(c)) {
                ++punct_cnt;
            }
        }
        cout << "标点符号的个数为: " << punct_cnt << endl;
    }

    // 使用范围for语句改变字符串中的字符
    // 如果想要改变string对象中字符的值，必须把循环变量定义为引用类型
    {
        // 将字符串转成大写形式
        string s("Hello World!!!");
        for (auto &c : s) {     // 注意，c是引用
            c = toupper(c);
        }
        cout << s << endl;  // 输出 HELLO WORLD!!!
    }

    // 只处理一部分字符
    // 要想访问string对象中的单个字符有两种方式：1.使用下标，2.使用迭代器
    {
        /**
         * 1.下标运算符 []  接收的输入参数是 string::size_type类型的值，
         *                 返回值是该位置上字符的引用。
         *  下标必须是大于等于0且小于s.size()的值
         *   使用超出此范围的下标将引发不可预知的结果，
         */
        {
            string s("Hello World!!!");
            cout << "s[0] = " << s[0] << endl;

            //在s没有const修饰的情况下，可以为下标返回的字符赋新值
            s[1] = 'x';

            // 使用下标迭代
            for (decltype(s.size()) index = 0; index != s.size(); ++index) {
                s[index] = toupper(s[index]);  // 将当前字符改成大写形式
            }
        }

        // 使用下标进行随机访问
        // 编写一个程序，把0-15之间的十进制数转换成对应的十六进制形式
        {
            const string hexdigits = "0123456789ABCDEF";
            cout << "输入0到15之间的数字，数字之间用空格分开，输入非数字结束,并按回车:" << endl;
            string result;
            string::size_type n;
            while (cin >> n) {
                cout << n << endl;
                if (n < hexdigits.size()) {     // 忽略无效输入
                    result += hexdigits[n];     // 得到对应的十六进制数字
                }
            }
            cout << "对应的十六进制形式为：" << result << endl;
        }
    }
}

// at方法和下标[]，效果一样
// 唯一区别：在超出访问范围后，at会抛出异常，[]将引发不可预知的结果
void test6()
{
    string s1 = "abcdefg";
    // at方法
    try {
        for (string::size_type i = 0; i < s1.length() + 2; ++i) {
            cout << s1.at(i) << "-";
        }
        cout << endl;
    } catch (...) {
        cout << "发生异常" << endl;
    }

    // operator[]
    try {
        for (string::size_type i = 0; i < s1.length() + 2; ++i) {
            cout << s1[i] << "-";   // 直接对内存的访问，可能会引起程序崩溃
        }
        cout << endl;
    } catch (...) {
        cout << "发生异常" << endl;
    }
}

// 字符指针和string的转换
void test7()
{
    // 1. char * ==> string
    string s1 = "abcdefghi";

    // 2. string ==> char *
    printf("s1: %s\n", s1.c_str());

    // 3 把string中的内容拷贝到一个 char *buf中
    char p1[20] = {0};
    s1.copy(p1, 4, 2);  // 从第2个位置开始，拷贝4个字符，要保证buf足够大，否则会出现越界
    cout << "p1: " << p1 << endl;
}

// 字符串的查找和替换
void test8()
{
    {
        string s1 = "test 111 test 222 test 333";

        // 没有找到，返回string::npos
        int index = s1.find("test", 0); // 位置下表，从0开始
        cout << index << endl;
    }

    // 一、 统计所有test出现的位置（下标）
    {
        string s1 = "test 111 test 222 test 333";
        int offindex = s1.find("test", 0);
        while (offindex != string::npos) {
            cout << "offindex " << offindex << endl;
            offindex = s1.find("test", offindex + 1);
        }
    }

    // 二、替换
    //s1.replace(int pos, int n, const char *s);   // 删除从pos开始的n个字符，然后在pos处插入串s
    //s1.replace(int pos, int n, const string &s);   // 删除从pos开始的n个字符，然后在pos处插入串s
    //void swap(string &s2); // 交换当前字符串和s2的值
    {
        string s1 = "test 111 test 222 test 333";
        int offindex = s1.find("test", 0);
        while (offindex != string::npos) {
            s1.replace(offindex, 4, "TEST");
            offindex = s1.find("test", offindex + 1);
        }
        cout << "替换后的s1: " << s1 << endl;
    }
}

// 截断（区间删除）和插入
void test9()
{
    string s1 = "hello1 hello2 hello1";
    string::iterator it = find(s1.begin(), s1.end(), 'l');
    if (it != s1.end()) {
        s1.erase(it);
    }
    cout << "s1删除后l的结果: " << s1 << endl;

    s1.erase(s1.begin(), s1.end());
    cout << "s1长度: " << s1.length() << endl;

    //
    string s2 = "BBB";
    s2.insert(0, "AAA");    // 头插法
    cout << "s2: " << s2 << endl;
    s2.insert(s2.length(), "CCC");    // 尾插法
    cout << "s2: " << s2 << endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    return 0;
}
