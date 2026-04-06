#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char board[1002][1002];
int fire[1002][1002]; 
int dist[1002][1002]; 

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    queue<pair<int,int>> fq; 
    queue<pair<int,int>> jq; 

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> board[i][j];
            fire[i][j] = -1;
            dist[i][j] = -1;

            if(board[i][j] == 'F'){
                fq.push({i,j});
                fire[i][j] = 0;
            }
            if(board[i][j] == 'J'){
                jq.push({i,j});
                dist[i][j] = 0;
            }
        }
    }

    // 1. 불 BFS
    while(!fq.empty()){
        auto cur = fq.front(); fq.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(board[nx][ny] == '#') continue;
            if(fire[nx][ny] != -1) continue;

            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            fq.push({nx, ny});
        }
    }

    //  2. 지훈 BFS
    while(!jq.empty()){
        auto cur = jq.front(); jq.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c){
                cout << dist[cur.X][cur.Y] + 1;
                return 0;
            }

            if(board[nx][ny] == '#') continue;
            if(dist[nx][ny] != -1) continue;

            if(fire[nx][ny] != -1 && fire[nx][ny] <= dist[cur.X][cur.Y] + 1)
                continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            jq.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
}