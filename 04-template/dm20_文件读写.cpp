//
// Created by YANHAI on 2019/12/15.
//

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    {
        const char *filename = "/tmp/test.txt";

        // ofstream
        {
            ofstream fout(filename);
            if (fout) {     // 可以if一个对象，是因为重载了bool操作符
                fout << "hello...111" << endl;
                fout << "hello...222" << endl;
                fout << "hello...333" << endl;
                fout.close();
            } else {
                cout << "打开文件" << filename << "失败" << endl;
            }
        }

        // ifstream
        {
            ifstream fin(filename);
            if (!fin) {     // 也重载了!操作符
                cout << "打开文件" << filename << "失败" << endl;
            } else {
                char ch;
                while ((ch = fin.get()) != EOF) {
                    cout << ch;
                }
                cout.flush();
                fin.close();
            }
        }

    }

    // 二进制文件读写
    {
        class Teacher {
        public:
            Teacher()
            {
                m_age = 20;
                m_name[0] = 0;
            }

            Teacher(int age, const char *name)
            {
                m_age = age;
                strcpy(m_name, name);
            }

            void printInfo()
            {
                cout << "age: " << m_age << ", name: " << m_name << endl;
            }

        private:
            int m_age;
            char m_name[32];
        };

        // 将对象序列化到文件
        const char *filename = "/tmp/test_b.dat";
        {
            ofstream fout(filename, ios::binary);
            if (fout) {
                Teacher t1(23, "t23");
                Teacher t2(18, "t18");
                fout.write((char *) &t1, sizeof(t1));
                fout.write((char *) &t2, sizeof(t2));
                fout.close();
            }
        }
        {
            ifstream fin(filename, ios::binary);
            if (fin) {
                Teacher t1;
                Teacher t2;
                fin.read((char *) &t1, sizeof(t1));
                fin.read((char *) &t2, sizeof(t2));
                fin.close();

                t1.printInfo();
                t2.printInfo();
            }
        }
    }

    return 0;
}
