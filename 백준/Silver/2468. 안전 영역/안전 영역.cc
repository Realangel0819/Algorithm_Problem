#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
int board[101][101];
int visited[101][101];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(int x, int y, int h){
    queue<pair<int,int>> q;
    visited[x][y] = 1;
    q.push({x,y});

    while(!q.empty()){
        auto cur = q.front(); q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
            if(visited[nx][ny]) continue;
            if(board[nx][ny] <= h) continue;

            visited[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int maxH = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            maxH = max(maxH, board[i][j]);
        }
    }

    int ans = 0;

    for(int h = 0; h <= maxH; h++){
        memset(visited, 0, sizeof(visited));
        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && board[i][j] > h){
                    bfs(i,j,h);
                    cnt++;
                }
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans;
}

