#include<bits/stdc++.h>
using namespace std;

int stu[100001];
bool visited[100001];
bool finished[100001];
int cnt;

void dfs(int cur){
    visited[cur] = true;
    int next = stu[cur];

    if(!visited[next]){
        dfs(next);
    }
    else if(!finished[next]){
        for(int i = next; i != cur; i = stu[i]){
            cnt++;
        }
        cnt++;
    }

    finished[cur] = true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++){
            cin >> stu[i];
            visited[i] = false;
            finished[i] = false;
        }

        cnt = 0;

        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                dfs(i);
            }
        }

        cout << n - cnt << "\n";
    }
}