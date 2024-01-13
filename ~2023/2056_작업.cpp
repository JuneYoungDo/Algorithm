//
// Created by June Young Do on 2022/07/13.
//
#include<iostream>
#include<queue>
#include<vector>

using namespace std;
#define endl '\n'

int N;
int in_degree[10002];
int cost[10002];
vector<int> v[10002];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        cost[i] = a;
        for (int j = 0; j < b; j++) {
            int c;
            cin >> c;
            v[i].push_back(c);
            in_degree[c]++;
        }
    }

    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= N; i++) {
        if (!in_degree[i]) {
            pq.push({-cost[i], i});
        }
    }

    int weight;
    while (!pq.empty()) {
        int now = pq.top().second;
        weight = -pq.top().first;
        pq.pop();

        for (int i = 0; i < v[now].size(); i++) {
            in_degree[v[now][i]]--;
            if (in_degree[v[now][i]] == 0) {
                pq.push({-(weight + cost[v[now][i]]), v[now][i]});
            }
        }
    }
    cout << weight << endl;

    return 0;
}
