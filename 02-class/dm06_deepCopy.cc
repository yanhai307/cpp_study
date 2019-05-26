//
// Created by YANHAI on 2019/5/25.
//

// 深浅拷贝问题的引出

#include <iostream>
#include <cstring>

using namespace std;

class Name {
public:
    Name(const char *name)
    {
        len = strlen(name);
        // 这里先使用malloc，因为还没有学习 new
        p = (char *) malloc(len + 1);
        if (p) {
            strcpy(p, name);
            printf("Name(const char *name) name: %s, %p\n", p, (void *) p);
        }
    }

    // 必须手动添加拷贝构造函数，深拷贝
#if 1

    Name(const Name &obj)
    {
        len = obj.len;
        p = (char *) malloc(len + 1);
        if (p) {
            strcpy(p, obj.p);
            printf("Name(const Name &obj) name: %s, %p\n", p, (void *) p);
        }
    }

#endif

    ~Name()
    {
        if (p != NULL) {
            printf("~Name() name: %s, %p\n", p, (void *) p);
            free(p);
            p = NULL;
            len = 0;
        }
    }

private:
    char *p;
    int len;
};

int main()
{
    // 释放obj1对象时，程序出现 core dump
    Name obj1("obj1");
    Name obj2 = obj1;   // 必须手动编写拷贝构造函数，深拷贝

    Name obj3("obj3");
//    obj3 = obj2;    // 为什么这一行写 obj3 = obj1时，程序不会 core dump
                        // 这里必须要用到 =号操作符重载了，后面介绍
    return 0;
}
