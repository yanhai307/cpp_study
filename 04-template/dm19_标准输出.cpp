//
// Created by YANHAI on 2019/12/15.
//

/**
 * 标准输出流对象 cout
 *  cout.flush()    // 刷新输出缓冲区
 *  cout.put()      // 将一个字符输出
 *  cout.write()    // 输出二进制流
 *  cout.width()
 *  cout.fill()
 *  cout.setf(标记)
 */

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
    // cout.flush() cout.put()
    {
        cout << "hello" << endl;
        cout.put('h');
        cout.put('e');
        cout.put('l').put('l').put('o');
        cout.flush();
    }

    // cout.write()
    {
        const char *p = "hello c++";
        cout.write(p, strlen(p)) << endl;
        cout.write(p, strlen(p) - 4) << endl;
        cout.write(p, strlen(p) + 4) << endl;
    }

    // 使用类成员函数 width  fill setf
    {
        cout << "<Start>";
        cout.width(10); // 设置宽度
        cout.fill('*');     // 不足设置的宽度，用该字符填充
        cout.setf(ios::showbase);   // 显示前缀
        cout.setf(ios::internal);   // 前缀和要显示的数据分离
        cout << hex << 123 << "<End>" << endl;
    }

    // 使用控制符, 实现上面的效果, 要包含头文件 iomanip
    {
        cout << "<Start>"
             << setw(10)
             << setfill('*')
             << setiosflags(ios::showbase)
             << setiosflags(ios::internal)
             << hex << 123
             << "<End>"
             << endl;
    }
    return 0;
}
