#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool q = true;
    vector<int> v;

    for (char k : s) {
        if (k == '-') {
            q = false;
            continue;
        }

        if (k == '+') {
            continue;
        }

        v.push_back(k - '0');
    }

    int num = 1;

    for (int i = v.size() - 1; i >= 0; i--) {
        answer += num * v[i];
        num *= 10;
    }

    if (q == false) {
        answer *= -1;
    }

    return answer;
}