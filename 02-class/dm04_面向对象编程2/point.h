//
// Created by YANHAI on 2019/5/4.
//

#pragma once


class Point {
public:
    void setPoint(int x, int y)
    {
        m_x = x;
        m_y = y;
    }

    int getX()
    {
        return m_x;
    }

    int getY()
    {
        return m_y;
    }

private:
    int m_x;
    int m_y;
};

