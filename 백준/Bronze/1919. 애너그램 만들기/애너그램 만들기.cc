#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    string b;
    int str[26] = {0,};
    int cnt = 0;
    cin >> a >> b;

    for(auto s : a) str[s-'a']++;
    for(auto s : b) str[s-'a']--;

    for(int i=0;i<26;i++){
        if(str[i]>0){
            while(str[i]){
                cnt++;
                str[i]--;
            }
        }
        else{
            
            while(str[i]){
                cnt++;
                str[i]++;
            }
        }
    }    

    cout << cnt ;
    return 0;
}