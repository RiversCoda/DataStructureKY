#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ARRAY_SIZE = 30;
const int POOL_SIZE = 100;  // 这个数字可以根据需要更改，保证大于30即可

// 整数二分板子：
bool check(int x){}
int bsearch_1(int l, int r){
    while(l<r){
        int mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
int bsearch_2(int l, int r){
    while(l<r){
        int mid = (l+r+1) /2;
        if(check(mid)) l = mid;
        else r = mid -1;
    }
    return r;
}

void findOrInsert(int arr[], int x,int start, int end){ // end = n-1
    int l = start, r = end, mid;
    while(l < r){
        mid = (l + r)/2;
        //
        if (arr[mid] == x) break;
        else if(arr[mid] > x){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    if(arr[l] == x) {
        if(l <= 28) {swap(arr[l], arr[l+1]);}
        else{}
    }
    else{
        if(l <= 29) {
            for(int i = 29; i > l; i --){
                arr[i+1] = arr[i];
                
            }
        }
        else{
            arr[30] = x;
        }
        ARRAY_SIZE ++;
    }
    
}
int main()
{
    // 生成一个递增且不重复的数组
    vector<int> pool;
    for (int i = 1; i <= POOL_SIZE; i++) {
        pool.push_back(i);
    }

    random_shuffle(pool.begin(), pool.end());
    int arr[50];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = pool[i];
    }
    sort(arr, arr + ARRAY_SIZE);

    // 输出原始数组
    cout << "Original array:" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 进行处理
    int x = 77;
    findOrInsert(arr, x, 0, 29);

    // 输出处理后的数组
    cout << "Array after processing:" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
