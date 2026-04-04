#include <bits/stdc++.h>
using namespace std;
stack<char> st;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  char n, prev = 0;
  int cnt = 0, ans = 0;

  while (cin >> n) {
    if (n == '(') {
      st.push(n);
      cnt++;
    } else { // n == ')'
      st.pop();
      cnt--;

      if (prev == '(') {
        // 레이저
        ans += cnt;
      } else {
        // 막대 끝
        ans += 1;
      }
    }
    prev = n;
  }

  cout << ans;
}