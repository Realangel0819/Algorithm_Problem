#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    stack <int> s;
    string ans;
    int q=1;
    int n, k;
    cin >>n;
    for(int i=0;i<n;i++){
        cin >> k;
        while(q<=k){
            s.push(q++);
            ans+="+\n";
        }
        if(s.top()==k){
            s.pop();
            ans+="-\n";
        }
        else{
            cout << "NO";
            return 0;
        }
    }
    for(auto w:ans) cout<<w;
}