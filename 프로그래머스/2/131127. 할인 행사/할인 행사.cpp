#include<bits/stdc++.h>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int n = discount.size();
    map<string,int> res;
    map<string,int> dis;
    for(int i =0;i<want.size();i++){
        res[want[i]] = number[i];
    }
    for(int i=0;i+10<=n;i++){
        dis.clear();
        for(int j=i;j<i+10;j++){
            dis[discount[j]]++;
            
        }
        bool b= true;
        for(const auto& pair : res){
            if(dis[pair.first]<pair.second) b=false;
        }
        if(b) answer+=1;
    }
    
    
    return answer;
}