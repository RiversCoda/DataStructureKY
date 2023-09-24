#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>  // <-- Include this for sort function
using namespace std;

const int MAXSIZE = 10;

int find_mid(int a[], int b[], int n){
    int i = 0, j = 0, delete_cnt = 0;
    while (delete_cnt < n - 1){
        if(a[i] < b[j]) i ++;
        else j++;
        delete_cnt ++;
    }
    return min(a[i], b[j]);
}

int main()
{
    int arr1[MAXSIZE];
    int arr2[MAXSIZE];
    // Initialize
    // Fill the array with random integers between 1 and 16
    for (int i = 0; i < MAXSIZE; i++) {
        arr1[i] = rand() % 60 + 61;
    }
    for (int i = 0; i < MAXSIZE; i++) {
        arr2[i] = rand() % 60 + 1;
    }

    // sort arr1 and arr2
    sort(arr1, arr1 + MAXSIZE);  // <-- Sort arr1
    sort(arr2, arr2 + MAXSIZE);  // <-- Sort arr2

    // Output the original array
    cout << "Original array:" << endl;
    for (int i = 0; i < MAXSIZE; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < MAXSIZE; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // process
    // ... (whatever modifications you want to do to the array)


    // Output the processed array
    cout << "mid is:" << endl;
    cout << find_mid(arr1, arr2, MAXSIZE) << endl;

    return 0;
}
