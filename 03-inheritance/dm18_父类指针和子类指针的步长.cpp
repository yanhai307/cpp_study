

/* 
    父类指针和子类指针的步长

    结论：
        多态是用父类指针指向子类对象，  和 父类步长++ 是两个不同的概念
*/

#include <iostream>

using std::cout;
using std::endl;

class Parent {
public:
    Parent(int a = 0)
    {
        this->a = a;
    }

    virtual void print()
    {
        cout << "Parent print()" << endl;
    }

private:
    int a;
};

class Child : public Parent {
public:
    Child(int a = 0, int b = 0) : Parent(a)
    {
        //  this->b = b;
    }

private:
    int b;
};

int main()
{
    Parent *pP = nullptr;
    Child *pC = nullptr;
    Child array[] = {Child(1), Child(2), Child(3)};

    // 0
    pP = array;
    pC = array;
    pP->print();
    pC->print();

    // 1
    pP++;   // 指针++后，并没有指向一个实际的对象
    pC++;
    pP->print();    // 错误，指针异常
    pC->print();

    // 2
    pP++;
    pC++;
    pP->print();
    pC->print();
    return 0;
}
