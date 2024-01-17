#include<iostream>
using namespace std;
int main(){
    int n;
    int dp[100]={0,};
    int a[100]={0,};
    cin >> n;

    dp[1] = 1;
    dp[2]= 2;
    dp[3] = 4;
    dp[4] =7;
    for(int i=4;i<=10;i++){
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1]; 
    }
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    for(int i=1;i<=n;i++){
        cout << dp[a[i]] << endl;
    }
}