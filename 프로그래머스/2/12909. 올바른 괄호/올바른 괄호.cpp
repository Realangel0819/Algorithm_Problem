#include<bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = false;
    stack<int> stk;
    for(auto f : s){
        stk.push(f);
    }
    int cnt = 0;
    for (char c : s) {
        if (c == '(') {
            cnt++;
        }
        else {
            cnt--;
        }

        if (cnt < 0) {
            return false;
        }
    }
    
    if(cnt ==0 ) answer = true;
   
    return answer;
}