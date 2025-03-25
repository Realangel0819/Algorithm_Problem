#include<bits/stdc++.h>
using namespace std;

int n, temp;
string op;
int main() {
    ios::sync_with_stdio(0);
    cin >> n;

    stack<int> s;

    while(n--){
        cin >> op;
        if (op =="push"){
            cin >> temp;
            s.push(temp);
        }
        else if(op =="pop"){
            if(!s.empty()) {
                cout << s.top()<< '\n';
                s.pop();
            }
            else cout << -1<< '\n';
        }
        else if(op =="size"){
            cout << s.size()<< '\n';
        }
        else if(op =="empty"){
            if (s.empty()) cout << 1<< '\n';
            else cout << 0<< '\n';
        }
        else{
            if (!s.empty()) cout << s.top()<< '\n';
            else cout << -1<< '\n';
        }
    }
}