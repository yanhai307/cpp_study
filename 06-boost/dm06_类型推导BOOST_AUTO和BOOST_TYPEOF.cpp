//
// Created by YANHAI on 2019/9/14.
//

/*
    类型推导
*/

#include <iostream>
#include <typeinfo>
#include <boost/typeof/typeof.hpp>

using namespace std;

/*
    auto关键字
      C++11新标准就引入了类型自动推断：auto关键字让编译器通过初始值
      来进行类型推导。从而获得定义变量的类型，auto定义的变量必须有初始值。

    decltype关键字
        C++11新标准编译时类型推导，除了auto关键字，还有decltype关键字，
        decltype不是像auto一样是从变量的初始化表达式获得类型，而是以表达式作为参数，
        返回该表达式的类型，并且decltype不会对表达式求值。
*/

void test1()
{
    cout << "auto & decltype" << endl;

    auto a = 100;
    cout << typeid(a).name() << endl;

    auto b = 1.243f;
    cout << typeid(b).name() << endl;

    decltype(a++) c;
    cout << a << ", "<< typeid(c).name() << endl;

    decltype('a') d;
    cout << typeid(d).name() << endl;
    
    decltype(&c) e;
    cout << typeid(e).name() << endl;
}

/*
    BOOST_TYPEOF宏
        与decltype类似，BOOST_TYPEOF使用一个表达式作为宏的参数，
        推导出表达式Expr的类型，头文件<boost/typeof/typeof.hpp>

    BOOST_AUTO宏
        与auto类似，BOOST_AUTO推导表达式Expr类型，然后用这个类型
        声明变量Var， 并将表达式的结果赋值给Var，BOOST_AUTO实际上调用了
        BOOST_TYPEOF
        # define BOOST_AUTO(Var, Expr)  BOOST_TYPEOF(Expr) Var = Expr
*/
void test2()
{
    cout << "BOOST_TYPEOF & BOOST_TYPEOF" << endl;
    BOOST_TYPEOF(1.234 + 100) a;
    cout << typeid(a).name() << endl;

    BOOST_AUTO(b, "abcdef");
    cout << b << ", " << typeid(b).name() << endl;
    
    BOOST_AUTO(c, 1234);
    cout << c << ", " << typeid(c).name() << endl;

    for (BOOST_AUTO(i, 0); i < 10; ++i)
    //for (int i = 0; i < 10; ++i)
    {
        cout << i << endl;
    }
}

int main()
{
    test1();
    test2();
    return 0;
}
