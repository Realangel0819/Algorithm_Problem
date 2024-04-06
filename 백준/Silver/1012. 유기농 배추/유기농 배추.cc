#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, m, n, k;
    int tempx, tempy;
    cin >> t;
    

    while(t--){
        int res = 0;
        int field[52][52]= {0,};
        int vis[52][52]= {0,}; //1이 보호받음
        cin >> m >> n >> k;

        queue<pair<int,int>> q;
        for(int i=0;i<k;i++){
            cin >> tempy >> tempx;
            field[tempx][tempy] = 1;
        }

         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(field[i][j]==1 && vis[i][j]==0){
                    res ++;
                    q.push({i,j});
                    vis[i][j]=1;

                    while(!q.empty()){
                        auto cur = q.front();q.pop();
                        for(int a=0;a<4;a++){
                            int nx = cur.X+dx[a];
                            int ny = cur.Y+dy[a];
                            if(nx >= n || nx < 0 || ny >=m || ny < 0) continue;
                            if(vis[nx][ny]==1|| field[nx][ny]!=1) continue;
                            vis[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
        cout <<res<<"\n";
    }
    
}