//
// Created by yanhai on 2020/1/22.
//

/**
 * 头文件 <boost/assert.hpp>
 */

#include <iostream>
#include <string>
#include <boost/assert.hpp>

using namespace std;

int main()
{
    BOOST_ASSERT(16 == 0x10);   // 断言成立
    BOOST_ASSERT(string().size() == 1); // 断言失败，抛出异常
    return 0;
}
