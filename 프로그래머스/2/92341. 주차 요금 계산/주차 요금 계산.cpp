#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int,int> inTime;
    map<int,int> total;
    
    for(string rec : records){
        stringstream ss(rec);
        string time,number,status;
        
        ss >> time >> number >>status;
        
        int car = stoi(number);
        int t = stoi(time.substr(0,2))*60+stoi(time.substr(3,2));
        
        if(status =="IN") inTime[car] = t;
        else {
            total[car] += t - inTime[car];
            inTime.erase(car);
        }
    }
    
    for (auto&p :inTime) total[p.first] += (23*60+59) - p.second;
    
    for(auto&p:total){
        int m = p.second;
        int fee = fees[1];
        if (m>fees[0]){
            int extra = m - fees[0];
            fee += (extra+fees[2]-1)/fees[2]*fees[3];
        }
        answer.push_back(fee);
    }
    
    return answer;
}