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
// way 1
void delete_value(Sqlist &L, int x)
{
    int filled_pos = 0;
    int delete_cnt = 0;
    for (int i = 0; i < L.length; i++) {
        int flag = 0;
        if (L.num[i] == x) {
            flag = 1;
            delete_cnt++;
        }
        if (flag == 0) {
            L.num[filled_pos] = L.num[i];
            filled_pos++;
        }
    }
    L.length -= delete_cnt;
}

// way2
void delete_value1(Sqlist &L, int x)
{
    int delete_cnt = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.num[i] == x) {
            delete_cnt++;
        }
        L.num[i - delete_cnt] = L.num[i];
    }
    L.length -= delete_cnt;
}

int main()
{
    Sqlist L;
    // Initialize
    // Fill the array with random integers between 1 and 100
    for (int i = 0; i < 30; i++) {
        L.num[i] = rand() % 10 + 1;
    }
    L.length = 30;
    // Output the original array
    cout << "Original array:" << endl;
    for (int i = 0; i < L.length; i++) {
        cout << L.num[i] << " ";
    }
    cout << endl;
    // porcess
    // random x in array
    int pos = rand() % L.length;
    int x = L.num[pos];
    cout << "delete x is " << x << endl;
    delete_value1(L, x);

    // show
    cout << "The array after process:" << endl;
    for (int i = 0; i < L.length; i++) {
        cout << L.num[i] << " ";
    }
    cout << endl;

    return 0;
}
