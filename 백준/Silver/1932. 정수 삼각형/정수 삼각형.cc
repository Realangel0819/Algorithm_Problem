#include<iostream>
using namespace std;

int dp[501][501]={0,};
int max(int a, int b){
    if(a>b)
        return a;
    else 
        return b;
}
int main(){
    int n, maxNum=0;
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin >> dp[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                dp[i][j] = dp[i-1][0] + dp[i][j];
            }
            else if(i==j){
                dp[i][j] =  dp[i-1][j-1]+ dp[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j]+ dp[i][j], dp[i-1][j-1]+ dp[i][j]) ;
            }

            maxNum = max(maxNum, dp[i][j]);
        }

        
    } 
    cout << maxNum;
    return 0;


    







}