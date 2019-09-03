//
// Created by YANHAI on 2019/5/4.
//

#ifndef CPP_STUDY_CUBE_H
#define CPP_STUDY_CUBE_H


class Cube {
public:
    void setABC(int a = 0, int b = 0, int c = 0);

    int getS();

    int getV();

    int getA()
    {
        return m_a;
    }

    int getB()
    {
        return m_b;
    }

    int getC()
    {
        return m_c;
    }

    /*
     * 第2种，成员函数判断2个立方体是否相同
     * 不要这么写
     */
    int judgeCube(Cube &v1, Cube &v2);

    /*
     * 第3种，
     */
    int judgeCube(Cube &v2);

    /*
     * 第4种，运算符重载，后面介绍
     * 推荐这样写
     */

private:
    int m_a;
    int m_b;
    int m_c;
};


#endif //CPP_STUDY_CUBE_H
