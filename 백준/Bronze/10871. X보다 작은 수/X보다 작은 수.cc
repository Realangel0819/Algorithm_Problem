#include<bits/stdc++.h>
using namespace std;
int n,x;
int ans[100000];
int temp;
int main(void){
    ios::sync_with_stdio(0);
    cin >> n >> x;
    for (int i =0 ;i<n;i++){
        int add;
        cin >> add;
        if (add < x){
            ans[temp++] = add;
        }
    }
    for (int i = 0 ; i< temp ;i++){
        cout << ans[i] << " ";
    }

    cin.get();
    cin.get();

}
