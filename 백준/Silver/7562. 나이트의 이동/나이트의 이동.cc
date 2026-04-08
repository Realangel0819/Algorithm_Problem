#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int visited[301][301];

int dx[8] = {1,2,-2,-1,1,-1,2,-2};
int dy[8] = {2,1,-1,-2,-2,2,-1,1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int l;
        cin >> l;

        int x, y, goalx, goaly;
        cin >> x >> y;
        cin >> goalx >> goaly;

        memset(visited, -1, sizeof(visited));

        queue<pair<int,int>> q;
        q.push({x,y});
        visited[x][y] = 0;

        while(!q.empty()){
            auto cur = q.front(); q.pop();

            if(cur.X == goalx && cur.Y == goaly){
                cout << visited[cur.X][cur.Y] << '\n';
                break;
            }

            for(int dir = 0; dir < 8; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if(nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
                if(visited[nx][ny] != -1) continue;

                visited[nx][ny] = visited[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
        }
    }
}