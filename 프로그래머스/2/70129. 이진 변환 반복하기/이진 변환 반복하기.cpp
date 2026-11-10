#include<bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int count = 0;
    int zero = 0;
    while(s.length()>1){
        count += 1;
        int len = s.length();
        int cnt =0;
        for(auto q : s){
            if (q =='0') cnt ++;
        }
        zero += cnt;
        len = len -cnt;
        s ="";
        while(len>1){
            int tmp = len %2;
            len = len/2;
            if(tmp ==1) s+="1";
            else s+="0";
        }
        s+=1;

        reverse(s.begin(),s.end());
    }
    answer.push_back(count);
    answer.push_back(zero);

    return answer;
}