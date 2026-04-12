#include<bits/stdc++.h>
using namespace std;

int f,s,g,u,d;
int ans;
int dist[1000002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> f >> s >> g >> u >> d;
    fill(dist+1, dist+f+1, -1);

    queue<int>q;

    dist[s] =0;

    q.push(s);

    while(!q.empty()){
        int cur = q.front();q.pop();

        int nxt1 = cur + u;
        int nxt2 = cur - d;

        if(nxt1 <= f && nxt1 > 0 && dist[nxt1] == -1){
            dist[nxt1] = dist[cur] + 1;
            q.push(nxt1);
        }

        if(nxt2 <= f && nxt2 > 0 && dist[nxt2] == -1){
            dist[nxt2] = dist[cur] + 1;
            q.push(nxt2);   
        }   

    }

    if (dist[g] == -1 ) cout << "use the stairs";
    else cout << dist[g];
}