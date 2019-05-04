//
// Created by YANHAI on 2019/5/4.
//

#include <iostream>
#include "circle.h"
#include "point.h"

using namespace std;

int main() {
    Circle c1;
    Point p1;

    c1.setCircle(2, 3, 3);
    p1.setPoint(4, 4);

    if (c1.judge(p1) == 1)
        cout << "点在圆形内" << endl;
    else
        cout << "点在圆形外" << endl;
    return 0;
}
