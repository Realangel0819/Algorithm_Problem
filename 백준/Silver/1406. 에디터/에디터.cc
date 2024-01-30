#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    list<char> li;
    string a;
    int temp = 0;
    cin >> a;

    for(auto s : a) li.push_back(s);
    auto cursor = li.end();

    int n;
    cin >> n;
    while(n--){
        char ch;
        cin >> ch;

        if(ch == 'L' && cursor != li.begin()) {
            cursor--;
        } else if(ch == 'D' && cursor != li.end()) {
            cursor++;
        } else if(ch == 'B' && cursor != li.begin()){
            if (cursor != li.begin()) {
                cursor = li.erase(--cursor);
            }
        } else if(ch == 'P') {
            char insertChar;
            cin >> insertChar;
            li.insert(cursor, insertChar);
        }
    }
    for(auto s: li) cout << s;
}
