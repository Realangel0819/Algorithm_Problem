#include<bits/stdc++.h>
using namespace std;
int boy[6];
int girl[6];
int main(){
    int n,k;
    int s,y;
    cin >> n >> k;

    int cnt = 0;

    for (int i = 0; i < n ; i++){
        cin >> s >> y;
        if(s == 0)
            girl[y-1]++;
        else
            boy[y-1]++;
    }
    for(int i = 0; i < 6; i++ ){
        if(girl[i]%k==0){
            cnt = girl[i]/k + cnt;
        }
        else{
            cnt = girl[i]/k + 1 + cnt;
        }

        if(boy[i]%k==0){
            cnt = boy[i]/k + cnt;
        }
        else{
            cnt = boy[i]/k + 1 + cnt;
        }
    }
    cout << cnt;
    return 0;

}
