#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();

    vector<vector<int>> ans = triangle;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                ans[i][j] += ans[i - 1][j];
            }
            else if (j == i) {
                ans[i][j] += ans[i - 1][j - 1];
            }
            else {
                ans[i][j] += max(
                    ans[i - 1][j - 1],
                    ans[i - 1][j]
                );
            }
        }
    }

    return *max_element(ans[n - 1].begin(), ans[n - 1].end());
}
