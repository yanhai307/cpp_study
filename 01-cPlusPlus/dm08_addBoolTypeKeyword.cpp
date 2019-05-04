//
// Created by YANHAI on 2019/4/21.
//

/* C++中的布尔类型
 *  C++在C语言的基本类型系统之上增加了bool
 *  C++中bool可取的值只有true和false
 *  理论上bool只占用一个字节
 *  如果多个bool变量定义在一起，可能会各占一个bit，这取决于编译器的实现
 *
 *  true代表真值，编译器内部用1来表示
 *  false代表非真值，编译器内部用0来表示
 *
 *  bool类型只有true（非0）和false（0）两个值
 *  C++编译器会在赋值时将非0值转换为true，0值转换成false
 */

#include <iostream>
using namespace std;

int main()
{
    bool b1 = true;

    // 打印 sizeof(bool): 1
    cout << "sizeof(bool): " << sizeof(bool) << endl;

    // bool变量1或者0
    b1 = 10;
    cout << "b1: " << b1 << endl;

    b1 = -10;
    cout << "b1: " << b1 << endl;

    b1 = 0;
    cout << "b1: " << b1 << endl;

    return 0;
}
