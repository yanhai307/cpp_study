//
// Created by yanhai on 2020/1/22.
//

/**
 * uuid库是一个小的实用工具，可以表示和生成UUID.
 * uuid位于名字空间boost::uuids
 * 头文件
 *  <boost/uuid/uuid.hpp>
 *  <boost/uuid/uuid_generators.hpp>
 *  <boost/uuid/uuid_io.hpp>
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

using namespace std;
using namespace boost::uuids;

void func1()
{
    uuid u;
    assert(uuid::static_size() == 16);
    assert(u.size() == 16);

    vector<unsigned char> v(16, 7);
    std::copy(v.begin(), v.end(), u.begin());   // 使用标准复制算法
    assert(u.data[0] == u.data[1] && u.data[15]==7);    // 数组方式访问

    cout << u << endl;  // 07070707-0707-0707-0707-070707070707
    std::fill_n(u.data+10, 6, 8);   // 标准算法fill_n直接操纵数组

    cout << u << endl;  // 07070707-0707-0707-0707-080808080808
}

// 未完待续...

int main()
{
    func1();
    return 0;
}
