#include <bits/stdc++.h>
using namespace std;

// z, x, y 기준
int dz[6] = {0, 0, 0, 0, 1, -1};
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};

int board[102][102][102];
int dist[102][102][102];

int m, n, h;
queue<tuple<int,int,int>> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;

    // 입력
    for(int z = 0; z < h; z++){
        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                cin >> board[z][x][y];

                if(board[z][x][y] == 1){
                    q.push({z, x, y});
                }
                if(board[z][x][y] == 0){
                    dist[z][x][y] = -1; // 안 익은 토마토
                }
            }
        }
    }

    // BFS
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int z, x, y;
        tie(z, x, y) = cur;

        for(int dir = 0; dir < 6; dir++){
            int nz = z + dz[dir];
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nz < 0 || nz >= h || nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nz][nx][ny] >= 0) continue;
            if(board[nz][nx][ny] == -1) continue;

            dist[nz][nx][ny] = dist[z][x][y] + 1;
            q.push({nz, nx, ny});
        }
    }

    // 결과 계산
    int ans = 0;
    for(int z = 0; z < h; z++){
        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                if(dist[z][x][y] == -1){
                    cout << -1;
                    return 0;
                }
                if(ans < dist[z][x][y]) {
                    ans = dist[z][x][y];
                }            
            }
        }
    }

    cout << ans;
}