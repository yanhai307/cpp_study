//
// Created by YANHAI on 2019/5/26.
//

#include <iostream>

using namespace std;

class Test {
public:
    Test(int a, int b)  // --> Test(Test *this, int a, int b)
    {
//        a = a;
//        b = b;
        this->a = a;
        this->b = b;
    }

    void print()
    {
        cout << "a: " << a << endl;
        cout << "b: " << this->b << endl;
    }

private:
    int a;
    int b;
};

int main()
{
    Test t1(1, 2);
    t1.print(); // --> print(&t1);
    return 0;
}
