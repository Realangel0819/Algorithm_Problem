#include<bits/stdc++.h>
using namespace std;
  
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    queue<int>q;
    int n, k;
    string h;
    cin >> n;
    while(n--){
        cin >> h;
        if(h=="push"){
            cin >> k;
            q.push(k);
        }
        else if(h=="front"){
            if(q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n";
        }
        else if(h=="back"){
            if(q.empty()) cout << -1 << "\n";
            else cout << q.back()<< "\n";
        }
        else if(h=="size"){
            cout << q.size()<< "\n";
        }
        else if(h=="empty"){
            cout << q.empty()<< "\n";
        }
        else{
            if(!q.empty()){
                cout << q.front()<< "\n";
                q.pop();
            }
            else {
                cout << -1 << "\n";
            }
        }
    }
}