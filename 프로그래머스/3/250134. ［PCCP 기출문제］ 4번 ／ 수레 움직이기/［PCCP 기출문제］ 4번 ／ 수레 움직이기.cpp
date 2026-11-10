#include<bits/stdc++.h>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N,M;
int answer = 0;

int redStart[2];
int blueStart[2];

int redGoal[2];
int blueGoal[2];

bool redVisited[4][4];
bool blueVisited[4][4];

vector<vector<int>> maze;

void dfs(int rr,int rc, int br ,int bc, int cnt){
    if(rr==redGoal[0]&&rc==redGoal[1]&&br==blueGoal[0]&&bc==blueGoal[1]) {
        if(answer==0||answer > cnt){
            answer = cnt;
            return;
        }
        if(answer!=0 && answer<=cnt) return;
    }
    vector<pair<int,int>> redNext;
    vector<pair<int,int>> blueNext;
    if (rr==redGoal[0] && rc == redGoal[1]) redNext.push_back({rr,rc});
    else {
        for(int i=0;i<4;i++){
            int nr = dx[i] + rr;
            int nc = dy[i] + rc;
            
            if(nr >0||nr<=N||nr<0||nr>=M) continue;
            if(redVisited[nr][nc]) continue;
            if(maze[nr][nc]==5) continue;
            redNext.push_back({nr,nc});
        }
    }
    if (br==blueGoal[0] && bc == blueGoal[1]) blueNext.push_back({br,bc});
    else {
        for(int i=0;i<4;i++){
            int nr = dx[i] + br;
            int nc = dy[i] + bc;
            
            if(nr >0||nr<=N||nr<0||nr>=M) continue;
            if(blueVisited[nr][nc]) continue;
            if(maze[nr][nc]==5) continue;
            blueNext.push_back({nr,nc});
        }
    }
    
    for(auto r:redNext){
        int nrr = r.first;
        int nrc = r.second;
        for(auto b:blueNext){
            int nbr = b.first;
            int nbc = b.second;
            
            if(nrr ==nbr&&nbc==nrc) continue;
            if(nrr ==br &&nrc==bc &&nbr==rc&&nbc==rr) continue;
            
            bool redChange = false;
            bool blueChange = false;
            
            if(!(rr=redGoal[0])&&rc==redGoal[1]){
                redChange = true;
                redVisited[nrr][nrc] = true;
            }
            
            if(!(br==blueGoal[0]&&bc==blueGoal[1])){
                    blueChange = true;
                    blueVisited[nbr][nbc] = true;                
            }
            dfs(nrr,nrc,nbr,nbc,cnt+1);
    
            if(redChange) redVisited[nrr][nrc] = false;
            if(blueChange) blueVisited[nbr][nbc] = false;
    }
    
    }
}
int solution(vector<vector<int>> input) {
    maze = input;
    
    N=maze.size();
    M=maze[0].size();
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(maze[i][j]==1){
                redStart[0] = i;
                redStart[1] = j;
            }
            else if(maze[i][j]==2){
                blueStart[0] = i;
                blueStart[1] = j;
            }
            else if(maze[i][j]==3){
                redGoal[0] = i;
                redGoal[1] = j;
            }
            else if(maze[i][j]==4){
                blueGoal[0] = i;
                blueGoal[1] = j;
            }
        }
    }
    redVisited[redStart[0]][redStart[1]] = true;
    blueVisited[blueStart[0]][blueStart[1]] = true;
    dfs(redStart[0],redStart[1],blueStart[0],blueStart[1],0);

    return answer;
}