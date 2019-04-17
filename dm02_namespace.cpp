//
// Created by YANHAI on 2019/4/17.
//

#include <iostream>

using namespace std;

namespace namespaceA {
    int a = 10;
}

namespace namespaceB {
    int a = 20;
    namespace namespaceC {
        struct Teacher {
            char name[20];
            int age;
        };
    }
}


int main()
{
    // 1. 使用不同命名空间的中的变量a
    // 1.1 通过 using namespace
    {
        using namespace namespaceA;
        cout << a << endl;
    }

    {
        using namespace namespaceB;
        cout << a << endl;
    }

    // 1.2 同时使用多个命名空间，多个命名空间中包含相同名称的变量，会产生编译错误
//    {
//        using namespace namespaceA;
//        using namespace namespaceB;
//        cout << a << endl;
//    }

    // 1.3 也可以使用 using namespaceA::a
    {
        using namespaceA::a;
        cout << a << endl;
    }

    // 1.4 也可以直接使用
    {
        cout << namespaceA::a << endl;
        cout << namespaceB::a << endl;
    }

    // 2. 下面是如何使用Teacher结构体
    // 2.1 可以使用 using namespace
    {
        using namespace namespaceB::namespaceC;
        Teacher t1;
        t1.age = 20;
        cout << t1.age << endl;
    }

    // 2.2 也可以 using namespaceB::namespaceC::Teacher
    {
        using namespaceB::namespaceC::Teacher;
        Teacher t1;
        t1.age = 21;
        cout << t1.age << endl;
    }

    // 2.3 也可以直接使用 namespaceB::namespaceC::Teacher
    {
        namespaceB::namespaceC::Teacher t1;
        t1.age = 22;
        cout << t1.age << endl;
    }

    return 0;
}
