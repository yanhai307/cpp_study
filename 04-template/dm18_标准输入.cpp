//
// Created by YANHAI on 2019/12/15.
//

/**
 * 标准输入流对象 cin
 *  cin.get()   // 一次只能读取一个字符
 *  cin.get(一个参数) // 读取一个字符
 *  cin.get(三个参数) // 可以读字符串
 *  cin.getline()   // 可以接收空格
 *  cin.ignore()    // 忽略缓冲区的数据
 *  cin.peek()      // 查看缓存区有没有数据，如果有数据，返回第1个字符，没有数据，阻塞
 *  cin.putback()   // 将一个字符放到缓冲区
 */

#include <iostream>

using namespace std;

int main()
{

    // cin >>
    {
        char buf[1024];
        int i;
        long l;

        cout << "请输入一个int类型的数据，回车结束" << endl;
        cin >> i;
        cout << "输入的int类型数据为: " << i << endl;

        cout << "请输入一个long类型的数据，回车结束" << endl;
        cin >> l;
        cout << "输入的long类型数据为: " << l << endl;

        cout << "请输入一个字符串，包含空格，回车结束" << endl;
        cin >> buf;     // 遇到空格，停止接收
        cout << "输入的字符串为: " << buf << endl;
    }

    // cin.get()
    {
        char ch;
        cout << "请输入一个字符串, 遇到字符q终止" << endl;
        while ((ch = cin.get()) != EOF) {
            cout << ch << endl;
            if (ch == 'q')
                break;
        }
    }

    // cin.get(a)
    {
        char a, b , c;
        cout << "输入一个长度大于6的字符串" << endl;

        cin.get(a);
        cin.get(b);
        cin.get(c);
        cout << "a: " << a << ", b: " << b << ", c: "<< c << endl;

        cout << "因为缓冲区还有数据，因此程序不会阻塞" << endl;
        cin.get(a).get(b).get(c);   // 支持链式
        cout << "a: " << a << ", b: " << b << ", c: "<< c << endl;
    }

    // cin.getline()
    {
        char buf1[256];
        char buf2[256];

        cout << "输入一个字符串，包含多个空格，回车结束" << endl;
        cin >> buf1;
        cin.getline(buf2, 256); //    可以接收空格

        cout << "buf1:" << buf1 << ", buf2:" << buf2 << endl;
    }

    // cin.ignore()
    {
        char buf1[256];
        char buf2[256];

        cout << "输入'aa  bbccdd'，回车结束" << endl;
        cin >> buf1;
        cin.ignore(2);   // 忽略缓冲区的2个字符
        cin.getline(buf2, 256); //    可以接收空格

        cout << "buf1:" << buf1 << ", buf2:" << buf2 << endl;
    }

    // cin.peek()
    {
        char buf1[256];
        char buf2[256];

        cout << "输入'aa  bbccdd'，回车结束" << endl;
        cin >> buf1;
        cin.ignore(2);   // 忽略缓冲区的2个字符

        int ch1 = cin.peek();
        cout << "ch1:" << ch1 << endl;

        cin.getline(buf2, 256); //    可以接收空格
        cout << "buf1:" << buf1 << ", buf2:" << buf2 << endl;
    }

    // cin.putback()
    {
        cout << "输入一个字符串或者一个数字" << endl;
        char c = std::cin.get();
        if (c >= '0' && c <= '9') {
            int number;
            cin.putback(c); // 再将刚才拿出来的字符还回去
            cin >> number;
            cout << "输入的数字为: " << number << endl;
        } else {
            char buf[1024];
            cin.putback(c);
            cin.getline(buf, 1024);
            cout << "输入的字符串为: " << buf << endl;
        }
    }

    return 0;
}
