#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    stack<char> st;
    int ans = 0;
    int mult = 1;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (c == '(') {
            mult *= 2;
            st.push(c);
        }
        else if (c == '[') {
            mult *= 3;
            st.push(c);
        }
        else if (c == ')') {
            if (st.empty() || st.top() != '(') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '(') { // 바로 닫히는 경우
                ans += mult;
            }
            st.pop();
            mult /= 2;
        }
        else if (c == ']') {
            if (st.empty() || st.top() != '[') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '[') {
                ans += mult;
            }
            st.pop();
            mult /= 3;
        }
    }

    if (!st.empty()) cout << 0;
    else cout << ans;
}