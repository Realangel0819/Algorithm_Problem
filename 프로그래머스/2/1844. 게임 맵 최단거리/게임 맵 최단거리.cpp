#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int,int>> q;

    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (!maps[nx][ny]) continue; // 0이면 벽

            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});
        }
    }

    if (visited[n-1][m-1] == 0) return -1;
    return visited[n-1][m-1];
}