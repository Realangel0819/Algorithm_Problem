#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    int d,e,f;
    cin >> a >> b >> c;
    d = min({a,b,c});
    f = max ({a,b,c});
    e = a+b+c-d-f;

    cout << d << " " << e << " " << f;
}