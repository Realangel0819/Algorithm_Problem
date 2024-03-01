#include<bits/stdc++.h>
using namespace std;

void parse(string&tmp, deque<int>&d){
    int cur = 0;
    for(int i = 1; i+1<tmp.size();i++){
        if(tmp[i] == ','){
            d.push_back(cur);
            cur = 0;
        }
        else {
            cur = 10*cur +(tmp[i]-'0');
        }
    }
    if(cur!=0){
            d.push_back(cur);
        }
}
void print(deque<int>&d){
std::cout << "[";
    for(int i=0;i<d.size();i++){
    std::cout << d[i];
        if(i+1 != d.size())
        std::cout << ',';
  }
std::cout << "]\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    string p, s;
    cin >> t;

    while(t--){
        cin >> p;
        cin >> n;
        cin >> s;
        deque<int>dq;
        parse(s, dq);
        bool r = false;
        bool wrong = false;
        for(auto c:p){
            if(c =='R')
                r = (!r);
            else{
                if(dq.empty()){
                    wrong = true;
                    break;
                }
                if(!r) dq.pop_front();
                else dq.pop_back();
            }   
        }
        if(wrong) std::cout << "error\n";
        else {
            if(r) reverse(dq.begin(),dq.end());
            print(dq);
        }
    }
}
