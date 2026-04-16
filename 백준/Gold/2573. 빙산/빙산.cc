#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int board[1001][1001];
int tmp[1001][1001];
bool visited[1001][1001];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void melt(){
    memset(tmp, 0, sizeof(tmp));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] > 0){
                int cnt = 0;
                for(int dir=0;dir<4;dir++){
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    if(nx<0||ny<0||nx>=n||ny>=m) continue;
                    if(board[nx][ny] == 0) cnt++;
                }
                int val = board[i][j] - cnt;
                if(val <= 0) val = 0;
                tmp[i][j] = val;
            }
        }
    }

    memcpy(board, tmp, sizeof(board));
}

void bfs(int i, int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j] = true;

    while(!q.empty()){
        auto cur = q.front(); q.pop();

        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(visited[nx][ny] || board[nx][ny]==0) continue;

            visited[nx][ny] = true;
            q.push({nx,ny});
        }
    }
}

int countIce(){
    memset(visited, 0, sizeof(visited));

    int cnt = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] > 0 && !visited[i][j]){
                bfs(i,j);
                cnt++;
            }
        }
    }
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

    int year = 0;

    while(true){
        int cnt = countIce();

        if(cnt >= 2){
            cout << year;
            break;
        }

        if(cnt == 0){
            cout << 0;
            break;
        }

        melt();
        year++;
    }
}