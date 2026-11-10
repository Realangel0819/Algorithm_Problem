#include<bits/stdc++.h>


using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int n = park.size();
    int m = park[0].length();
    vector<vector<int>> board(n,vector<int>(m,0));
    int x,y;
    for(int i = 0;i< n;i++){
        int cnt =0;
        for(char a : park[i]){
            if(a == 'S') {
                board[i][cnt] = 1;
                x= i;
                y = cnt;
            }
            if(a=='X') board[i][cnt] =-1;
            cnt ++;
        }
    }
    for(auto r : routes){
        stringstream ss(r);
        char t;
        int c;
        ss >> t >> c;

        int nx = 0, ny = 0;
        bool b = true;

        if (t == 'E') ny = c;
        else if (t == 'S') nx = c;
        else if (t == 'W') ny = -c;
        else if (t == 'N') nx = -c;
        int dx = x+nx;
        int dy = y+ny;
        if(dx<0||dy<0||dx>=n||dy>=m) continue;
        
        
        if(t == 'E'){
            for(int r=0;r<=c;r++){
                if(board[x][y+r]==-1) b =false;
            }
        }
        else if(t == 'S'){
            for(int r=0;r<=c;r++){
                if(board[x+r][y]==-1) b =false;
            }
        }
        else if(t == 'W'){
            for(int r=0;r<=c;r++){
                if(board[x][y-r]==-1) b =false;
            }
        }
        else if(t == 'N'){
            for(int r=0;r<=c;r++){
                if(board[x-r][y]==-1) b =false;
            }
        }
        
        if(!b) continue;
        x=dx; y=dy;
    }
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}