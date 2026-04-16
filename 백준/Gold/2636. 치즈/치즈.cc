#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int board[1001][1001];
int temp[1001][1001];
bool visited[1001][1001];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

// 외부 공기 BFS
void bfs(){
    memset(visited, 0, sizeof(visited));

    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = true;

    while(!q.empty()){
        auto cur = q.front(); q.pop();

        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(visited[nx][ny] || board[nx][ny] == 1) continue;

            visited[nx][ny] = true;
            q.push({nx,ny});
        }
    }
}

// 치즈 녹이기
int melt(){
    memset(temp, 0, sizeof(temp));
    int cnt = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == 1){
                bool ok = false;

                for(int dir=0;dir<4;dir++){
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    if(nx<0||ny<0||nx>=n||ny>=m) continue;

                    if(visited[nx][ny]){
                        ok = true;
                        break;
                    }
                }

                if(ok){
                    temp[i][j] = 0;
                    cnt++;
                }
                else temp[i][j] = 1;
            }
        }
    }

    memcpy(board, temp, sizeof(board));
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }

    int time = 0;
    int last = 0;

    while(1){
        bfs();              // 외부 공기
        int melted = melt(); // 녹은 개수

        if(melted == 0) break;

        last = melted;
        time++;
    }

    cout << time << "\n" << last;
}