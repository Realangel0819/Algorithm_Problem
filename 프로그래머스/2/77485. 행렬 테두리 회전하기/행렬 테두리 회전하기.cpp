#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>>board(rows+1,vector<int>(columns+1));
    
    int k = 1;
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=columns;j++){
            board[i][j] = k++;
        }
    }
    
    for(auto q: queries){
        int x1 = q[0]; int y1 = q[1];
        int x2 = q[2]; int y2 = q[3];
        int prev = board[x1][y1];   // 들고 가는 값
        int mn = prev;

        for (int j = y1+1; j <= y2; j++) {      // 위 행 →
            int cur = board[x1][j];
            board[x1][j] = prev;
            mn = min(mn, prev);
            prev = cur;
        }
        for (int i = x1+1; i <= x2; i++) {      // 오른쪽 열 ↓
            int cur = board[i][y2];
            board[i][y2] = prev;
            mn = min(mn, prev);
            prev = cur;
        }
        for (int j = y2-1; j >= y1; j--) {      // 아래 행 ←
            int cur = board[x2][j];
            board[x2][j] = prev;
            mn = min(mn, prev);
            prev = cur;
        }
        for (int i = x2-1; i >= x1; i--) {      // 왼쪽 열 ↑
            int cur = board[i][y1];
            board[i][y1] = prev;
            mn = min(mn, prev);
            prev = cur;
        }
        answer.push_back(mn);
    }
    
    return answer;
}