#include <bits/stdc++.h>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    set<tuple<int,int,int,int>> path;
    int x = 0, y = 0;
    for(auto d : dirs){
        int dx = 0, dy=0;
        if(d =='U'){
            dy=1;
        }
        else if(d =='L'){
            dx = -1;
        }
        else if(d =='R'){
            dx =1;
        }
        else{
            dy = -1;
        }
        int nx = x + dx, ny = y + dy;
        if (nx < -5 || nx > 5 || ny < -5 || ny > 5) continue;
        
        path.insert({x, y, nx, ny});    // 양방향 저장
        path.insert({nx, ny, x, y});
        x = nx; y = ny;
    }
    answer = path.size()/2;
    return answer;
}