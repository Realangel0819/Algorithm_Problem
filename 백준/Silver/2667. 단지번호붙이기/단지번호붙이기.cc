#include<bits/stdc++.h>
using namespace std;

#define X first 
#define Y second 

int board[26][26];
int visited[26][26];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int n;

int dfs(int i,int j){
    visited[i][j]=1;
    int cnt =1;
    for (int dir =0;dir<4;dir++){
        int nx = i+dx[dir];
        int ny = j+dy[dir];

        if(nx<0||ny<0||nx>=n||ny>=n) continue;
        if(visited[nx][ny]||board[nx][ny]==0) continue;

        cnt+= dfs(nx,ny);

    }

    return cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    cin >>n;

    string s;

    for(int i = 0 ; i<n ;i++){
        cin >> s;
        for(int j=0;j<n;j++){
            board[i][j] = s[j]-'0';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 1 && visited[i][j] == 0){
                v.push_back(dfs(i,j));
            }
        }
    }

    sort(v.begin(),v.end());

    cout << v.size() << '\n';
    for(int x: v) cout << x <<'\n';


}