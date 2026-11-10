#include<bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    string status, userId, nickName;
    vector<pair<string,string>> logs;
    
    map <string, string> chat;
    for (auto r : record){
        stringstream ss(r);
        ss >> status >> userId >>nickName;
        if(status == "Enter"){
            chat[userId] = nickName;
            logs.push_back({status,userId});
        }
        else if(status == "Leave"){
            logs.push_back({status,userId});  
        }
        else{
            chat[userId] = nickName;
        }
      
    }
      
        for(auto a : logs){
            if (a.first == "Enter"){
                string tmp = chat[a.second] +"님이 들어왔습니다.";
                answer.push_back(tmp);
            }
            else if(a.first =="Leave"){
                string tmp = chat[a.second] +"님이 나갔습니다.";
                answer.push_back(tmp);

            }
            
        }
        
    
    return answer;
}