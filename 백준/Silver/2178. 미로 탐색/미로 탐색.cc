#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
char board[102][102];
int dis[102][102];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 
int n, m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> board[i][j];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            dis[i][j] = -1;
    
    dis[0][0] = 0;
    queue<pair<int, int> >q;
    q.push({0,0});
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        for(int z=0; z<4; z++){
            int nx = cur.x+dx[z];
            int ny = cur.y+dy[z];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dis[nx][ny]>=0 || board[nx][ny]!='1') continue;
            dis[nx][ny] = dis[cur.x][cur.y] +1;
            q.push({nx,ny});
        }
    }
    cout <<dis[n-1][m-1] +1;
}
