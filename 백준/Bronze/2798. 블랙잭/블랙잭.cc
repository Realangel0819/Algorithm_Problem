#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
    int n,m;
    int max=0;
    cin >> n >> m;
    int *a = (int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int sum = a[i]+a[j]+a[k];
                if(sum>max && sum<=m) 
                    max=sum;
            }
        }
    }
    cout << max;
    return 0;

}