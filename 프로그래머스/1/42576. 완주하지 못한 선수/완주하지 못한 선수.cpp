#include<bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> run;
    for(auto a:participant){
        run[a]+=1;
    }
    for(auto a : completion){
        run[a] -=1;
    }
    
    for(auto &[name,count] : run){
        if (count >0) answer+=name;
        
    }
    return answer;
}