#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto s : scoville){
        pq.push(s);
    }
    while(pq.top()<K){
        if(pq.size()<2) return -1;
        int a = pq.top();pq.pop();
        int b = pq.top();pq.pop();
        a = a+ (b*2);
        pq.push(a);
        answer ++;
    }
    return answer;
}