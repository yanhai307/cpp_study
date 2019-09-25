//
// Created by yanhai on 2019/9/25.
//

/**
 * 经过模板的原理可以知道，模板不支持分离编译，故类模板的声明和实现必须写在一个文件中
 * 因此，要将hpp文件包含进来，
 * 其实，正确的写法应该是 将.h中的代码也放在.hpp中（这里分开写只是为了演示）
 */

#include <iostream>
//#include "complex.h"    // 只包含.h将会编译失败
#include "complex.hpp"    // 应该把类模板的声明和实现写在一个文件中

using std::cout;
using std::endl;

int main()
{
    Complex<int> c1(1, 2);
    Complex<int> c2(3, 4);

    {
        Complex<int> c3 = c1 + c2;
        cout << c3 << endl;
    }

    {
        Complex<int> c4 = mySub(c1, c2);
        cout << c4 << endl;
    }

    return 0;
}
