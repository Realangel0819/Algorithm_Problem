#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 1;
    int h = n/w;
    if(n%w!=0) h++;
    int top = n%w;
    int row = (num-1)/w;
    int pos = (num-1)%w;
    
    int col = pos;
    if(row%2==1){
        col = w-1-pos;
    }
    answer += h-1-row;
    
    if(top!=0 && row!=h-1){
        int toprow = h-1;
        bool exist;
        
        if(toprow%2==1){
            exist = col>=w-top;
        }
        else{
            exist = col<top;
        }
        if(!exist) answer --;
    }
    
    return answer;
}