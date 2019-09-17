//
// Created by YANHAI on 2019/8/17.
//

#include <iostream>
#include <cstring>

using namespace std;

class Name {
    friend ostream &operator<<(ostream &out, Name &n);

public:
    Name(const char *name)
    {
        m_len = strlen(name);
        m_p = new char(m_len + 1);
//        m_p = (char *)malloc(m_len+1);
        strcpy(m_p, name);
        m_p[m_len] = 0;
    }

    Name(const Name &obj)
    {
        m_len = obj.m_len;
        m_p = new char(m_len + 1);
//        m_p = (char *)malloc(m_len+1);
        strcpy(m_p, obj.m_p);
        m_p[m_len] = 0;
    }

    ~Name()
    {
        printf("delete p: %p\n", m_p);
        delete m_p;
//        free(m_p);
        m_len = 0;
    }

    Name &operator=(Name &obj)
    {
        // 先释放旧内存
        delete m_p;

        m_len = obj.m_len;
        m_p = new char(m_len + 1);
        strcpy(m_p, obj.m_p);
        m_p[m_len] = 0;

        // 返回引用
        return *this;
    }

private:
    char *m_p;
    int m_len;
};

ostream &operator<<(ostream &out, Name &n)
{
    printf("p: %p ", n.m_p);
    out << n.m_p << " len: " << n.m_len;
    return out;
}

void display()
{
    Name a("dog");
    Name b = a;
    Name c("cat");
    Name d("bird");
    cout << b << endl;

    c = a;
    cout << c << endl;

    c = b = d;
    cout << c << endl;
}

int main()
{
    display();
    return 0;
}
