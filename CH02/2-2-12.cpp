#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

const int MAXSIZE = 20;

int times_cnt[MAXSIZE]; // 统计各个数字出现次数,全局变量默认全为0
int find_main_num(int arr[])
{
    for (int i = 0; i < MAXSIZE; i++) {
        times_cnt[arr[i]]++;
        if (times_cnt[arr[i]] >= MAXSIZE / 2) {
            return arr[i];
        }
    }
    // 若找到了主元素则会提前退出，否则执行下面的代码
    cout << "no main num" << endl;
    return -1;
}
int main()
{
    int arr[MAXSIZE];

    // Seed the random number generator with current time
    srand(time(nullptr));

    cout << endl;
    // Initialize
    // Fill the array with random 0s and 1s
    for (int i = 0; i < MAXSIZE; i++) {
        arr[i] = rand() % 2; // This will generate either 0 or 1
    }
    for (int i = 0; i < MAXSIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // process
    cout << "main is   " << find_main_num(arr) << endl;
    // Output the array

    return 0;
}
