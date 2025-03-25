#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    list<int> l;
    vector<int> ans;

    // 1부터 n까지 리스트에 추가
    for (int i = 1; i <= n; i++) {
        l.push_back(i);
    }

    auto cur = l.begin();  // 리스트의 첫 번째 요소 가리킴

    while (!l.empty()) {
        // k-1번 이동 (k번째 요소 찾기 위해)
        for (int i = 1; i < k; i++) {
            cur++;
            if (cur == l.end()) cur = l.begin();  // 리스트 끝이면 처음으로 이동
        }

        // k번째 요소 삭제
        ans.push_back(*cur);  // 삭제할 요소 저장
        cur = l.erase(cur);   // 삭제 후 커서 이동

        // 리스트의 마지막 원소를 삭제한 경우, 커서를 처음으로 이동
        if (cur == l.end()) cur = l.begin();
    }

    // 결과 출력 (형식 맞춤)
    cout << '<';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) cout << ", ";
    }
    cout << '>' << '\n';

    return 0;
}
