#include <iostream>
#include <stack>

using namespace std;

long long fibonacci(int n) {
    if (n <= 1) return n;

    stack<long long> fibStack;
    fibStack.push(0);
    fibStack.push(1);

    for (int i = 2; i <= n; i++) {
        long long a = fibStack.top(); fibStack.pop();
        long long b = fibStack.top(); fibStack.pop();

        fibStack.push(a);
        fibStack.push(a + b);
    }

    return fibStack.top();
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}
