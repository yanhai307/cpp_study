
#include <iostream>

using std::cout;
using std::endl;

class A {
public:
    void print()
    {
        cout << "A " << endl;
    }

private:
    int a;

};

class B {
public:
    virtual void print()
    {
        cout << "B " << endl;
    }

private:
    int b;

};

int main()
{
    cout << "sizeof(A)" << sizeof(A) << endl;   // 4
    cout << "sizeof(B)" << sizeof(B) << endl;   // 8  多了一个vptr指针
    return 0;
}