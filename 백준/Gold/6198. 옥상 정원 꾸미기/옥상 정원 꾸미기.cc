#include<bits/stdc++.h>
using namespace std;
int n;
long long int c;
long long int sum=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    stack<int>tower;
    cin >> n;
    while(n--){
        cin >> c;
        while(!tower.empty() && tower.top()<=c){
            tower.pop();
        }
        tower.push(c);
        sum+=(tower.size()-1);
    }
    cout << sum << endl;
    return 0;
}