//
// Created by YANHAI on 2019/5/4.
//

#include "cube.h"

void Cube::setABC(int a, int b, int c)
{
    m_a = a;
    m_b = b;
    m_c = c;
}

int Cube::getS()
{
    return (m_a * m_b + m_a * m_c + m_b * m_c) * 2;
}

int Cube::getV()
{
    return m_a * m_b * m_c;
}

int Cube::judgeCube(Cube &v1, Cube &v2)
{
    if (v1.getA() == v2.getA() &&
        v1.getB() == v2.getB() &&
        v1.getC() == v2.getC())
        return 1;
    else
        return 0;
}

int Cube::judgeCube(Cube &v2)
{
    if (m_a == v2.getA() &&
        m_b == v2.getB() &&
        m_c == v2.getC())
        return 1;
    else
        return 0;
}
