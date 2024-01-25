#include<bits/stdc++.h>
using namespace std;
int arr1[9];
int main(){
    int sum = 0;
    int q=0,w=0;
    for(int i=0;i<9;i++){
        cin >>arr1[i];
        sum += arr1[i];
    }

    sort(arr1,arr1+9);

    for(int i=0;i<8;i++){
        for(int j=i+1;j<9;j++){
            int k= sum- arr1[i] -arr1[j];
            if(k==100){
                q=arr1[i];
                w=arr1[j];
                for(int i=0;i<9;i++){
                    if(arr1[i]!=q && arr1[i]!=w){
                    cout << arr1[i] <<endl;
                    }
                }
                return 0;
            }
        }
    }

    


}