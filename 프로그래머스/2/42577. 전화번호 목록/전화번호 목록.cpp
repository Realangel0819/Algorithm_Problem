#include<bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i + 1 < (int)phone_book.size(); i++) {
        const string& a = phone_book[i];
        const string& b = phone_book[i + 1];
        if (b.substr(0, a.size()) == a)
            return false;
    }
    return true;
}