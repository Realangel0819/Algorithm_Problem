#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(true){
        string a;
        getline(cin, a);
        if(a==".") break;
        stack<char>c;
        bool valid = true;
        for(auto t : a){
            if(t =='('){
                c.push(t);
            }
            else if(t == '['){
                c.push(t);
            }
             else if(t == ')'){
                if(!c.empty() && c.top()=='(') c.pop();
                else {
                    valid = false;
                    break;
                }
            }
             else if(t == ']'){
                if(!c.empty() && c.top()=='[') c.pop();
                else {
                    valid = false;
                    break;
                }
            }
        }

        if(!c.empty()) valid = false;
        if(valid) cout << "yes\n";
        else cout << "no\n";
        
    }
}
