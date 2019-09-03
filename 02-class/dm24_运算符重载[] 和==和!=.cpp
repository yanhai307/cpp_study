//
// Created by yanhai on 2019/8/17.
//

#include <iostream>

using namespace std;

class Array {
    friend ostream &operator<<(ostream &out, Array &a);

    friend istream &operator>>(istream &in, Array &a);

public:
    Array(int length)
    {
        m_length = length;
        m_space = new int[m_length];
    }

    Array(const Array &obj)
    {
        m_length = obj.m_length;
        m_space = new int[m_length];
        for (int i = 0; i < obj.m_length; ++i) {
//            m_space[i] = obj.m_space[i];
//            (*this)[i] = obj[i];
            m_space[i] = obj[i];
        }
    }

    ~Array()
    {
        delete[] m_space;
        m_length = 0;
    }

    Array &operator=(Array &obj)
    {
        delete[] m_space;
        m_length = obj.m_length;
        m_space = new int[m_length];
        for (int i = 0; i < obj.m_length; ++i) {
//            m_space[i] = obj.m_space[i];
            (*this)[i] = obj[i];
        }

        return *this;
    }

    int &operator[](int i) const
    {
        return m_space[i];
    }

    bool operator==(Array &obj)
    {
        if (m_length != obj.m_length)
            return false;
        for (int i = 0; i < m_length; ++i)
        {
            if (m_space[i] != obj[i])
                return false;
        }
        return true;
    }

    bool operator!=(Array &obj)
    {
        return !(*this == obj);
    }


private:
    int m_length;
    int *m_space;
};

ostream &operator<<(ostream &out, Array &a)
{
    for (int i = 0; i < a.m_length; ++i) {
        out << a[i] << ", ";
    }
    out << endl;
    return out;
}


istream &operator>>(istream &in, Array &a)
{
    for (int i = 0; i < a.m_length; ++i) {
        in >> a[i];
    }
    return in;
}

int main()
{
    Array a1(3);
    cin >> a1;  // 重载 >>
    cout << a1; // 重载 <<

    Array a2 = a1;  // 拷贝构造函数
    cout << a2;

    Array a3(10);
    a3 = a2 = a1;   // 重载 =

    Array a4(3);
    a4[0] = 11;     // 重载 []
    a4[1] = 21;
    a4[2] = 31;

    cout << a4[1] << endl;      // 重载 []

    if (a2 == a3)   // 重载 ==
        cout << "a2 == a3" << endl;
    else
        cout << "a2 != a3" << endl;

    if (a2 != a3)   // 重载 !=
        cout << "a2 != a3" << endl;
    else
        cout << "a2 == a3" << endl;

    if (a3 == a4)   // 重载 ==
        cout << "a3 == a4" << endl;
    else
        cout << "a3 != a4" << endl;

    return 0;
}