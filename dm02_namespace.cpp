//
// Created by YANHAI on 2019/4/17.
//

#include <iostream>

// 文件iostream没有引入标准的std，因此需要手动引入
using namespace std;

// 定义命名空间
namespace namespaceA {
    int a = 10;
}

namespace namespaceB {
    int a = 20;

    // 命名空间可以嵌套
    namespace namespaceC {
        struct Teacher {
            char name[20];
            int age;
        };
    }
}

// 使用命名空间
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

    // 1.2 同时使用多个命名空间，多个命名空间中包含相同名称的变量
    //     使用该变量时，必须明确指出所属命名空间，否则会产生编译错误
    {
        using namespace namespaceA;
        using namespace namespaceB;
        // 变量a在命名空间namespaceA和namespaceB中均有定义，直接写a会编译错误
//        cout << a << endl;
        // 必须明确指出所属命名空间
        cout << namespaceA::a << endl;
        cout << namespaceB::a << endl;
    }

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

// 结论：
//  1. 当使用<iostream>的时候，该头文件没有定义全局命名空间，必须使用namespace std;
//     这样才能正确使用cout。若不引用using namespace std，需要这样做 std::cout。
//  2. C++标准为了和C区别开，也为了正确使用命名空间，规定头文件不使用后缀.h。
//  3. C++命名空间的定义: namespace name { ... }
//  4. 使用命名空间 using namespace name;
//  5. namespace定义可以嵌套。
