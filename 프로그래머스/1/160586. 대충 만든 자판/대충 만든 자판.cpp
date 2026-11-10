#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map <char,int> key;
    for(int i=0;i<keymap.size();i++){
        int s = 1;
        for(char a:keymap[i]){
            if (key.find(a) != key.end()){
                int tmp = min(key[a],s);
                key[a] = tmp;
            }
            else{
                key[a] = s;
            }
            s++;
        }
    }
    for(int i=0;i<targets.size();i++){
        int sum = 0;
        bool b = true;
        for(char a:targets[i]){
            if(key.find(a) == key.end()){
                answer.push_back(-1);
                b = false;
                break;
            }
            sum += key[a];
        }
        if(b)answer.push_back(sum);
    }
    
    return answer;
}