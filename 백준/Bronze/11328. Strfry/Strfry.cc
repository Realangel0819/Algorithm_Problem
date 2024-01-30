#include<bits/stdc++.h>
using namespace std;
bool t[1001];
int main(){
    int n;
    cin >> n;
    string a,b;

    for(int j=0;j<n;j++){
        int cnt[26]={0,};
        int temp = 0;
        cin >> a >> b;
        for(auto s : a) cnt[s-'a']++;
        for(auto s : b) cnt[s-'a']--;

        for(int i = 0; i<26; i++ ){
            if(cnt[i]!=0){
                temp = 1;
                break;
            }
        }
        if(temp == 0){
            t[j] = true;
        }
    }

     for(int j=0;j<n;j++){
        if(t[j]==false)
            cout << "Impossible"<<endl;
        else
            cout << "Possible"<<endl;
     }
        
}