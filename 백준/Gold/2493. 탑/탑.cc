#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    stack<pair<int,int>>tower; // index, height
    int n, h;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> h;
        while(!tower.empty()){
            if(h < tower.top().second){
                cout << tower.top().first << " ";
                break;
            }
            tower.pop();
        }
        if(tower.empty())
            cout << 0 << " ";
        tower.push(make_pair(i+1,h));
    }
    return 0;
}