//
// Created by YANHAI on 2019/5/4.
//

/*
 * 案例1  设计立方体（Cube），求出立方体的面积和体积
 *        求两个立方体，是否相等（全局函数和成员函数）
 */

#include <iostream>
#include "cube.h"

using namespace std;

// 第一种方法，使用全局函数
// 1相等 0不相等
int judgeCube(Cube &v1, Cube &v2) {
    if (v1.getA() == v2.getA() &&
        v1.getB() == v2.getB() &&
        v1.getC() == v2.getC())
        return 1;
    else
        return 0;
}

int main() {
    Cube v1, v2;
    v1.setABC(1, 2, 3);
    cout << "c1.getS(): " << v1.getS() << endl;
    cout << "c1.getV(): " << v1.getV() << endl;

    v2.setABC(1, 2, 4);
    if (judgeCube(v1, v2) == 1) {
        cout << "v1 == v2" << endl;
    } else {
        cout << "v1 != v2" << endl;
    }

    v2.setABC(1, 2, 3);
    if (v1.judgeCube(v1, v2) == 1) {    // 不要这样定义函数
        cout << "v1 == v2" << endl;
    } else {
        cout << "v1 != v2" << endl;
    }

    v2.setABC(1, 3, 3);
    if (v1.judgeCube(v2) == 1) {    // 应该这样
        cout << "v1 == v2" << endl;
    } else {
        cout << "v1 != v2" << endl;
    }


    return 0;
}