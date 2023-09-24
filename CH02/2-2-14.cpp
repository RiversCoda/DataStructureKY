#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

const int SIZE1 = 15;
const int SIZE2 = 16;
const int SIZE3 = 17;

#define MAX_INT = 0x7fffffff;
int max3(int a, int b, int c)
{
    return max(max(a, b), c);
}
int min3(int a, int b, int c)
{
    return min(min(a, b), c);
}
int max_distance(int a, int b, int c)
{
    int end = max3(a, b, c);
    int start = min3(a, b, c);
    return end - start;
}
int find_min_ans(int arr1[], int arr2[], int arr3[], int a, int b, int c)
{
    int i = 0, j = 0, k = 0;
    int ans = 0x7ffffff;
    while (i < a && j < b && k < c) {
        ans = min(2 * max_distance(arr1[i], arr2[j], arr3[k]), ans);
        if (arr1[i] <= arr2[j] && arr1[i] <= arr3[k]) {
            i++;
        }
        else if (arr2[j] < arr1[i] && arr2[j] < arr3[k]) {
            j++;
        }
        else {
            k++;
        }
    }
    return ans;
}
int main()
{
    int arr1[SIZE1];
    int arr2[SIZE2];
    int arr3[SIZE3];

    // Fill the arrays with random integers between -32 and 32
    for (int i = 0; i < SIZE1; i++) {
        arr1[i] = rand() % 65 - 32;
    }
    for (int i = 0; i < SIZE2; i++) {
        arr2[i] = rand() % 65 - 32;
    }
    for (int i = 0; i < SIZE3; i++) {
        arr3[i] = rand() % 65 - 32;
    }

    // Output the original arrays
    cout << "Array 1:" << endl;
    for (int i = 0; i < SIZE1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Array 2:" << endl;
    for (int i = 0; i < SIZE2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    cout << "Array 3:" << endl;
    for (int i = 0; i < SIZE3; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    cout << "ans" << find_min_ans(arr1, arr2, arr3, SIZE1, SIZE2, SIZE3);
    return 0;
}
