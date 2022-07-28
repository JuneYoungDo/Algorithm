//
// Created by June Young Do on 2022/07/28.
//
#include<iostream>
#include<queue>
#include<algorithm>

#define endl '\n'
using namespace std;

int N, M;
int sum;
int parent[1002];
priority_queue<pair<int, pair<int, int>>> pq;

int findParent(int x) {
    if (x == parent[x]) { return x; }
    else { return parent[x] = findParent(parent[x]); }
}

void Union(int a, int b) {
    int pa = findParent(a);
    int pb = findParent(b);
    if (pa < pb) {
        parent[pb] = pa;
    } else {
        parent[pa] = pb;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c, {a, b}});
    }

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int v1 = pq.top().second.first;
        int v2 = pq.top().second.second;
        pq.pop();
        if (findParent(v1) != findParent(v2)) {
            Union(v1, v2);
            sum += cost;
        }
    }

    cout << sum << endl;

    return 0;
}

