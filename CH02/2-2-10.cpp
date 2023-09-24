#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXSIZE = 30;

void reverse(int arr[], int start_pos, int end_pos){
    for(int i = start_pos, j = 0; i <= (start_pos + end_pos) / 2; i++, j ++){
        int temp = arr[i];
        arr[i] = arr[end_pos - j];
        arr[end_pos - j] = temp;
    }
}

void move(int arr[], int x){
    reverse(arr, 0, x-1);
    reverse(arr, x, MAXSIZE - 1);
    reverse(arr, 0, MAXSIZE - 1);
}

int main()
{
    int arr[MAXSIZE];
    // Initialize
    // Fill the array with random integers between 1 and 16
    for (int i = 0; i < MAXSIZE; i++) {
        arr[i] = rand() % 16 + 1;
    }
    
    // Output the original array
    cout << "Original array:" << endl;
    for (int i = 0; i < MAXSIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // process
    // ... (whatever modifications you want to do to the array)
    move(arr, 2);
    
    // Output the processed array
    cout << "The array after process:" << endl;
    for (int i = 0; i < MAXSIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
