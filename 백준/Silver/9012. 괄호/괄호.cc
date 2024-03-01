#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    
    string str;
    int n;
    cin >> n;
    while(n--){
        stack<char>s;
        cin >> str;
        bool v = true;
        for(auto a: str){
            if(a=='('){
                s.push(a);
            }
            else {
                if(s.empty()|| s.top()==')') {
                    v = false;
                    break;
                }
                s.pop();
            }
         
        }
        if(!s.empty()) v = false;
        
        if(v) cout << "YES\n";
        else cout << "NO\n";
    }
}