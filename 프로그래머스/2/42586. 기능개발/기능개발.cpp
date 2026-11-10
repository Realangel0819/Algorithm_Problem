#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    int front = 0;
    while(front<n){
        for(int i = front ;i<n;i++){
            progresses[i]+=speeds[i];
        }
        
        int count = 0 ;
        while(front<n&&progresses[front]>=100){
            count ++;
            front ++;
        }
        if(count > 0){  
            answer.push_back(count);
        }
        
        
    }
    return answer;
}