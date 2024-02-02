#include<bits/stdc++.h>
using namespace std;
  
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    deque<int>dq;
    cin >> n >> m;
    int ans = 0;

    for(int i=0;i<n;i++) dq.push_back(i+1);

    while(m--){
        cin >> n;
        int idx = find(dq.begin(),dq.end(),n)-dq.begin();

        while(dq.front()!=n){
            if(idx < dq.size()-idx){
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            ans++;
        }
        dq.pop_front();
    }cout << ans;

}