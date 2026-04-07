#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char board[102][102];
int visited[102][102]; 

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n;
void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    char color = board[x][y];

    while(!q.empty()){
        auto cur = q.front(); q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(visited[nx][ny]) continue;
            if(board[nx][ny] == color){
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt1=0,cnt2=0;
    cin >> n;
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                bfs(i, j);
                cnt1++;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'G') board[i][j] = 'R';
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                bfs(i, j);
                cnt2++;
            }
        }
    }

    cout << cnt1 << " " << cnt2;

    

}