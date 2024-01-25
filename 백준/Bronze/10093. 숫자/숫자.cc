#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int a, b, cnt=0;
    cin >>a>>b;
    if (a>b)
        swap(a,b);
    if(a==b){
        cout << 0;
        return 0;
    }
    cnt = b-a-1;
    cout << cnt <<endl;
    for(long long int i=a+1;i<b;i++){
        cout << i << " ";
    }

}