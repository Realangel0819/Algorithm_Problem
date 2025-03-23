#include <bits/stdc++.h>
using namespace std;

int stu[2][6];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	while (n--) {
		int s, y;
		cin >> s >> y;
		stu[s][y - 1]++;
	}
	
	int ans = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			ans += stu[i][j] / k; // 나눈 몫 = 방의 개수
			
			if (stu[i][j] % k != 0) {
				ans++; // 나머지 학생들이 있을 경우 방의 개수 +1
			}
		}
	}
	
	cout << ans;
	
	return 0;
}