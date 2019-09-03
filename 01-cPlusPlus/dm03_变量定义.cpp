//
// Created by YANHAI on 2019/4/21.
//

// 在早期C编译器中，
// 变量必须在作用域开始的位置定义
// C++中更强调语言的"实用性"，所有的变量都可以在需要的时候再定义
// 当然，现在新版本的C编译器也支持 变量可随时定义。

// 在VC++6.0中编译下面代码会报错
/*
#include <stdio.h>

int main()
{
    int i = 0;
    printf("hello\n");
    int k;
    return 0;
}
*/

// 在C++中是可以编译通过的

#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    printf("hello\n");
    int k;
    return 0;
}
