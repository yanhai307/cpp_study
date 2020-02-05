//
// Created by yanhai on 2020/1/27.
//

#define BOOST_ENABLE_ASSERT_HANDLER

#include <iostream>
#include <boost/format.hpp>
#include <boost/assert.hpp>

using namespace std;

namespace boost {
void assertion_failed(char const *expr, char const *function, char const *file, long line)
{
    format fmt("Assertion failed!\nExpression: %s\nFunction: %s\nFile: %s\nLine: %ld\n\n");
    fmt % expr % function % file % line;
    cout << fmt;
}

void assertion_failed_msg(char const *expr, char const *msg, char const *function, char const *file, long line)
{
    format fmt("Assertion failed!\nExpression: %s\nFunction: %s\nFile: %s\nLine: %ld\nMsg: %s\n\n");
    fmt % expr % function % file % line % msg;
    cout << fmt;
}
}

double func(int x)
{
    BOOST_ASSERT(x != 0 && "divided by zero");
    cout << "after BOOST_ASSERT" << endl;

    BOOST_ASSERT_MSG(x != 0, "divided by zero");
    cout << "after BOOST_ASSERT_MSG" << endl;

    return 1.0 / x;
}

int main()
{
    func(0);
    return 0;
}
