//
// Created by June Young Do on 2022/07/28.
//

#include<iostream>
#include<queue>

using namespace std;
#define endl '\n'

int n, m, ans;
int parent[100002];
priority_queue<pair<int, pair<int, int>>> pq;

int findParent(int a) {
    if (parent[a] == a) { return a; }
    else { return parent[a] = findParent(parent[a]); }
}

void Union(int a, int b) {
    int pa = findParent(a);
    int pb = findParent(b);
    if (pa > pb) { parent[pa] = pb; }
    else { parent[pb] = pa; }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c, {a, b}});
    }

    int tmp;
    while (!pq.empty()) {
        int v1 = pq.top().second.first;
        int v2 = pq.top().second.second;
        int cost = -pq.top().first;
        pq.pop();

        if (findParent(v1) != findParent(v2)) {
            Union(v1, v2);
            ans += cost;
            tmp = cost;
        }
    }
    cout << ans - tmp << endl;

    return 0;
}