//
// Created by YANHAI on 2019/5/26.
//

#include <iostream>
using namespace std;

class C1 {
public:
    int i;
    int j;
    int k;
};

class C2 {
public:
    int i;
    int j;
    int k;
    static int m;
public:
    int getK() const
    {
        return k;
    }

    void setk(int val)
    {
        k = val;
    }
};

struct S1 {
    int i;
    int j;
    int k;
};

struct S2 {
    int i;
    int j;
    int k;
    static int m;
};


int main()
{
    cout << "sizeof(C1)" << sizeof(C1) << endl;
    cout << "sizeof(C2)" << sizeof(C2) << endl;
    cout << "sizeof(S1)" << sizeof(S1) << endl;
    cout << "sizeof(S2)" << sizeof(S2) << endl;
}