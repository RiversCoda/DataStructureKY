#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define MAXSIZE
using namespace std;

typedef struct
{
    int num[30];
    int length;
} Sqlist;
bool delete_between(Sqlist &L, int a, int b)
{
    // error case
    if (a >= b || L.length <= 0) {
        cout << "error case" << endl;
        return 0;
    }

    int j = 0; // 用于跟踪新的长度和位置
    for (int i = 0; i < L.length; i++) {
        if (!(L.num[i] >= a && L.num[i] <= b)) { // 如果数字不在a和b之间，我们保留它
            L.num[j] = L.num[i];
            j++;
        }
    }
    L.length = j;
    return 1;
}

int main()
{
    Sqlist L;
    // Initialize
    // Fill the array with random integers between 1 and num
    for (int i = 0; i < 30; i++) {
        L.num[i] = rand() % 16 + 1; // num between 1 and num
    }
    L.length = 30;
    // Output the original array
    cout << "Original array:" << endl;
    for (int i = 0; i < L.length; i++) {
        cout << L.num[i] << " ";
    }
    cout << endl;

    // 此题初始为有序顺序表
    // use sort func to sort
    sort(L.num, L.num + L.length);

    // porcess
    // 随机生成两个1-16的数
    int a = rand() % 16 + 1;
    int b = rand() % 16 + 1;
    // int b = 14;
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    delete_between(L, a, b);

    // show
    cout << "The array after process:" << endl;
    for (int i = 0; i < L.length; i++) {
        cout << L.num[i] << " ";
    }
    cout << endl;

    return 0;
}
