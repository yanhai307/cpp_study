//
// Created by YANHAI on 2019/12/15.
//

#include <iostream>

using namespace std;

class Test {
public:
    Test(const char *name) : name(name)
    {
        cout << "构造函数..." << name << endl;
    }

    ~Test()
    {
        cout << "析构函数..." << name << endl;
    }

private:
    const char *name;
};

void TestFun()
{
    Test t1("t1");
    Test t2("t2");

    throw 1;
}

int main()
{
    // 异常被抛出后，从进入try块起，到异常被抛掷前，这期间在栈上的构造的所有对象，
    // 都会被自动析构，析构的顺序和构造的顺序相反。这一过程称为栈的解旋(unwinding)
    try {
        TestFun();
    }
    catch (int e)
    {
        cout << "TestFun发生异常: " << e << endl;
    }
    catch (...) {

    }
    return 0;
}
