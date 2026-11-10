#include<bits/stdc++.h>
#define X first
#define Y second

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
using namespace std;

int solution(vector<string> board) {
    int n = board.size();
    int m = board[0].size();
    
    vector<vector<int>> dist(n,vector<int>(m,-1));
    
    int gr = 0, gc = 0;
    
    queue<pair<int,int>> q;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == 'G'){
                gr =i; gc=j;
            }
            if(board[i][j]=='R'){
                q.push({i,j});
                dist[i][j] =0;
            }
        }
    }
    
    while(!q.empty()){
        auto cur = q.front();q.pop();
        for(int i=0;i<4;i++){
            int cx = cur.X;
            int cy = cur.Y;
            while(true){
                int nx = dx[i] + cx;
                int ny = dy[i] + cy;
                if(nx<0||ny<0||nx>=n||ny>=m||board[nx][ny]=='D') break;
                cx = nx; cy = ny;
            }
            if(dist[cx][cy]!=-1) continue;
            dist[cx][cy] = dist[cur.X][cur.Y]+1;
            q.push({cx,cy});
        }
    }
    return dist[gr][gc];
}