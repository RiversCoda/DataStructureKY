#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main(){
    unordered_set<char> op, num;
    num = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    op = {'+', '-', '*', '/'};
    stack<char> s;
    string str;
    cin >> str;
    
    for(int i = 0; i < str.size(); i++){
        // 如果str[i]是数字就进栈
        if(num.find(str[i]) != num.end()){
            s.push(str[i]);
        }
        // 如果str[i]是运算符就弹出两个数字,计算结果后再进栈
        else if(op.find(str[i]) != op.end()){
            if(s.size() < 2){
                cout << "error" << endl;
                return 0;
            }
            else{
                char x = s.top();
                s.pop();
                char y = s.top();
                s.pop();
                int a = x - '0';
                int b = y - '0';
                int c;
                if(str[i] == '+'){
                    c = a + b;
                }
                else if(str[i] == '-'){
                    c = a - b;
                }
                else if(str[i] == '*'){
                    c = a * b;
                }
                else if(str[i] == '/'){
                    c = a / b;
                }
                s.push(c + '0');
            }
        }
    }

    if(s.size() == 1){
        cout << s.top() << endl;
    }
    else{
        cout << "error" << endl;
    }
}