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

void change_array(Sqlist &L){
    for(int i = 0; i < L.length / 2; i++)
    {
        swap(L.num[i], L.num[L.length - i - 1]);
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
    // swap all array
    change_array(L);
    cout << "The array after swapping:" << endl;
    for (int i = 0; i < L.length; i++) {
        cout << L.num[i] << " ";
    }
    cout << endl;
    
    return 0;
}
