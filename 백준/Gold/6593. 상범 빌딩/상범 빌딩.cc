#include<bits/stdc++.h>
using namespace std;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};

int l, r, c;
int dist[31][31][31];
char board[31][31][31];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0) break;

        queue<tuple<int,int,int>> q;
        bool isEscape = false;

        fill(&dist[0][0][0], &dist[0][0][0] + 31*31*31, -1);

        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    cin >> board[i][j][k];

                    if(board[i][j][k] == 'S'){
                        q.push({i,j,k});
                        dist[i][j][k] = 0;
                    }
                }
            }
        }

        while(!q.empty()){
            auto cur = q.front(); q.pop();
            int ch, cx, cy;
            tie(ch, cx, cy) = cur;

            for(int dir = 0; dir < 6; dir++){
                int nh = ch + dh[dir];
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];

                if(nx < 0 || nx >= r || ny < 0 || ny >= c || nh < 0 || nh >= l) continue;
                if(board[nh][nx][ny] == '#') continue;
                if(dist[nh][nx][ny] != -1) continue;

                dist[nh][nx][ny] = dist[ch][cx][cy] + 1;

                if(board[nh][nx][ny] == 'E'){
                    cout << "Escaped in " << dist[nh][nx][ny] << " minute(s).\n";
                    isEscape = true;
                    break;
                }

                q.push({nh,nx,ny});
            }

            if(isEscape) break;
        }

        if(!isEscape) cout << "Trapped!\n";
    }
}