//
// Created by June Young Do on 2022/07/25.
//
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
#define endl '\n'

int n;
int ans;
int endVertex;
vector<pair<int, int>> v[10001];
bool visit[10001];

void dfs(int vertex, int maxL) {
    if (visit[vertex]) { return; }
    visit[vertex] = true;
    if (ans < maxL) {
        ans = maxL;
        endVertex = vertex;
    }
    for (int i = 0; i < v[vertex].size(); i++) {
        dfs(v[vertex][i].first, maxL + v[vertex][i].second);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    dfs(1, 0);
    ans = 0;
    memset(visit, false, sizeof(visit));
    dfs(endVertex, 0);

    cout << ans << endl;

    return 0;
}