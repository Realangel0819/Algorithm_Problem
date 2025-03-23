#include<bits/stdc++.h>
using namespace std;

int n, cur;
const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;
int size;

void insert(int addr, int num){
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused ++;
}

void erase(int addr){
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != -1 ) pre[nxt[addr]] = pre[addr]; 
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur];
    cur = nxt[cur];
  }
  cout << "\n\n";
}


int main(void){
    ios::sync_with_stdio(0);
    //cin.tie(0);
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    string s;
    char a;
    cin >> s;
    cur = 0;
    for (auto q:s){
        insert(cur,q);
        cur++;
    }
    cin >> n;
    while(n--){
        cin >> a;
        if (a == 'P'){
            char add;
            cin >> add;
            insert(cur,add);
            cur = nxt[cur];
        }
        else if(a=='L'){
            if(pre[cur]!=-1){
                cur=pre[cur];
            }
        }
        else if(a=='D'){
            if (nxt[cur]!=-1){
                cur=nxt[cur];
            }
        }
        else{
            if(cur!=0){
                erase(cur);
                cur = pre[cur];
            }
        }
    }
    traverse();
    
    cin.get();
    cin.get();

}

