//
// Created by June Young Do on 2022/07/22.
//

#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
#define endl '\n'

int N, Q;
vector<pair<int, int>> v[5002];
int visited[5002];
int vertex;
int cost;

int bfs(int start) {
    int ret = 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++) {
            int nv = v[now][i].first;
            int nc = v[now][i].second;
            if (visited[nv]) continue;
            if (nc >= cost) {
                ret++;
                visited[nv] = true;
                q.push(nv);
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for (int i = 0; i < Q; i++) {
        memset(visited, false, sizeof(visited));
        cin >> cost >> vertex;
        cout << bfs(vertex) << endl;
    }

    return 0;
}