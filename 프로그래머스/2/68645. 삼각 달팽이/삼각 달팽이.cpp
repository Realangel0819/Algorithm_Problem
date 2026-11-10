#include<bits/stdc++.h>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>>t(n,vector<int>(n,0));
    int dr[3] = {1,0,-1};
    int dc[3] = {0,1,-1};
    int r = 0, c = 0, d = 0;
    int total = n*(n+1) / 2;
    
    for(int k=1;k<=total;k++){
        t[r][c] = k;
        int nr = r+ dr[d],nc = c +dc[d];
        if(nr<0||nr>=n||nc<0||nc>nr||t[nr][nc]!=0){
            d = (d+1)%3;
            nr = r+dr[d]; nc = c+dc[d];
        }
        r= nr;c=nc;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++) answer.push_back(t[i][j]);
    }
    return answer;
}