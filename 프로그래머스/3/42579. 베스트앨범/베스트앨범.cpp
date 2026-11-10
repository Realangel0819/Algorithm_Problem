#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> genreCount;
    map<string,vector<pair<int,int>>> countNumber;

    for (int i = 0; i < (int)genres.size(); i++) {
        genreCount[genres[i]] += plays[i];
        countNumber[genres[i]].push_back({plays[i], i});
    }

    for (auto& [g, v] : countNumber)
        sort(v.begin(), v.end(), cmp);

    vector<pair<int,string>> order;
    for (const auto& [g, total] : genreCount)
        order.push_back({total, g});
    sort(order.rbegin(), order.rend());

    for (const auto& o : order) {
        const auto& v = countNumber[o.second];
        for (int i = 0; i < (int)v.size() && i < 2; i++)
            answer.push_back(v[i].second);
    }
    return answer;
}