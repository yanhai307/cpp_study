//
// Created by YANHAI on 2019/8/17.
//

#include <iostream>

using namespace std;

class F {
public:
    int operator()(int a, int b)
    {
        return a * a + b * b;
    }

    explicit operator bool() const
    {
        return !!*this;
    }

    bool operator!() const
    {
        return false;
    }
};

int main()
{
    F f;
    int c = f(2, 4);
    cout << c << endl;

    if (f) {
        cout << "object f is true." << endl;
    } else {
        cout << "object f is false." << endl;
    }

    if (!f) {
        cout << "object f is false." << endl;
    } else {
        cout << "object f is true." << endl;
    }

    return 0;
}
