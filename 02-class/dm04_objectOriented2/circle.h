//
// Created by YANHAI on 2019/5/4.
//

#pragma once

#include "point.h"

class Circle {
public:
    void setCircle(int r, int x, int y) {
        m_r = r;
        p.setPoint(x, y);
    }

    // 在圆内1，不在圆内0
    int judge(Point &p1);

private:
    int m_r;
    Point p;
};


