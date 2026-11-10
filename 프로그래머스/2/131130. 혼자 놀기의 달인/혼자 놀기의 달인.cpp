#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    int n = cards.size();
    vector<int>visited(n,0);
    vector<int>groupSizes;
    
    for(int start = 0 ; start < n; start++){
        if(visited[start]) continue;
        int size = 0;
        int cur = start;
        while(!visited[cur]){
            visited[cur] = 1;
            size++;
            cur = cards[cur] -1;
        }
        groupSizes.push_back(size);
    }
    
    sort(groupSizes.rbegin(),groupSizes.rend());
    
    if(groupSizes.size()<2) answer = 0;
    else answer = groupSizes[0] * groupSizes[1];
    
    return answer;
}