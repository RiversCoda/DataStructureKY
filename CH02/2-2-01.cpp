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

bool delete_min(Sqlist &L, int &value)
{
    if (L.length == 0)
        return false;
    else {
        int pos = 0, min_num = L.num[0];
        for (int i = 0; i < L.length; i++) {
            if (L.num[i] < min_num) {
                pos = i;
                min_num = L.num[i];
            }
        }
        for (int i = pos; i < L.length - 1; i++) {
            L.num[i] = L.num[i + 1];
        }
		L.length -= 1;
        value = min_num;
        return true;
    }
}
int main()
{
    Sqlist L;
    // Initialize
    // Fill the array with random integers between 1 and 100
    for (int i = 0; i < 30; i++) {
        L.num[i] = rand() % 100 + 1;
    }
    L.length = 30;
    // Output the original array
    cout << "Original array:" << endl;
    for (int i = 0; i < L.length; i++) {
        cout << L.num[i] << " ";
    }
    cout << endl;
    // Delete the minimum value
    int value;
    if (delete_min(L, value)) {
        cout << "The minimum value is: " << value << endl;
        cout << "The array after deleting the minimum value:" << endl;
        for (int i = 0; i < L.length; i++) {
            cout << L.num[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "The array is empty. Cannot delete the minimum value." << endl;
    }
    return 0;
}
