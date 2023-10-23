#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    stack<char> s;
    vector<char> l, r;
    // 将括号匹配<,(,{,[,>,),},]存入vector<char> l, r
    l = {'<', '(', '{', '['};
    r = {'>', ')', '}', ']'};

    char x;
    while(cin >> x){
        if(find(l.begin(), l.end(), x) != l.end()){
            s.push(x);
        }
        else if(find(r.begin(), r.end(), x) != r.end()){
            if(s.empty()){
                cout << "no" << endl;
                return 0;
            }
            else{
                char y = s.top();
                s.pop();
                if(find(l.begin(), l.end(), y) - l.begin() != find(r.begin(), r.end(), x) - r.begin()){
                    cout << "no" << endl;
                    return 0;
                }
            }
        }
    }
    if(s.empty()){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
}