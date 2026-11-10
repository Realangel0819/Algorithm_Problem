#include <bits/stdc++.h>
using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    vector<tuple<int, int, string>> words;
    int n = message.size();
    for(int i=0;i<n;){
        if(i<n&&message[i]==' '){
            i++;
            continue;
        }

        int start = i;
        while(message[i]!=' '){
            i++;
        }
        int end = i-1;

        string word = message.substr(start,end-start+1);
        words.push_back({start,end,word});
    }
    set<string>normalwords;
    vector <int>reveal(words.size(),-1);
    
    int r=0;
    
    for(int i=0;i<words.size();i++){
        int wordstart = get<0>(words[i]);
        int wordend = get<1>(words[i]);
        string word = get<2>(words[i]);
        
        while(r<spoiler_ranges.size()&&spoiler_ranges[r][1]<wordstart){
            r++;
        }
        
        if(r<spoiler_ranges.size()&&spoiler_ranges[r][0]<=wordend){
            reveal[i] = r;
        }
        else{
            normalwords.insert(word);
        }
    }
    vector<vector<string>> revealwords(spoiler_ranges.size());
    
    for(int i=0;i<words.size();i++){
        if(reveal[i]!=-1){
            string word = get<2>(words[i]);
            revealwords[reveal[i]].push_back(word);
        }
        
    }
    set<string>used;
    int answer = 0;
    
    for(int i=0;i<spoiler_ranges.size();i++){
        for(auto word : revealwords[i]){
            if(normalwords.count(word)){
                continue;
            }
            if (used.count(word)){
                continue;
            }
            
            answer++;
            used.insert(word);
            
        }
    }    
    return answer;
}