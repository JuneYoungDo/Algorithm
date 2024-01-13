//
// Created by June Young Do on 2022/07/26.
//
#include<iostream>
#include<queue>

using namespace std;
#define endl '\n'

int sum;
int parent[10002];

int findParent(int a) {
    if (parent[a] == a) { return a; }
    else { return parent[a] = findParent(parent[a]); }
}

void Union(int a, int b) {
    int pa = findParent(a);
    int pb = findParent(b);
    if (pa < pb) { parent[pb] = pa; }
    else { parent[pa] = pb; }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;

    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    priority_queue<pair<int, pair<int, int>>> pq;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c, {a, b}});
    }

    while (!pq.empty()) {
        int cost = pq.top().first;
        int v1 = pq.top().second.first;
        int v2 = pq.top().second.second;
        pq.pop();

        if (findParent(v1) != findParent(v2)) {
            Union(v1, v2);
            sum += cost;
        }
    }

    cout << -sum << endl;

    return 0;
}
