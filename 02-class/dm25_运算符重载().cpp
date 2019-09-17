//
// Created by YANHAI on 2019/8/17.
//

#include <iostream>

using namespace std;

class F{
public:
    int operator()(int a, int b)
    {
        return a*a+b*b;
    }
};

int main()
{
    F f;
    int c = f(2, 4);
    cout << c << endl;
    return 0;
}
