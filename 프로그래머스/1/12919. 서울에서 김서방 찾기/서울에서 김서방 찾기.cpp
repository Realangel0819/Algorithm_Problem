#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int i = 0;

    for (string k : seoul) {
        if (k == "Kim") {
            break;
        }
        i++;
    }

    answer = "김서방은 " + to_string(i) + "에 있다";
    return answer;
}