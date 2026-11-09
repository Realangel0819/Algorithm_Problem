#include<bits/stdc++.h>

using namespace std;
int p(int q){
    int f[q+2];
    f[0]=0;
    f[1]=1;
    for(int i =2;i<=q;i++){
        f[i]=(f[i-1]+f[i-2])%1000000007;
    }
    return f[q];
}
int solution(int n) {
    int answer = 0;
    answer = p(n+1)%1000000007;
    return answer;
}