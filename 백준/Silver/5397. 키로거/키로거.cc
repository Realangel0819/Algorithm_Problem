#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while (n--) {
        list<char> L;
        auto cur = L.begin();
        string s;
        cin >> s;

        for (auto c : s) {
            if (c == '<') {
                if (cur != L.begin()) cur--;
            } 
            else if (c == '>') {
                if (cur != L.end()) cur++;
            } 
            else if (c == '-') {
                if (cur != L.begin()) {
                    cur = L.erase(prev(cur));
                }
            } 
            else {
                L.insert(cur, c);
            }
        }

        // 문자열을 한 번에 출력
        ostringstream oss;
        for (auto c : L) {
            oss << c;
        }
        cout << oss.str() << "\n";
    }
}
