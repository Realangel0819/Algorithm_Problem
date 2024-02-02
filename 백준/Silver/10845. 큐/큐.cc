#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int ans[1000000];   
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
            if(q.empty()) cout << -1 << endl;
            else cout << q.front() << endl;
        }
        else if(h=="back"){
            if(q.empty()) cout << -1 << endl;
            else cout << q.back()<< endl;
        }
        else if(h=="size"){
            cout << q.size()<< endl;
        }
        else if(h=="empty"){
            cout << q.empty()<< endl;
        }
        else{
            if(!q.empty()){
                cout << q.front()<< endl;
                q.pop();
            }
            else {
                cout << -1 << endl;
            }
        }
    }
}