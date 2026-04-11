#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 

int board[26][26];
int visited[26][26];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int n;

int bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = 1;

    int cnt = 1; // 여기서 시작

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny] || board[nx][ny] == 0) continue;

            visited[nx][ny] = 1;
            cnt++;
            q.push({nx, ny});
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<int> v;

    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<n;j++){
            board[i][j] = s[j] - '0';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 1 && visited[i][j] == 0){
                v.push_back(bfs(i,j));
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << '\n';
    for(int x : v) cout << x << '\n';
}
