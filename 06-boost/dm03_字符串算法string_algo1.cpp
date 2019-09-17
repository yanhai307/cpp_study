//
// Created by YANHAI on 2019/9/13.
//

/*
   字符串算法库  boost string_algo库
        -- boost/algorithm/string.hpp
   
   包含的算法分为五大类：
        >> 大小写转换
        >> 判断式与分类
        >> 修剪
        >> 查找与替换
        >> 分割与合并

   string_algo库命名规则
    string_algo库中的算法命名遵循了标准库的惯例
    - 前缀i:     有这个前缀表明算法大小写不敏感，否则大小写敏感
    - 后缀copy:  有这个后缀表明算法不变动输入，返回处理结果的拷贝，
                 否则算法原地处理，输入即输出
    - 后缀if:    有这个后缀表明算法需要一个作为判断式的谓词函数对象，
                 否则使用默认的判断准则。
*/

#include <iostream>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

/*
    1.大小写转换
      void to_upper(T &input);  // 转为大写，改变原字符串
      void to_lower(T &input);  // 转为小写，改变原字符串
      T to_upper_copy(T &input); // 转为大写，不改变原字符串
      T to_lower_copy(T &input); // 转为小写，不改变原字符串
*/
void test1()
{
    // 大小写转换
    cout << "大小写转换" << endl;
    string str1 = "abc";
    to_upper(str1); // 改变原字符串
    cout << str1 << endl;

    to_lower(str1); // 改变原字符串
    cout << str1 << endl;

    string str2 = to_upper_copy(str1);  // 不改变原字符串
    cout << str1 << endl;
    cout << str2 << endl;
}

/*
    2.判断式
        starts_with   检测一个字符串是否是另一个的前缀
        ends_with     检测一个字符串是否是另一个的后缀
        contains  检测一个字符串是否被另一个包含
        equals   检测两个字符串是否相等
        lexicographical_compare  根据字典序检测一个字符串是否小于另一个
        all 检测一个字符串中的所有元素是否满足指定的判断式

        除了all，所有算法都有另一个i前缀的版本
*/
void test2()
{
    // 判断式  ，返回bool
    cout << "判断式" << endl;

    // 前缀
    cout << starts_with("Hello World", "He") << endl; //1  // 大小写敏感
    cout << starts_with("Hello World", "he") << endl;//0
    cout << istarts_with("Hello World", "he") << endl;//1  // 忽略大小写

    // 后缀
    cout << ends_with("Hello World", "ld") << endl;//1   // 大小写敏感
    cout << iends_with("Hello World", "LD") << endl;//1   // 忽略大小写

    // 包含
    cout << contains("Hello World", "llo") << endl; //1  // 大小写敏感
    cout << icontains("Hello World", "LLo") << endl; //1 // 忽略大小写

    // 内容是否相等
    cout << equals("abc", "abc") << endl; //1  // 大小写敏感  
    cout << iequals("abc", "AbC") << endl; //1 // 忽略大小写

    // 判断字符串中的每个字符是否满足判断式
    cout << all("Hello", is_lower()) << endl;//0   // 判断所有字符都是小写
    cout << all("hello", is_lower()) << endl;//1   // 判断所有字符都是小写

    //根据字典序检测一个字符串是否小于另一个
    cout << lexicographical_compare("abc", "xyz") << endl;  // 1    // 前面的小于后面的
    cout << lexicographical_compare("zbc", "xyz") << endl;  // 0    // 前面的不小于后面的
    cout << lexicographical_compare("abc", "abc") << endl;  // 0    // 前面的不小于后面的

    // (小写字符比大写字符 大)
    cout << lexicographical_compare("abc", "XYZ") << endl;  // 0    // 前面的不小于后面的
    cout << ilexicographical_compare("abc", "XYZ") << endl;  // 1    // 忽略大小写，前面的小于后面的
}

/*
    判断式（函数对象）
      string_algo增强了标准库中的equal_to<>和less<>函数
      对象，允许对不同类型的参数进行比较，并提供大小写无关的形式。
      - is_equal  类似equals算法，比较两个对象是否相等。
      - is_less 比较两个对象是否具有小于关系
      - is_not_greater 比较两个对象是否具有不大于关系
*/
void test3()
{
    // 判断式（函数对象）
    cout << "判断式（函数对象）" << endl;
    cout << is_equal()("abc", "abc") << endl;   // 1    // 是否相等
    cout << is_equal()("abc", "Abc") << endl;   // 0    // 是否相等
    cout << is_less()("abc", "zbc") << endl;    // 1    // 是否小于
    cout << is_not_greater()("abc", "zbc") << endl;//1  // 是否不大于

    is_equal eq;
    cout << eq("abc", "abc") << endl;   // 1 等价于上面的写法
}

/*
    分类：
     - is_space     字符是否为空格
     - is_alnum     字符串是否为字母和数字字符
     - is_alpha     字符是否为字母
     - is_cntrl     字符是否为控制字符
     - is_digit     字符是否为十进制数字
     - is_lower     字符是否为小写字符
     - is_upper     字符是否为大写字符
     - is_punct     字符是否为标点符号字符
     - is_xdigit    字符是否为十六进制数字
     - is_any_of    字符是否是参数字符序列中的任意字符
*/
void test4()
{
    cout << "分类" << endl;

    cout << is_alnum()('1') << endl; // 1   // 判断是否是字母或数字
    cout << is_alnum()('a') << endl; // 1
    cout << is_alnum()(';') << endl; // 0

    cout << is_alpha()('A') << endl;//1    // 是否字母
    cout << is_digit()('3') << endl;//1    // 是否数字
    cout << is_xdigit()('F') << endl;//1    // 是否十六进制数字
    cout << is_cntrl()('\n') << endl;//1   // 是否控制字符
    cout << is_any_of("ABCDE")('A') << endl;//1   // 是否是ABCDE里面的任何一个
    cout << is_any_of("ABCDE")('F') << endl;//0   // 是否是ABCDE里面的任何一个
    cout << is_lower()('a') << endl;//1   // 是否小写字符
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}
