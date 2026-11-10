#include <string>
#include <vector>

using namespace std;
int gcd (int a, int b){
    while(b){
        int t = a%b;
        a=b;
        b=t;
    }
    return a;
}

int lcm(int a, int b){
    return a/gcd(a,b)*b;
}
int solution(vector<vector<int>> signals) {
    int answer = 0;
    
    int limit = 1;
    
    for (int i=0;i<signals.size();i++){
        int sum = signals[i][0]+signals[i][1]+signals[i][2];
        limit = lcm(sum,limit);
    }
    bool yellow = true;    
    for (int i=1;i<limit;i++){
        bool yellow = true;    
        for (int j=0;j<signals.size();j++){
            int cycle = signals[j][0]+signals[j][1]+signals[j][2];
            int temp = (i-signals[j][0]) %cycle;
            if(temp>0&&temp<=signals[j][1]) continue;
            yellow = false;
            
        }
        
        if(yellow) return i;
    }
    return -1;
}