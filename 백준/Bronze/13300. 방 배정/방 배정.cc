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
        if(girl[i]%2==0){
            cnt = girl[i]/2 + cnt;
        }
        else{
            cnt = girl[i]/2 + 1 + cnt;
        }

        if(boy[i]%2==0){
            cnt = boy[i]/2 + cnt;
        }
        else{
            cnt = boy[i]/2 + 1 + cnt;
        }
    }
    cout << cnt;
    return 0;

}