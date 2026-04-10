#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 

int board[101][101];
int visited[101][101];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int m,n,k,cnt;

int bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = 1;
    int area = 1;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(visited[nx][ny] || board[nx][ny] == 1) continue;

            visited[nx][ny] = 1;
            q.push({nx, ny});
            area++;
        }
    }
    return area;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    int x1,y1,x2,y2;

    while(k--){
        cin >> x1 >> y1 >> x2 >> y2;

        for(int i = x1; i < x2; i++){
            for(int j = y1; j < y2; j++){
                board[j][i] = 1; // 좌표 맞춰서
            }
        }
    }

    vector<int> v;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 0 && !visited[i][j]){
                v.push_back(bfs(i,j));
                cnt++;
            }
        }
    }

    sort(v.begin(), v.end());

    cout << cnt << '\n';
    for(int x : v) cout << x << ' ';
}