//
// Created by YANHAI on 2019/4/21.
//

// C++中所有的变量和函数都必须有类型
// C语言中的默认类型在C++中是不合法的

// 函数f的返回值是什么类型，参数又是什么类型？
// 函数g可以接受多少个参数？
// 更换成.cpp试试

/*
#include <stdio.h>

f(i)
{
    printf("i = %d\n", i);
}

g()
{
    return 5;
}

int main()
{
    f(10);
    printf("g() = %d\n", g(1, 2, 3, 4, 5));
    return 0;
}
*/

// 运行结果为:
// i = 10
// g() = 5


// 在C++上是编译不通过的
/*
#include <iostream>
using namespace std;

f(i)
{
    printf("i = %d\n", i);
}

g()
{
    return 5;
}

int main()
{
    f(10);
    printf("g() = %d\n", g(1, 2, 3, 4, 5));
    return 0;
}
*/

// 必须写上类型
#include <iostream>
using namespace std;

int f(int i)
{
    printf("i = %d\n", i);
    return 0;
}

int g()
{
    return 5;
}

int main()
{
    f(10);
    printf("g() = %d\n", g());
    return 0;
}
