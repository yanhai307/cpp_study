//
// Created by YANHAI on 2019/12/15.
//

#include <iostream>

using namespace std;

// -----------以前的解决方式----------------
int copy_string1(char *dst, const char *src)
{
    if (src == nullptr)
        return 1;
    if (dst == nullptr)
        return 2;
    if (src[0] == 'h')  // 模拟拷贝时出错
        return 3;
    while (*src != '\0') {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
    return 0;
}

void test1()
{
    const char *p = "hello world";
    char buf[100] = {0};
    int r = copy_string1(buf, p);
    switch (r) {
        case 1:
            cout << "源错误" << endl;
            break;
        case 2:
            cout << "目的错误" << endl;
            break;
        case 3:
            cout << "拷贝过程错误" << endl;
            break;
        default:
            cout << "未知错误" << endl;
    }
}

// ---------------------使用异常---------------

void copy_string2(char *dst, const char *src)
{
    if (src == nullptr)
        throw 1;
    if (dst == nullptr)
        throw 2;
    if (src[0] == 'h')  // 模拟拷贝时出错
        throw 3;
    while (*src != '\0') {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
}

void test2()
{
    const char *p = "hello world";
    char buf[100] = {0};
    try {
        copy_string2(buf, p);
    }
    catch (int e) {
        cout << e << " int类型错误" << endl;
    } catch (...) {
        cout << "未知错误" << endl;
    }
}

// ---------------------使用char*异常---------------

void copy_string3(char *dst, const char *src)
{
    if (src == nullptr)
        throw "源错误";
    if (dst == nullptr)
        throw "目的错误";
    if (src[0] == 'h')  // 模拟拷贝时出错
        throw "拷贝过程错误";
    while (*src != '\0') {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
}

void test3()
{
    const char *p = "hello world";
    char buf[100] = {0};
    try {
        copy_string3(buf, p);
    }
    catch (int e) {
        cout << e << " int类型错误" << endl;
    } catch (const char *e) {
        cout << e << " char* 类型错误" << endl;
    } catch (...) {
        cout << "未知错误" << endl;
    }
}

// ---------------------使用异常类---------------

class BadSrcException {
};

class BadDstException {
};

class BadProcessException {
public:
    BadProcessException()
    {
        cout << "BadProcessException构造函数" << endl;
    }

    BadProcessException(const BadProcessException &obj)
    {
        cout << "BadProcessException拷贝构造函数" << endl;
    }

    ~BadProcessException()
    {
        cout << "BadProcessException析构函数" << endl;
    }
};


void copy_string4(char *dst, const char *src)
{
    if (src == nullptr)
        throw BadSrcException();
    if (dst == nullptr)
        throw BadDstException();
    if (src[0] == 'h')  // 模拟拷贝时出错
    {
        cout << "异常开始..." << endl;
        throw BadProcessException();    // 生成的是一个匿名对象吗？
    }
    if (src[0] == 'a') {
//        BadProcessException e;
//       throw &e;  // 上面catch接收到的将是一个野指针
        throw new BadProcessException; // 要使用new
    }
    while (*src != '\0') {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
}

void test4()
{
//    const char *p = "hello world";
    const char *p = "aello world";
    char buf[100] = {0};
    try {
        copy_string4(buf, p);
    }
    catch (int e) {
        cout << e << " int类型错误" << endl;
    } catch (const char *e) {
        cout << e << " char* 类型错误" << endl;
    } catch (BadSrcException e) {
        cout << "BadSrcException 类型错误" << endl;
    } catch (BadDstException e) {
        cout << "BadDstException 类型错误" << endl;
    }
        // 结论1： 如果接收异常的时候，使用一个异常变量，则发生拷贝构造异常变量
        // 结论2：catch (BadProcessException e) 和catch (BadProcessException &e) 不能同时写，编译报错
        // 结论3： 使用引用，会使用throw抛掷的那个对象
        /*catch (BadProcessException e) {   // e就是那个匿名对象，还是又拷贝了一份?
            // 发生了拷贝构造
            cout << "BadProcessException 类型错误" << endl;
        }*/
    catch (BadProcessException &e) {
        cout << "BadProcessException 类型错误" << endl;
    }
    // 结论4： 指针可以和 引用/元素 同时写
    catch (BadProcessException *e) {
        cout << "BadProcessException * 类型错误" << endl;
        delete e;    // 底层使用了new， 上层必须delete，否则会内存泄漏
    }
    catch (...) {
        cout << "未知错误" << endl;
    }
    cout << __FUNCTION__ << "函数结束" << endl;

    // ************结论: 使用引用 *******************
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}
