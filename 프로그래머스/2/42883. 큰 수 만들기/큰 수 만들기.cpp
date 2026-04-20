#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> s;

    for (char c : number) {
        while (!s.empty() && k > 0 && s.top() < c) {
            s.pop();
            k--;
        }
        s.push(c);
    }

    while (k--) s.pop();


    while (!s.empty()) {
        answer += s.top();
        s.pop();
    }

    reverse(answer.begin(), answer.end());
    return answer;
}