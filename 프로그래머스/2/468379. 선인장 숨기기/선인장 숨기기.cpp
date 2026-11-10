#include <bits/stdc++.h>

using namespace std;

bool check(int mid, int m, int n, int h, int w,
           const vector<vector<int>>& drops, vector<int>& out_pos) {

    int cols = n + 1;

    // 누적합 배열
    vector<int> psum((m + 1) * cols, 0);

    // 처음 mid개의 물방울 위치 표시
    for (int i = 0; i < mid; ++i) {
        int r = drops[i][0] + 1;
        int c = drops[i][1] + 1;

        psum[r * cols + c] = 1;
    }

    // 2차원 누적합
    for (int r = 1; r <= m; ++r) {
        for (int c = 1; c <= n; ++c) {

            psum[r * cols + c] +=
                psum[(r - 1) * cols + c]
                + psum[r * cols + (c - 1)]
                - psum[(r - 1) * cols + (c - 1)];
        }
    }

    // h x w 크기의 영역을 하나씩 확인
    for (int r = 1; r <= m - h + 1; ++r) {
        for (int c = 1; c <= n - w + 1; ++c) {

            int r2 = r + h - 1;
            int c2 = c + w - 1;

            // 해당 영역 안에 물방울이 몇 개 있는지 계산
            int drops_in_area =
                psum[r2 * cols + c2]
                - psum[(r - 1) * cols + c2]
                - psum[r2 * cols + (c - 1)]
                + psum[(r - 1) * cols + (c - 1)];

            // 물방울이 하나도 없다면 성공
            if (drops_in_area == 0) {
                out_pos[0] = r - 1;
                out_pos[1] = c - 1;

                return true;
            }
        }
    }

    return false;
}

vector<int> solution(int m, int n, int h, int w,
                     vector<vector<int>> drops) {

    vector<int> answer = {0, 0};

    int left = 0;
    int right = drops.size();

    vector<int> temp_pos = {0, 0};

    // 이분 탐색
    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (check(mid, m, n, h, w, drops, temp_pos)) {

            // mid개의 물방울까지 놓아도
            // 빈 h x w 영역이 존재한다.
            answer = temp_pos;

            // 더 많은 물방울도 가능한지 확인
            left = mid + 1;
        }
        else {

            // mid개에서는 불가능하므로
            // 물방울 개수를 줄인다.
            right = mid - 1;
        }
    }

    return answer;
}