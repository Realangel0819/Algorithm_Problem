#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    
    string str;
    int n;
    cin >>n;
    while(n--){
        stack<int>s;
        cin >> str;
        for(auto a : str){
            if(s.empty() || s.top()!=a) s.push(a);
            else if(s.top()==a) {
                s.pop();
            }
        }
        if(s.empty()) cnt++;
    }
    cout << cnt;
}
