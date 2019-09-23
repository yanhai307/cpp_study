//
// Created by YANHAI on 2019/9/19.
//

/**
 * 对字符数组 int数组进行排序
 */

#include <iostream>
#include <cstring>

using namespace std;

template<typename T1, typename T2>
int mySort(T1 *array, T2 len)
{
    if (array == nullptr || len == 0)
        return 1;

    for (T2 i = 0; i < len; ++i) {
        for (T2 j = i + 1; j < len; ++j) {
            if (array[i] < array[j]) {
                T1 tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }

    return 0;
}

template<typename T1, typename T2>
void myPrint(T1 *array, T2 len)
{
    for (T2 i = 0; i < len; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    // int类型
    {
        int my_array[] = {11, 33, 44, 33, 3, 2, 9};

        constexpr int len = sizeof(my_array) / sizeof(my_array[0]);

        myPrint<int, int>(my_array, len);
        mySort<int, int>(my_array, len);
        myPrint<int, int>(my_array, len);
    }

    // char类型
    {
        char my_array[] = "abfsfa232afafsasfsb";

//        constexpr int len = sizeof(my_array) / sizeof(my_array[0]) - 1;
        int len = strlen(my_array);

        myPrint<char, int>(my_array, len);
        mySort<char, int>(my_array, len);
        myPrint<char, int>(my_array, len);
    }

    // string类型
    {
        string my_array[] = {"aabb", "csfa", "arwra", "arwab"};

        constexpr int len = sizeof(my_array) / sizeof(my_array[0]);

        myPrint<string, int>(my_array, len);
        mySort<string, int>(my_array, len);
        myPrint<string, int>(my_array, len);
    }
    return 0;
}
