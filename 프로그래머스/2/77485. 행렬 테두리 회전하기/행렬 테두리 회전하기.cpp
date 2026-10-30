#include<bits/stdc++.h>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
   
    vector<vector<int>> board(rows+1, vector<int>(columns+1));
    int k = 1;
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=columns;j++){
            board[i][j] = k++;
        }
    }
    for (auto& q : queries) {
    int x1 = q[0], y1 = q[1], x2 = q[2], y2 = q[3];
    int prev = board[x1][y1];   // 들고 다니는 값
    int mn = prev;

    auto step = [&](int r, int c) {
        int cur = board[r][c];  // 덮어쓰기 전 값을 저장
        board[r][c] = prev;     // 들고 온 값을 넣고
        mn = min(mn, prev);
        prev = cur;             // 저장해 둔 값을 다음 칸으로 들고 감
    };

    for (int j = y1 + 1; j <= y2; j++) step(x1, j);   // 위 행 →
    for (int i = x1 + 1; i <= x2; i++) step(i, y2);   // 오른쪽 열 ↓
    for (int j = y2 - 1; j >= y1; j--) step(x2, j);   // 아래 행 ←
    for (int i = x2 - 1; i >= x1; i--) step(i, y1);   // 왼쪽 열 ↑

    answer.push_back(mn);
}
    
    return answer;
}