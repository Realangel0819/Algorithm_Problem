#include <string>
#include <vector>

using namespace std;
int answer = 0;


void dfs(int now, int n, vector<int>&numbers,int target, int result){
    if(now == n){
        if (result == target) answer ++;
        return;
    }
    dfs(now+1,n,numbers,target,result+numbers[now]);
    dfs(now+1,n,numbers,target,result-numbers[now]);

}
int solution(vector<int> numbers, int target) {
    
    dfs(0,numbers.size(),numbers,target,0);
    
    return answer;
}