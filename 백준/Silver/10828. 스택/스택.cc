#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int>stack;
    int n;
    cin >> n;
    while(n--){
        string ch;
        cin >> ch;
        if(ch == "push"){
            int k;
            cin >> k;
            stack.push(k);
        }else if(ch == "pop"){
            if(stack.empty()){
                cout << -1 << endl;
            }else{
                cout << stack.top() << endl;
                stack.pop();
            }    
        }else if(ch=="size"){
            cout << stack.size() << endl;
        }else if(ch=="empty"){
            cout << (int)stack.empty() << endl;
        }else {
            if(stack.empty()){
                cout << -1 << endl;
            }else 
                cout << stack.top() << endl;
        }     
    }
}