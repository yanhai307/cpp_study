//
// Created by YANHAI on 2019/5/4.
//

#include "circle.h"

// 在圆内1，不在圆内0
int Circle::judge(Point &p1) {
    int r2 = m_r * m_r;
    int d2 = (p.getX() - p1.getX()) * (p.getX() - p1.getX()) +
             (p.getY() - p1.getY()) * (p.getY() - p1.getY());
    if (r2 > d2)
        return 1;
    else
        return 0;
}
