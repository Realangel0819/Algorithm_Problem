#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int ans[1000000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    stack <int> s;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && s.top()<=a[i]) s.pop();
        if(s.empty()){
            ans[i] = -1;
        }
        else {
            ans[i]=s.top();
        }
        s.push(a[i]);
    }

      for (int i = 0; i < n; i++) cout << ans[i] << ' ';

}