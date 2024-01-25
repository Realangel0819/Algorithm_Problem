#include<bits/stdc++.h>
using namespace std;
int temp[10];
int main(){
    int a;
    cin >> a;
    while(a>0){
        temp[a%10]++;
        a/=10;
    }
    int max=0;
    int k = temp[6]+temp[9];
    if(k%2==0) k/=2;
    else k=k/2+1;

    temp[6]=k;
    temp[9]=k;
    
    for(auto s : temp){
        if(max < s)
            max =s;
    }

    cout << max;
}