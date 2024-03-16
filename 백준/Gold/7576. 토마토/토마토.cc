#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second

int farm[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 
int n, m;
int vis[1002][1002];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    queue <pair<int, int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> farm[i][j];
            if(farm[i][j]==1) q.push({i,j});
            if(farm[i][j]==0) vis[i][j] = -1;
        }
    }
    int day = 0;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(vis[nx][ny]>=0) continue;
            vis[nx][ny] = vis[cur.x][cur.y] +1;
            q.push({nx,ny});
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==-1){
                cout << -1;
                return 0;
            }
            day = max(day, vis[i][j]);
        }
    }

    cout << day;

    

}
