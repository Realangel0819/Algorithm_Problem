#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    stack<int>s;
    int temp;
    int q=1;
    string ans;
    cin >> n;
    for (int i = 0; i < n ; i++ ){
        cin >> temp;
        while(q<=temp){
            s.push(q++);
            ans+= "+\n";
        }
        if(s.top()==temp){
            s.pop();
            ans+= "-\n";
        }
        else {
            cout << "NO";
            return 0;
        }
    }

    cout << ans;
    return 0;
}