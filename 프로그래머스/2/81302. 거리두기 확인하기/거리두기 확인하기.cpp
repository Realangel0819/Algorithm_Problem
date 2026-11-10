#include<bits/stdc++.h>
using namespace std;

bool inRange(int r, int c) { return r >= 0 && r < 5 && c >= 0 && c < 5; }

bool check(const vector<string>& room) {
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (room[i][j] != 'P') continue;

            // 거리 1 + 직선 거리 2
            for (int d = 0; d < 4; d++) {
                int ni = i + dr[d], nj = j + dc[d];
                if (!inRange(ni, nj)) continue;
                if (room[ni][nj] == 'P') return false;
                if (room[ni][nj] == 'O') {
                    int mi = i + 2 * dr[d], mj = j + 2 * dc[d];
                    if (inRange(mi, mj) && room[mi][mj] == 'P') return false;
                }
            }
            // 대각선
            for (int di = -1; di <= 1; di += 2) {
                for (int dj = -1; dj <= 1; dj += 2) {
                    int ni = i + di, nj = j + dj;
                    if (!inRange(ni, nj) || room[ni][nj] != 'P') continue;
                    if (room[i][nj] != 'X' || room[ni][j] != 'X') return false;
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (const auto& room : places)
        answer.push_back(check(room) ? 1 : 0);
    return answer;
}