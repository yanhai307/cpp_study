//
// Created by YANHAI on 2019/12/15.
//

#include <iostream>
#include <string>
#include <exception>

using namespace std;

class MyArray {
public:
    MyArray(int len) : m_len(len)
    {
        if (m_len < 0)
            throw eNegative(m_len);
        else if (m_len == 0)
            throw eZero(m_len);
        else if (m_len < 10)
            throw eTooSmall(m_len);
        else if (m_len > 1000)
            throw eTooBig(m_len);
        m_space = new int[len];
    }

    ~MyArray()
    {
        delete[] m_space;
    }

    int len()
    {
        return m_len;
    }

    int &operator[](int index)
    {
        return m_space[index];
    }

    class eSize : public std::exception {
    public:
        eSize(int size) : m_size(size) {}

    protected:
        int m_size;
        mutable string m_msg;
    };

    class eNegative : public eSize {
    public:
        eNegative(int size) : eSize(size) {}

        const char *what() const noexcept final
        {
            m_msg = "小于0错误: ";
            m_msg += std::to_string(m_size);
            return m_msg.c_str();
        }
    };

    class eZero : public eSize {
    public:
        eZero(int size) : eSize(size) {}

        const char *what() const noexcept final
        {
            m_msg = "等于0错误: ";
            m_msg += std::to_string(m_size);
            return m_msg.c_str();
        }
    };

    class eTooBig : public eSize {
    public:
        eTooBig(int size) : eSize(size) {}

        const char *what() const noexcept final
        {
            m_msg = "太大错误: ";
            m_msg += std::to_string(m_size);
            return m_msg.c_str();
        }
    };

    class eTooSmall : public eSize {
    public:
        eTooSmall(int size) : eSize(size) {}

        const char *what() const noexcept final
        {
            m_msg = "太小错误: ";
            m_msg += std::to_string(m_size);
            return m_msg.c_str();
        }
    };


private:
    int *m_space;
    int m_len;
};

int main()
{
    try {
        MyArray m(-100);
        for (int i = 0; i < m.len(); ++i) {
            m[i] = i;
        }
        for (int i = 0; i < m.len(); ++i) {
            cout << m[i] << " ";
        }
        cout << endl;
    } catch (MyArray::eSize &e) {
        cout << "eSize error: " << e.what() << endl;
    } catch (...) {
        cout << "未知错误" << endl;
    }

    return 0;
}
